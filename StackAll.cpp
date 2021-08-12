#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<stack>
#include<string>
#define ll long long
#define md 1000000007ll
using namespace std;
class StackQuestions
{
	public:
	bool matching_parenthesis(string s)
	{
		stack<char> par;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(' || s[i]=='{' || s[i]=='[')
				par.push(s[i]);
			else
			{
				if(par.empty())
					return false;
				else if(!is_matching(par.top(),s[i]))
					return false;
				else
					par.pop();
			}
		}
		return par.empty();
	}
	bool is_matching(char a, char b)
	{
		return ((a=='(' && b==')')||(a=='{' && b=='}')||(a=='[' && b==']'));
	}
	void stock_span_problem(int stock[],int n)
	{
		// int ans[n];//,stack[n];
		// ans[0]=1;
		// stack[0]=stock[0];
		// for(int i=1;i<n;i++)
		// {
		// 	int count=1,j=i-1;
		// 	while(j>=0 && stock[j--]<=stock[i])
		// 	{
		// 		count++;
		// 	}
		// 	ans[i]=count;
		// }
		// for(auto it : ans)
		// {
		// 	cout<<it<<"\t";
		// }
		// ---------------
		// O(n) algo
		stack<int> s;
		s.push(0);
		cout<<"1\t";
		for(int i=1;i<n;i++)
		{
			while(s.empty()==false && stock[s.top()]<=stock[i])
			{
				s.pop();
			}
			int span=s.empty()?i+1:i-s.top();

			cout<<span<<"\t";
			s.push(i);
		}
	}
	void previous_greater_element(int a[], int n)
	{
		stack<int> s;
		s.push(a[0]);
		cout<<"-1\t";
		for(int i=1;i<n;i++)
		{
			// if(s.top()>a[i])
			// {
			// 	cout<<s.top()<<"\t";
			// 	s.push(a[i]);
			// }
			// else
			// {
				while(!s.empty() && s.top()<=a[i])
				s.pop();
				
				if(s.empty())
				{
					cout<<"-1\t";
				}
				else
				{
					cout<<s.top()<<"\t";
				}
				s.push(a[i]);
			// }
		}
		cout<<"\n";
	}
	void next_greater_element(int a[], int n)
	{
		int ans[n];
		stack<int> s;
		s.push(a[n-1]);
		ans[n-1]=-1;
		for(int i=n-2;i>=0;i--)
		{
			while(!s.empty() && s.top()<=a[i])
				s.pop();
			ans[i]=s.empty()?-1:s.top();
			s.push(a[i]);
		}
		for(int i=0;i<n;i++)
		cout<<ans[i]<<"\t";
		cout<<"\n";
	}
	void previous_smaller_index(int a[], int n,int ps[])
	{
		stack<int> s;
		s.push(0);
		// cout<<"-1\t";
		ps[0]=-1;
		for(int i=1;i<n;i++)
		{
			while (!s.empty() && a[s.top()]>=a[i])
			{
				s.pop();
			}
			if(s.empty())
			// cout<<"-1\t";
			ps[i]=-1;
			else
			// cout<<s.top()<<"\t";
			ps[i]=s.top();
			
			s.push(i);
		}
		// cout<<"\n";
	}
	void next_smaller_index(int a[], int n, int ns[])
	{
		stack<int> s;
		s.push(n);
		ns[n-1]=n;
		for(int i=n-2;i>=0;i--)
		{
			while(!s.empty() && a[s.top()]>=a[i])
			s.pop();

			if(s.empty())
			ns[i]=n;
			else
			ns[i]=s.top();

			s.push(i);
		}
	}
	void max_area_in_a_histogram(int a[], int n)
	{
		// a[] = contains the height of each bar of histogram
		int ps[n],ns[n],res=0;
		previous_smaller_index(a,n,ps);
		next_smaller_index(a,n,ns);
		for(int i=0;i<n;i++)
		{
			int ar=a[i];
			ar+=(i-ps[i]-1)*a[i];
			ar+=(ns[i]-i-1)*a[i];
			res=max(res,ar);
		}
		cout<<"Max area = "<<res;
	}
	void max_area_in_a_histogram_efficient(int a[], int n)
	{
		stack<int> s;
		int res=0;
		for(int i=0;i<n;i++)
		{
			while(!s.empty() && a[s.top()]>=a[i])
			{
				int t=s.top();
				s.pop();
				int curr=a[t]*(s.empty()?i:(i-s.top()-1));
				res=max(res,curr);
			}
			s.push(i);
		}
		while(!s.empty())
		{
			int t=s.top();
			s.pop();
			int curr=a[t]*(s.empty()?n:(n-s.top()-1));
			res=max(res,curr);
		}
		cout<<"Max area = "<<res<<endl;
	}
	int max_histo(vector<int> a)
	{
		stack<int> s;
		int res=0;
		int n=a.size();
		for(int i=0;i<n;i++)
		{
			while(!s.empty() && a[s.top()]>=a[i])
			{
				int t=s.top();
				s.pop();
				int curr=a[t]*(s.empty()?i:(i-s.top()-1));
				res=max(res,curr);
			}
			s.push(i);
		}
		while(!s.empty())
		{
			int t=s.top();
			s.pop();
			int curr=a[t]*(s.empty()?n:(n-s.top()-1));
			res=max(res,curr);
		}
		return res;
	}
	void largest_rectangle_with_all_ones(vector<vector<int>> v)
	{
		// 0{{0,1,1,0},
		//  1{1,1,1,1},
		//  2{1,1,1,1},
		//  3{1,0,1,1}} ---> Input looks like this
		// Output for above = 8 [row1 + row2]
		int res=max_histo(v[0]);
		for(int i=1;i<v.size();i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				if(v[i][j])
				{
					v[i][j]+=v[i-1][j];
				}
			}
			res=max(res,max_histo(v[i]));
		}
		cout<<"Maximum area = "<<res<<endl;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// stack<int>s;
	// for(int i=0;i<50;i+=10)
	// 	s.push(i);
	// while(!s.empty())
	// {
	// 	cout<<s.top()<<endl;
	// 	s.pop();
	// }
	StackQuestions obj;
	// string ans = obj.matching_parenthesis("({[()()]}())")?"Correct":"Wrong";
	// cout<<ans<<endl;
	int a1[]={30,20,25,28,27,29};
	int a2[]={60,10,20,40,35,30,50,70,65};
	// obj.stock_span_problem(a1,sizeof(a1)/sizeof(int));
	// obj.previous_greater_element(a2,sizeof(a2)/sizeof(int));
	// obj.next_greater_element(a2,sizeof(a2)/sizeof(int));
	// obj.previous_smaller_index(a2,sizeof(a2)/sizeof(int));
	// obj.max_area_in_a_histogram(a1,sizeof(a1)/sizeof(int));
	// obj.max_area_in_a_histogram_efficient(a1,sizeof(a1)/sizeof(int));
	vector<vector<int>> v={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,0,0,1}};
	obj.largest_rectangle_with_all_ones(v);
}

