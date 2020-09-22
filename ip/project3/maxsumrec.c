#include<stdio.h>
int rec(int,int,int **,int,int);
void solve(int n,int m,int **board)
{
	int max,i,maxrec,j;
	maxrec=0;
	max=-1;//set max as -1(an invalid value max>=0)
	for(j=0;j<m;j++)//for every column call the recursive function
	{
		i=n-1;
		maxrec=rec(i,j,board,n,m);//returns the max sum found starting from this column
		if (maxrec>max)//if maxrec is largest than the by far max
			max=maxrec;//set max as maxrec
	}
	//print
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",board[i][j]);
		printf("\n");
	}
	printf("Running maxsumrec\n");
	printf("Max sum is %d\n",max);
}

int rec(int i,int j,int **board,int n,int m)
{
	int a,b,c,sum=0;
	if(i==0)//base case
		sum+= board[0][j];
	else if(i>0&&j==0)
	{	a=rec(i-1,m-1,board,n,m);
		b=rec(i-1,0,board,n,m);
		c=rec(i-1,1,board,n,m);
		//find the max of the three options and add it to sum
		if(a>=b&&a>=c)
			sum+= board[i][0]+a;
		else if(b>=a&&b>=c)
			sum+= board[i][0]+b;
		else if(c>=a&&c>=b)
			sum+= board[i][0]+c;
	}
	else if(i>0&&j>0&&j<m-1)
	{
		a=rec(i-1,j-1,board,n,m);
		b=rec(i-1,j,board,n,m);
		c=rec(i-1,j+1,board,n,m);
		//find the max of the three options and add it to sum
		if(a>=b&&a>=c)
			sum+= board[i][j]+a;
		else if(b>=a&&b>=c)
			sum+= board[i][j]+b;
		else if(c>=a&&c>=b)
			sum+= board[i][j]+c;
	}
	else if(i>0&&j==m-1)
	{
		a=rec(i-1,m-2,board,n,m);
		b=rec(i-1,m-1,board,n,m);
		c=rec(i-1,0,board,n,m);
		//find the max of the three options and  add it to sum
		if(a>=b&&a>=c)
			sum+= board[i][m-1]+a;
		else if(b>=a&&b>=c)
			sum+=board[i][m-1]+b;
		else if(c>=a&&c>=b)
			sum+=c+board[i][m-1];
	}
return sum;
}
