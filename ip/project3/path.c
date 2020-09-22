#include<stdio.h>
#include<stdlib.h>
void path(int ** board,int ** dp,int n,int m,int imax,int jmax)
{
	int end,left,right,up,i,k,j,pr;
	j=jmax;//set j as jmax
	for(k=0;k<n-1;k++)//for n-1 times
	{
			end=dp[imax][j];//set end as max
			jmax=j;//set jmax as j
	for(i=imax;i>k;i--)//starting from the end of the board
	{//in every loop find the previous element
		if(jmax==0)
		{
			left=dp[i-1][m-1];
			right=dp[i-1][jmax+1];
			up=dp[i-1][jmax];
		}
		else if(jmax==m-1)
		{
			left=dp[i-1][jmax-1];
			right=dp[i-1][0];
			up=dp[i-1][jmax];
		}
		else
		{
			left=dp[i-1][jmax-1];
			right=dp[i-1][jmax+1];
			up=dp[i-1][jmax];
		}
		if (left+board[i][jmax]==end)
		{
			if(jmax==0)
				jmax=m-1;
			else
				jmax=jmax-1;
		}
		else if(right+board[i][jmax]==end)
		{
			if(jmax==m-1)
				jmax=0;
			else
				jmax=jmax+1;
		}
		else if(up+board[i][jmax]==end)
		{
			jmax=jmax;
		}
		end=dp[i-1][jmax];//set end as that element
		pr=board[i-1][jmax];//set pr as the element of board with the same i,j
	}
printf("%d ->",pr);//print that element(in the first loop it is the 1,in the second the 2etc..)
	}
printf("%d\n",board[imax][j]);//print the last element
}
