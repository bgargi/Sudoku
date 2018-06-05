#include<bits/stdc++.h>

using namespace std;

/*
*Check if a given value x is present in 'rowth' row.
*/

int search_row(int board[][9],int n,int x,int row)		
{
	for(int i=0;i<n;i++)
	{	
		if(board[row][i]==x)
		return 1;
	}

	return 0;
}

/*
*Check if a given value y is present in 'columnth' column.
*/

int search_column(int board[][9],int n,int x,int column)
{

	for(int i=0;i<n;i++)
		if(board[i][column]==x)
			return 1;

	return 0;

}

/*
Check if the number is present in a position's given 3x3 cell area,given the coodinates of that cell.
*/

int search_3by3(int board[][9],int n,int x,int row,int column)
{

	int c=column/3;
	int r=row/3;

	int i=r*3;
	
	for(int i=(r*3);i<((r*3)+3);i++)
		for(int j=(c*3);j<((c*3)+3);j++)
			if(board[i][j]==x)
				return 1;

	return 0;
}

/*
Checks if all cells are full.
*/

int allFull(int board[][9],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==0)
				return 0;
	return 1;
}

/*
Finds the first empty location and stores it in row,col.
*/


void findEmptyLoc(int board[][9],int n,int &row,int &col)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(board[i][j]==0)
			{
				row=i;
				col=j;
				return;
			}
}

/*
Checks if a given move is valid or not.
*/


int isValid(int board[][9],int n,int row,int col,int num)
{

	return ((!search_row(board,n,num,row))&&(!search_column(board,n,num,col))&&(!search_3by3(board,n,num,row,col)));
}

/*
Prints Board
*/

void print_board(int board[][9],int n)
{
	for(int i=0;i<n+3;i++)
		cout<<" _";
	cout<<endl;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j%3==0)
				cout<<"| ";

			cout<<board[i][j]<<" ";

			if(j==n-1)
				cout<<"| ";


		}
		cout<<endl;
		if(i%3==2)
		{
			for(int k=0;k<n+3;k++)
				cout<<" _";
			cout<<endl;
		}
		cout<<endl;
		
		
	}
}

/*
The solve function,returns 1 if it solved,0 if not possible.
*/

int solve(int board[][9],int n)
{

	int row,col;

	if(allFull(board,n))
	{
		return 1;
	}

	for(int i=1;i<=n;i++)
	{
		findEmptyLoc(board,n,row,col);

		if(isValid(board,n,row,col,i))
		{

			board[row][col]=i;

			if(solve(board,n))
			{
				return 1;
			}

			board[row][col]=0;	//Invalid move hence revert back.
		}
	}

	return 0;		//Signals an invalid move.

}

int main()
{	
	int board[9][9];

	int n=9;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			board[i][j]=0;

	int m;
	//cout<<"Enter the number of markings"<<endl;
	cin>>m;
	//cout<<"Enter coodinates and number value at that coodinate. (x y z)"<<endl;

	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;

		board[x-1][y-1]=z;
	}

	print_board(board,n);

	if(solve(board,n))
	{
		cout<<"SOLVED BOARD:\n";
		print_board(board,n);
	}
	else
		cout<<"CANNOT SOLVE";
	
	return 0;

}