#include<bits/stdc++.h>
using namespace std;
class GreedyQuestions
{
	public:
	void activity_selection_problem(vector<vector<int>>&activities)
	{
		sort(activities.begin(),activities.end(),my_sort_ASP);
		for(auto it :activities)
		{
			for(auto x:it )
			{
				cout<<x<<"\t";
			}
			cout<<"\n";
		}
		int prev=0;
		int res=1;
		for(int curr=1;curr<activities.size();curr++)
		{
			if(activities[curr][0]>=activities[prev][1])
			{
				res++;
				prev=curr;
			}
		}
		cout<<"Number of activites included = "<<res;
	}
	static bool my_sort_ASP(vector<int>a,vector<int> b)
	{
		if(a[1]<b[1])return true;
		if(a[1]==b[1] && a[0]<b[0]) return true;
		return false;
	}
	static bool my_sort_FKP(vector<int>a,vector<int> b)
	{
		double vala=a[1]/(1.0*a[0]);
		double valb=b[1]/(1.0*b[0]);
		return vala>valb; 
	}
	void fractional_knapsack_problem(vector<vector<int>> &weights, int max_weight_capacity)
	{
		// weights = {{weight,value},{weight,value},{weight,value}....}
		sort(weights.begin(),weights.end(),my_sort_FKP);
		double res=0.0;
		int curr_cap=max_weight_capacity;
		// for(auto it :weights)
		// {
		// 	for(auto x:it )
		// 	{
		// 		cout<<x<<"\t";
		// 	}
		// 	cout<<"\n";
		// }
		
		for(auto v:weights)
		{
			if(v[0]<=curr_cap)
			{
				curr_cap-=v[0];
				res+=v[1];
			}
			else
			{
				res+=curr_cap*(v[1]/(v[0]*1.0));
				break;
			}
			cout<<"\tv[0] = "<<v[0]<<"\tres = "<<res<<"\n";
		}
		cout<<"Amount stored = "<<res;
	}
};
int main()
{
	
	GreedyQuestions obj;
	// vector<vector<int>> act={{10,20},{20,30},{12,25},{11,20},{20,21},{25,27},{1,27}};
	// obj.activity_selection_problem(act);
	vector<vector<int>> wei={{50,600},{20,500},{30,400}};
	obj.fractional_knapsack_problem(wei,70);
}