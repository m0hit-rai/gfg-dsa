#include<bits/stdc++.h>
using namespace std;
struct jobs
{
	int job_number,deadline,profit;
	jobs()
	{
		job_number=-1;
		deadline=-1;
		profit=-1;
	}
	jobs(int j,int d,int p)
	{
		job_number=j;
		deadline=d;
		profit=p;
	}
};
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
	static bool my_sort_JSP(jobs a,jobs b)
	{
		return a.profit>b.profit;
	}
	void job_sequencing_problem(vector<jobs> &jb)
	{
		sort(jb.begin(),jb.end(),my_sort_JSP);
		int max_deadline=-1,prof=0;
		for(auto j:jb)
		{
			max_deadline=max(max_deadline,j.deadline);
		}
		vector<jobs>ans(max_deadline);
		ans[jb[0].deadline-1]=jb[0];
		for(int i=1;i<jb.size();i++)
		{
			int x=1;
			while(jb[i].deadline>=x && ans[jb[i].deadline-x].job_number!=-1)
			{
				x++;
			}
			if((jb[i].deadline-x)>=0)
			{
				ans[jb[i].deadline-x]=jb[i];
				// prof+=jb[i].profit;
			}
		}
		int tm=0;
		cout<<"Time\tJNo\tDdln\tProf\n";
		for(auto j:ans)
		{
			cout<<tm<<" - "<<(tm+1)<<"\t";
			tm++;
			if(j.profit!=-1)
			{
				prof+=j.profit;
				cout<<j.job_number<<"\t"<<j.deadline<<"\t"<<j.profit<<"\n";
			}
			else
			{
				cout<<"Nothing Scheduled in this time\n";
			}
		}
		cout<<"Profit made : "<<prof;
	}
};
int main()
{
	
	GreedyQuestions obj;
	// vector<vector<int>> act={{10,20},{20,30},{12,25},{11,20},{20,21},{25,27},{1,27}};
	// obj.activity_selection_problem(act);
	// vector<vector<int>> wei={{50,600},{20,500},{30,400}};
	// obj.fractional_knapsack_problem(wei,70);
	// vector<jobs> job_seq={jobs(0,2,100), jobs(1,1,50), jobs(2,2,10),jobs(3,1,20),jobs(4,3,30)};
	vector<jobs> job_seq={jobs(0,4,50),jobs(1,1,5),jobs(2,1,20),jobs(3,5,10),jobs(4,5,80)};
	// for(auto jb:job_seq)
	// {
	// 	cout<<jb.job_number<<"\t"<<jb.deadline<<"\t"<<jb.profit<<"\n";
	// }
	obj.job_sequencing_problem(job_seq);
}