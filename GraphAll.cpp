#include<bits/stdc++.h>
using namespace std;
class GraphQuestions
{
	
	public:
	void add_edge_undirected(vector<int>graph[],int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	void create_graph(vector<int>graph[])
	{
		// add_edge_undirected(graph,0,1);
		// add_edge_undirected(graph,0,2);
		// add_edge_undirected(graph,0,5);
		// add_edge_undirected(graph,1,3);
		// add_edge_undirected(graph,2,4);
		// add_edge_undirected(graph,3,5);
		// add_edge_undirected(graph,4,5);
		// ---------------------------
		// add_edge_undirected(graph,0,2);
		// add_edge_undirected(graph,0,1);
		// add_edge_undirected(graph,1,2);
		// add_edge_undirected(graph,3,4);
		// add_edge_undirected(graph,5,6);
		// add_edge_undirected(graph,5,7);
		// add_edge_undirected(graph,7,8);
		// ------------------
		add_edge_undirected(graph,0,1);
		add_edge_undirected(graph,0,2);
		add_edge_undirected(graph,1,2);
		add_edge_undirected(graph,1,3);
		add_edge_undirected(graph,2,3);
	}
	void bfs(vector<int>graph[],int i,int vertex,vector<bool>&visited)
	{
		// unordered_set<int> s;
		// vector<bool> visited(vertex,false);
		queue<int> q;
		q.push(i);
		visited[i]=true;
		// s.insert(i);
		// cout<<i<<"\t";
		while (!q.empty())
		{
			int x=q.front();
			q.pop();
			cout<<x<<"\t";
			for(auto it :graph[x])
			{
				// if(s.count(it)==0)
				if(!visited[it])
				{
					// s.insert(it);
					// cout<<it<<"\t";
					visited[it]=true;
					q.push(it);
				}
			}
		}
	}
	void BFS_disconnected(vector<int> graph[],int vertex)
	{
		vector<bool> visited(vertex,false);
		int connected_component=0;
		for(int i=0;i<vertex;i++)
		{
			if(!visited[i])
			{
				connected_component++;
				bfs(graph,i,vertex,visited);
			}
		}
		cout<<"Connected Component = "<<connected_component;
	}
	void DFS_Rec(vector<int>graph[],vector<bool> &visited,int i)
	{
		if(!visited[i])
		{
			cout<<i<<"\t";
			visited[i]=true;
			for(auto it : graph[i]) DFS_Rec(graph,visited,it);
		}
	}
	void DFS(vector<int> graph[],int vertex)
	{
		vector<bool>visited(10,false);
		for(int i=0;i<vertex;i++)
		{
			if(!visited[i]) DFS_Rec(graph,visited,i);
		}
	}
	void shortest_path_unweighted_graph(vector<int> graph[], int vertex,int s)
	{
		// BFS is always the shortest path
		vector<int> path(vertex,INT_MAX);
		vector<bool> visited(vertex,false);
		queue<int> q;
		path[s]=0;
		q.push(s);
		visited[s]=true;
		while(!q.empty())
		{
			int t=q.front();
			q.pop();
			for(auto it:graph[t])
			{
				if(!visited[it])
				{
					path[it]=path[t]+1;
					visited[it]=true;
					q.push(it);
				}
			}
		}
		for(auto it : path)cout<<it<<"\t";
		cout<<"\n";
	}
	bool detect_cycle_DFS_rec(vector<int> graph[],int node,vector<bool>&visited,int parent)
	{
		visited[node]=true;
		for(int i=0;i<graph[node].size();i++)
		{
			if(visited[graph[node][i]]==false)
			{
				if(detect_cycle_DFS_rec(graph,graph[node][i],visited,node)==true)
					return true;
			}
			else if(graph[node][i]!=parent)
			{
				return true;
			}
		}
		return false;
	}
	bool detect_cycle_DFS(vector<int> graph[],int vertex)
	{
		vector<bool> visited(vertex,false);
		for(int i=0;i<vertex;i++)
		{
			if(!visited[i])
			{
				if(detect_cycle_DFS_rec(graph,i,visited,-1))
				{
					return true;
				}
			}
		}
		return false;
	}
};
int main()
{
	vector<int>graph[10];
	GraphQuestions obj;
	obj.create_graph(graph);
	// obj.bfs(graph,0,6);
	// cout<<"BFS : "<<"\t";
	// obj.BFS_disconnected(graph,9);
	// cout<<"\nDFS : "<<"\t";
	// obj.DFS(graph,9);
	obj.shortest_path_unweighted_graph(graph,4,0);
}