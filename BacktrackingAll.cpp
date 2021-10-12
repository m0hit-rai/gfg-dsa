#include<bits/stdc++.h>
using namespace std;
class BacktrackingQuestions
{
	public:
	bool solveMaze(vector<vector<bool>> &maze)
	{
		int n=maze.size();
		vector<vector<bool>> soln(n,vector<bool>(n,false));
		if(solveMazeRec(0,0,maze,soln))
		{
			for(auto vec:soln)
			{
				for(auto i:vec)
				{
					cout<<i<<"\t";
				}
				cout<<"\n";
			}
			return true;
		}
		return false;
	}
	bool solveMazeRec(int i, int j,vector<vector<bool>> &maze,vector<vector<bool>> &soln)
	{
		int n=maze.size();
		if(i==n-1 && j==n-1)
		{
			soln[i][j]=1;
			return true;
		}
		if(isSafe_maze(i,j,maze))
		{
			soln[i][j]=1;
			if(solveMazeRec(i+1,j,maze,soln)) return true;
			if(solveMazeRec(i,j+1,maze,soln)) return true;
			soln[i][j]=0;
		}
		return false;
	}
	bool isSafe_maze(int i, int j,vector<vector<bool>> &maze)
	{
		return (i<maze.size() && j<maze.size() && maze[i][j]);
	}
	bool isSafe_n_queen(int row,int col,vector<vector<bool>>&board)
	{
		// As we already place queens in defferent columns, we only need to check for
		// queens placed in same row
		for(int i=0;i<col;i++)
		{
			if(board[row][i])
			{
				return false;
			}
		}
		
		// current queen is placed at (row,col) and no queen has been placed after the current column
		// so we only need to check in the diagonals where the column is lesser row can inc or decrease
		for(int i=row,j=col;i>=0 && j>=0;i--,j--)
		{
			if(board[i][j])
			{
				return false;
			}
		}
		for(int i=0,j=col;i<board.size() && j>=0;i++,j--)
		{
			if(board[i][j])
			{
				return false;
			}
		}
	}
	bool solve_n_queen_rec(int col,vector<vector<bool>>&board)
	{
		if(col==board.size())
		{
			// if queens have been placed in all columns and all have been safe
			// we have found the answer
			return true;
		}
		for(int i=0;i<board.size();i++)
		{
			// we try to place a queen in every row in the given col, the place where 
			// it doesn't attack another queen, that is where we move forwar in the recursion tree
			if(isSafe_n_queen(i,col,board))
			{
				board[i][col]=true;
				if(solve_n_queen_rec(col+1,board))
				{
					return true;
				}
				board[i][col]=false;
			}
		}
		return false;
	}
	bool solve_n_queen(int n)
	{
		vector<vector<bool>> board(n,vector<bool>(n,false));
		if(solve_n_queen_rec(0,board))
		{
			return true;
			for(auto v:board)
			{
				for(auto b:v)
				{
					cout<<b<<"\t";
				}
				cout<<"\n";
			}
		}
		return false;
	}
};
int main()
{
	BacktrackingQuestions obj;
	vector<vector<bool>> maze={{1,0,1},{1,0,0},{0,1,1}};
	obj.solveMaze(maze);
}