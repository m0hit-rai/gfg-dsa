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
		if(isSafe(i,j,maze))
		{
			soln[i][j]=1;
			if(solveMazeRec(i+1,j,maze,soln)) return true;
			if(solveMazeRec(i,j+1,maze,soln)) return true;
			soln[i][j]=0;
		}
		return false;
	}
	bool isSafe(int i, int j,vector<vector<bool>> &maze)
	{
		return (i<maze.size() && j<maze.size() && maze[i][j]);
	}
};
int main()
{
	BacktrackingQuestions obj;
	vector<vector<bool>> maze={{1,0,1},{1,0,0},{0,1,1}};
	obj.solveMaze(maze);
}