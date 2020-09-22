#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COMPUTATIONS 10000000
int main()
{
int i,j,sum1,sum2,gcd1,large,small,rem,count,n,x,y,z,currenttime;
count=0;//counter of achilles numbers
currenttime=time(NULL);//seed for srand
srand(currenttime);
for (i=1;i<=COMPUTATIONS;i++)
    {y=rand();//first random number
     z=rand();//second random number
     x=(((y%32768)+1)*((z%32768)+1))+1;//final number
     gcd1=0;//set gcd as 0
     n=x;//set n as x
     sum1=0;//counter for first exponent
     sum2=0;//counter for second exponent
            while(n%2==0)
                 {sum1++;
                  n=n/2;
				 }
            while(n%3==0)
                 {sum2++;
                  n=n/3;
				 }
	        if(sum1==1||sum2==1)//if one of the exponents is equal to 1 the number is not achilles because it is not powerful
	             {continue;//so move on to the next one
	             }  
	        else//in other case calculate the gcd of the exponents
	        	{if(sum1>1&&sum2>1)
	        	{if (sum1>sum2)
	                {large=sum1;
	                 small=sum2;
					}
	                else
	                {large=sum2;
	                	small=sum1;
					}
                    while(small)
	                   {rem=large%small;
	                    large=small;
	                    small=rem;
					  	}
                    gcd1=large;
                   }
                 else if(sum1==0)
                 	gcd1=sum2;
                 else if(sum2==0)
                 	gcd1=sum1;
            }
    j=5;//next prime numbers counter
    while(j*j<=n)
         {sum1=0;//reset first counter as 0
          sum2=0;//reset second counter as 0
              while(n%j==0)//check j as factor
                   {sum1++;
                    n=n/j;
				   }
              while(n%(j+2)==0)//check j+2 as factor
                   {sum2++;
                    n=n/(j+2);
				   }
      j=j+6;//increase j by 6
    if(sum1==1||sum2==1)//if one of the exponents is equal to 1 the number is not achilles because it is not powerful 
       {
	    break;//so move on to the next one
       }
    else//else calculate the next gcd
     if(sum1>1)
       {if (sum1>gcd1)
	        {large=sum1;
	         small=gcd1;
			}
	     else
	        {large=gcd1;
	        small=sum1;
			}
         while(small)
	          {rem=large%small;
	          large=small;
	          small=rem;
			  }
         gcd1=large;//gcd
     }
     if(sum2>1)
        {if (gcd1>sum2)
	        {large=gcd1;
	        small=sum2;
			}
	     else
	        {large=sum2;
	        small=gcd1;
			}
         while(small)
	          {rem=large%small;
	          large=small;
	          small=rem;
			  }
         gcd1=large;
     }
    }
    if (gcd1==1&&sum1!=1&&sum2!=1&&n==1)//if gcd of all the counters is equal to 1 and none of the exponents size is equal to 1 and n is equal to 1
        {printf("%d is achilles number\n",x);//then the number x is achilles so print it
        count++;}//increase the counter by 1
}
printf("We found %d achilles numbers\n",count);//print the sum of the achilles numbers found
}
