#include<stdio.h>
#include<stdlib.h>
#include"maxsum.h"
int main(void)
{
	int n,m,**board,i,j;
	scanf("%d%d",&n,&m);//read the sizes
	board=malloc(n*sizeof(int*));//do malloc for the memory needed
	if(board==NULL)//check if malloc failed
		return 1;
	for(i=0;i<n;i++)
	{
		board[i]=(int *)malloc(m*sizeof(int));
		if(&board[i]==NULL)
			return 1;
	}
	for(i=0;i<n;i++)//scan the arrow
		{
		for(j=0;j<m;j++)
		{
			scanf("%d", &board[i][j]);
		}
		}
	solve(n,m,board);//call the function solve(depends on the compilation)
	for(i=0;i<n;i++)//free the memory
		free(board[i]);
	free(board);
return 0;
}

