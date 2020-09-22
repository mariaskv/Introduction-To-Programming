#include<stdlib.h>
#include<stdio.h>
#include"path.h"
#define PATH 1
void solve(int n,int m,int **board)
{
	int i,j,max,left,right,up,**dp,imax,jmax;
	dp=malloc(n*sizeof(int *));//call malloc for the memory needed
	if(dp==NULL)//if malloc fails
		exit(1);//exit
	for(i=0;i<n;i++)
		{
			dp[i]=malloc(m*sizeof(int));
			if(dp[i]==NULL)
				exit(1);
		}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			dp[i][j]=board[i][j];//set dp as board
	}
	for(i=1;i<n;i++)//dont change the first line
	{ //for every cell find the by far biggest sum and add it to this
		for(j=0;j<m;j++)
		{
			if(j==0)
			{
				left=dp[i-1][m-1];
				right=dp[i-1][j+1];
				up=dp[i-1][j];
			}
			else if(j==m-1)
			{
				left=dp[i-1][j-1];
				right=dp[i-1][0];
				up=dp[i-1][j];
			}
			else
			{
				left=dp[i-1][j-1];
				right=dp[i-1][j+1];
				up=dp[i-1][j];
			}
			if(left>=right&&left>=up)
				dp[i][j]+=left;
			else if(right>=left&&right>=up)
				dp[i][j]+=right;
			else if(up>=left&&up>=right)
				dp[i][j]+=up;
		}
	}
	max=dp[n-1][0];//set max as the first cell of the last line
	imax=n-1;//set i max as n-1(needed for path)
	jmax=0;//set jmax as 0(needed for path)
	for(j=1;j<m;j++)
	{
		if (dp[n-1][j]>max)//search for the largest sum
		{
			max=dp[n-1][j];
			jmax=j;//find the j matches to the biggest sum
		}
	
	}
	//print
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d\t",board[i][j]);
	printf("\n");
	}
	printf("Running maxsumdp\n");
        printf("Max sum is %d\n",max);
	//path
	#ifdef PATH
		path(board,dp,n,m,imax,jmax);
	#endif
for(i=0;i<n;i++)//free the memory
	free(dp[i]);
free(dp);	
}
