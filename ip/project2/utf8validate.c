#include<stdio.h>
int main(void)
{
	int ch,counter1,counter2,codepoint;
	counter1=0;//counter for ASCII charachters
	counter2=0;//counter for multibyte UTF-8 charachters
	while((ch=getchar())!=EOF)//get charachters as long as they are different to EOF
	{
		if((ch&0x80)==0)//if the first byte of a charachter is 0 it is an ASCII code
		{
			codepoint=ch;//set codepoint as the charachter read
			counter1++;//increase ascii's counter by one
		}
		else //so its a multibyte code
		{
			if((ch&0xE0)==0xC0)//its a 2bytes code
			{
				codepoint=ch&0x1F;//5bits of the first byte
				if((ch=getchar())==EOF)//if second byte is EOF then ERROR
				{
					printf("UNEXPECTED EOF");
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
				counter2++;//increase multibyte's counter by one
				if(codepoint<=0x0080)//if the charachter does not belong to the valid space ERROR
				{
					printf("Oversized UTF-8 code point: U+%04X\n",codepoint);
					return 1;
				}
			}
			else if((ch&0xF0)==0xE0)//its a 3bytes code
			{
				codepoint=ch&0x0F;//4bits of first byte
				if((ch=getchar())==EOF)//get the second byte
				{
					printf("UNEXPECTED EOF\n");//if it is equal to EOF ERROR
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
				if((ch=getchar())==EOF)//get the third byte
				{
					printf("UNEXPECTED EOF\n");//if it is equal to EOF ERROR
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
				counter2++;
				if(codepoint>=0xD800 && codepoint<=0xDFFF)//if codepoint belongs to the forbidden space
				{
					printf("Invalid UTF-8 code point: U+%04X\n",codepoint);
					return 1;
				}
				if(codepoint<0x0800)//if the code bellongs to another space
				{
					printf("Oversized UTF-8 code point: U+%04X\n",codepoint);
					return 1;
				}
			}
			else if((ch&0xF8)==0xF0)//its a 4bytes code
			{
				codepoint=ch&07;
				if((ch=getchar())==EOF)//get the second byte
				{
					printf("UNEXPECTED EOF\n");//if it is equal to EOF ERROR
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
					if((ch=getchar())==EOF)//get the third byte
				{	printf("UNEXPECTED EOF\n");//if it is equal to EOF ERROR
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
					if((ch=getchar())==EOF)//get the last byte
				{
					printf("UNEXPECTED EOF\n");//if it is equal to EOF ERROR
					return 1;
				}
				if((ch&0xC0)!=0x80)//if two first bits of second byte are not equal to 10 then ERROR
				{
					printf("Invalid UTF-8 tail byte: 0x%02X\n",ch);
					return 1;
				}
				codepoint<<=6;
				codepoint+=(ch&0x3F);
				counter2++;
				if(codepoint>0x10FFFF)//if code does not belong to the UTF-8 range
				{
					printf("Invalid UTF-8 code point: U+%04X\n",codepoint);
					return 1;
				}
				if(codepoint<0x010000)//if code belongs to another space
				{
					printf("Oversized UTF-8 code point: U+%04X\n",codepoint);
					return 1;
				}
				}
			else
			{
				printf("Invalid UTF-8 header byte: 0x%02X\n",ch);
				return 1;
			}
		}
	}
	printf("Found %d ASCII and %d multi-byte UTF-8 characters.\n",counter1,counter2);
	return 0;
}
