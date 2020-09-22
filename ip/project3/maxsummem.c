#include<stdio.h>
#include<stdlib.h>
#include"path.h"
#define PATH 1
int memrec(int,int,int **,int,int,int**);
void solve(int n,int m,int **board)
{
	int max,i,maxrec,j,**mem,imax,jmax;
	jmax=-1;//set jmax as an invalid price(needed for path)
	mem=malloc(n*sizeof(int*));//call malloc for the memmory needed 
	if(mem==NULL)//if malloc fails
		exit(1);//stop
	for(i=0;i<n;i++)
		{
			mem[i]=malloc(m*sizeof(int));
			if(&mem[i]==NULL)
				exit(1);
		}
	for(i=0;i<n;i++)//set all the cells of the board mem as -1
		{for(j=0;j<m;j++)
			mem[i][j]=-1;
		}
	max=-1;//set max as an invalid number
	for(j=0;j<m;j++)
	{
		i=n-1;
		maxrec=memrec(i,j,board,n,m,mem);//call the recursive function for every column of the board mem
		if (maxrec>max)//if the price returned by the function is bigger than the by far max
			{
				max=maxrec;//set max as maxrec
				jmax=j;//set jmax as j(needed for path)
			}
	}
imax=n-1;
//print
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
		printf("%d\t",board[i][j]);
printf("\n");
}
	printf("Running maxsummem\n");
	printf("Max sum is %d\n",max);
//path(PATH defined as 1)
		#ifdef PATH
			path(board,mem,n,m,imax,jmax);
		#endif
for(i=0;i<n;i++)//free the memory 
	free(mem[i]);
free(mem);
}

int memrec(int i,int j,int **board,int n,int m,int **mem)
{
	int a,b,c,sum;
	sum=0;
	if(i==0)//base case
	{	if(mem[i][j]==-1)//if that cell is -1 put at it the apropriate sum
			mem[i][j]=board[0][j];
		sum+=mem[i][j];//increase sum
	}
	else if(i>0&&j==0)
	{
		if(mem[i][j]==-1)//fill the board's cells
	{
		a=memrec(i-1,m-1,board,n,m,mem);
		b=memrec(i-1,0,board,n,m,mem);
		c=memrec(i-1,1,board,n,m,mem);
		//find the max and add it to the apropriate cell
		if(a>=b&&a>=c)
			mem[i][j]=board[i][0]+a;
		else if(b>=a&&b>=c)
			mem[i][j]=board[i][j]+b;
		else if(c>=a&&c>=b)
			mem[i][j]=board[i][j]+c;
	}
	sum+=mem[i][j];//increase sum
	}
	else if(i>0&&j>0&&j<m-1)
	{
		if(mem[i][j]==-1)//fill the board's cells
		{
		a=memrec(i-1,j-1,board,n,m,mem);
		b=memrec(i-1,j,board,n,m,mem);
		c=memrec(i-1,j+1,board,n,m,mem);
		//find max and add it to the apropriate cell
		if(a>=b&&a>=c)
			mem[i][j]=board[i][j]+a;
		else if(b>=a&&b>=c)
			mem[i][j]=board[i][j]+b;
		else if(c>=a&&c>=b)
			mem[i][j]=board[i][j]+c;
	}
	sum+=mem[i][j];//increase sum
		}
	else if(i>0&&j==m-1)
	{
		if(mem[i][j]==-1)//fill the board's cells
		{
		a=memrec(i-1,m-2,board,n,m,mem);
		b=memrec(i-1,m-1,board,n,m,mem);
		c=memrec(i-1,0,board,n,m,mem);
		//find max and add it to the apropriate cell
		if(a>=b&&a>=c)
			mem[i][j]=board[i][j]+a;
		else if(b>=a&&b>c)
			mem[i][j]=board[i][j]+b;
		else if(c>=a&&c>=b)
			mem[i][j]=board[i][j]+c;
	}
	sum+=mem[i][j];//increase sum
	}
return sum;
}
