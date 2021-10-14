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
	bool isSafe_n_queen(int row,int col,vector<vector<bool>>&board,int n)
	{
		// cout<<"\tisSafe col = "<<col<<" row = "<<row<<"\n";
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
		for(int i=row,j=col;i<n && j>=0;i++,j--)
		{
			if(board[i][j])
			{
				return false;
			}
		}
		return true;
	}
	bool solve_n_queen_rec(int col,vector<vector<bool>>&board,int n)
	{
		// cout<<"NQueenRec col = "<<col<<"\n";
		if(col==n)
		{
			// if queens have been placed in all columns and all have been safe
			// we have found the answer
			return true;
		}
		for(int i=0;i<n;i++)
		{
			// we try to place a queen in every row in the given col, the place where 
			// it doesn't attack another queen, that is where we move forwar in the recursion tree
			if(isSafe_n_queen(i,col,board,n))
			{
				// cout<<"\t\tif col = "<<col<<" row = "<<i<<"\n";
				// for(auto v:board)
				// {
				// 	for(auto b:v)
				// 	{
				// 		cout<<b<<" ";
				// 	}
				// 	cout<<"\n";
				// }
				board[i][col]=true;
				if(solve_n_queen_rec(col+1,board,n))
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
		// for(int i=0;i<n;i++)
		// {
			if(solve_n_queen_rec(0,board,n))
			{
				for(auto v:board)
				{
					for(auto b:v)
					{
						cout<<b<<" ";
					}
					cout<<"\n";
				}
				return true;
			}
		// }
		return false;
	}
	bool isSafe_sudoku(int r, int c, vector<vector<int>>&puzzle, int nxt)
	{
		// nxt is to be filled at (r,c) int th matrix puzzle
		int n=puzzle.size();
		for(int i=0;i<n;i++)
		{
			// che
			if(puzzle[r][i]==nxt ||puzzle[i][c]==nxt )
			{
				return false;
			}
		}
		int nrt=sqrt(n);
		// n=4,nrt=2;n=9,nrt=3....
		// rounding down row & col to nearest multiple of nrt
		int grid_row=(r/nrt)*nrt,grid_col=(c/nrt)*nrt;
		for(int i=0;i<nrt;i++)
		{
			for(int j=0;j<nrt;j++)
			{
				if(puzzle[grid_row+i][grid_col+j]==nxt)
				{
					return false;
				}
			}
		}
		return true;
	}
	bool solve_sudoku_rec(vector<vector<int>>&puzzle)
	{
		int i,j,n=puzzle.size();
		bool flag=false;
		// checking which position is a zero
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(puzzle[i][j]==0)
				{
					flag=true;
					break;
				}
			}
			if(flag)
			break;
		}
		// if no zero found that means whole matrix is filled
		// so return zero
		if(!flag)
		return true;
		for(int num=1;num<=n;num++)
		{
			if(isSafe_sudoku(i,j,puzzle,num))
			{
				// If it is safe to put num in the concerned position then 
				// put it there and solve for the rest
				puzzle[i][j]=num;
				if(solve_sudoku_rec(puzzle))
				return true;
				puzzle[i][j]=0;
			}
		}
		return false;
	}
	bool solve_sudoku(vector<vector<int>>&puzzle)
	{
		if(solve_sudoku_rec(puzzle))
		{
			cout<<"\n----Answer----\n\n";
			int x=0;
			int n=sqrt((int)puzzle.size());
			for(auto v:puzzle)
			{
				int y=0;
				for(auto b:v)
				{
					
					cout<<b<<" ";
					if(y%n==(n-1))
					cout<<"| ";
					y++;
				}
				cout<<"\n";
				if(x%n==(n-1))
				{
					for(int i=0;i<(2*(n*n)+n);i++)
					cout<<"_";
					cout<<"\n";
				}
				x++;
			}
			return true;
		}
		return false;
	}
};
int main()
{
	BacktrackingQuestions obj;
	// vector<vector<bool>> maze={{1,0,1},{1,0,0},{0,1,1}};
	// obj.solveMaze(maze);
	// obj.solve_n_queen(25);
	vector<vector<int>>p(9,vector<int>(9,0)); //= {{1,2,3,4},
	// 				{3,4,1,2},
	// 				{2,1,0,0},
	// 				{0,0,0,0}};
	// int n;
	// cin>>n;
	// for(int i=0;i<n;i++)
	// {
	// 	vector<int> x;
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		int y;
	// 		cin>>y;
	// 		x.push_back(y);
	// 	}
	// 	p.push_back(x);
	// }
	p[0][0]=7;
	p[0][2]=6;
	obj.solve_sudoku(p);
}