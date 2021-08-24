#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<vector>
#include<stack>
#include<string>
#define ll long long
#define md 1000000007ll
using namespace std;
#define sfsq stack_for_stackques
struct stack_for_stackques
{
	vector<int> arr;
	// vector<int>min_st;
	int arr_ele,min_st_ele;
	sfsq()
	{
		arr_ele=-1;
		min_st_ele=-1;
	}
	// void push(int x)
	// {
	// 	arr.push_back(x);
	// 	arr_ele++;
	// 	if(min_st_ele==-1)
	// 	{
	// 		min_st.push_back(x);
	// 		min_st_ele++;
	// 	}
	// 	else
	// 	{
	// 		if(x<=min_st[min_st_ele])
	// 		{
	// 			min_st.push_back(x);
	// 			min_st_ele++;
	// 		}
	// 	}

	// }
	// int pop()
	// {
	// 	if(arr_ele!=-1)
	// 	{
	// 		int x=arr[arr_ele];
	// 		arr.pop_back();
	// 		arr_ele--;
	// 		if(x==min_st[min_st_ele])
	// 		{
	// 			min_st.pop_back();
	// 			min_st_ele--;
	// 		}
	// 		return x;
	// 	}
	// 	else
	// 	{
	// 		return -10092;
	// 	}
	// }
	int top()
	{
		if(arr_ele!=-1)
		return arr[arr_ele];
		else
		return -10091;
	}
	int size()
	{
		return ((int)arr.size());
	}
	// int get_min()
	// {
	// 	if(min_st_ele!=-1)
	// 	return min_st[min_st_ele];
	// 	else
	// 	return -10093;
	// }
	// --------------
	// O(1) space but only for +ve elements
	void push(int x)
	{
		if(arr_ele==-1)
		{
			min_st_ele=x;	
		}
		else
		{
			if(x<min_st_ele)
			{
				// store the stack element as difference between current min and new element
				// curr min = 50, x= 20
				// 20-50=-30 will be stored in stack
				x-=min_st_ele;
				min_st_ele+=x;
			}
		}
		arr.push_back(x);
		arr_ele++;
	}
	int pop()
	{
		int x=arr[arr_ele];
		arr_ele--;
		arr.pop_back();
		if(x<0)
		{
			// let x=-30, min=20;
			// => min before x was 20+30=50
			min_st_ele+=-x;
			return (min_st_ele+x);
		}
		return x;
	}
	int get_min()
	{
		return min_st_ele;
	}

};
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
	void check_get_min_sfsq()
	{
		sfsq s;
		s.push(50);
		s.push(20);
		s.push(30);
		cout<<"s.push(50);\ns.push(20);\ns.push(30);\n";
		cout<<s.get_min()<<"\n";
		s.push(5);
		cout<<"s.push(5);\n";
		cout<<s.get_min()<<"\n";
		s.push(4);
		cout<<"s.push(4);\n";
		cout<<s.get_min()<<"\n";
		int x = s.pop();
		cout<<"s.pop(); = "<<x<<"\n";
		cout<<s.get_min()<<"\n";
	}
	int precedence(char c)
	{
		if(c=='^')
		return 3;
		if(c=='*' || c=='/')
		return 2;
		if(c=='+' || c=='-')
		return 1;

		return 0;
	}
	string convert_infix_to_postfix(string infix)
	{
		stack<char> s;
		string ans;
		// for(int i=0;i<infix.length();i++)
		// {
		// 	if((infix[i]=='+')||(infix[i]=='%')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/'))
		// 	{
		// 		op.push(infix[i]);
		// 	}
		// 	else if(infix[i]==')')
		// 	{
		// 		ans+=op.top();
		// 		op.pop();
		// 	}
		// 	else if('a'<=infix[i] && infix[i]<='z')
		// 	{
		// 		ans+=infix[i];
		// 	}
		// }
		// -----------------------------------------------------
		// This only works for infix wit paranthesis added
		for(int i=0;i<infix.length();i++)
		{
			if(('a'<=infix[i] && infix[i]<='z') || ('0'<=infix[i] && infix[i]<='9'))
			{
				ans+=infix[i];
			}
			else if(infix[i]=='(')
			{
				s.push(infix[i]);
			}
			else if(infix[i]==')')
			{
				while(s.top()!='(')
				{
					ans+=s.top();
					s.pop();
				}
				s.pop();
			}
			else
			{
				while(!s.empty() && precedence(s.top())>=precedence(infix[i]))
				{
					ans+=s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
		}
		while(!s.empty())
		{
			ans+=s.top();
			s.pop();
		}
		return ans;
		// cout<<"Infix = "<<infix<<"\nPostfix = "<<ans<<"\n";
	}
	inline bool isOperator(char c)
	{
		return (c=='+' || c=='*' || c=='-' || c=='^' || c=='/');
	}
	void evaluate_postfix(string s)
	{
		int n=s.length();
		stack<int> st;
		for(int i=0;i<s.length();i++)
		{
			if(isOperator(s[i]))
			{
				int a=st.top();
				st.pop();
				int b=st.top();
				st.pop();
				int x;
				if(s[i]=='+')
					x=b+a;
				else if(s[i]=='-')
					x=b-a;
				else if(s[i]=='*')
					x=b*a;
				else if(s[i]=='/')
					x=b/a;
				else
					x=pow(b,a);
				st.push(x);
				cout<<"i = "<<i<<"\ta = "<<a<<"\tb = "<<b<<"\tx = "<<x<<"\n";
			}
			else
			{
				st.push((s[i]-'0'));
			}
		}
		// cout<<s<<endl;
		cout<<st.top()<<endl;
	}
	void convert_infix_to_prefix(string s)
	{
		stack<char> st;
		string ans="";
		for(int i=s.length()-1;i>=0;i--)
		{
			if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z'))
			{
				ans=ans+s[i];
			}
			else if(s[i]==')')
			{
				st.push(s[i]);
			}
			else if(isOperator(s[i]))
			{
				while(!st.empty() && precedence(s[i])<precedence(st.top()))
				{
					ans=ans+st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if(s[i]=='(')
			{
				while(!st.empty() && st.top()!=')')
				{
					ans=ans+st.top();
					st.pop();
				}
				st.pop();
			}
		}
		while(!st.empty())
		{
			ans=ans+st.top();
			st.pop();
		}
		reverse(ans.begin(),ans.end());
		cout<<"Infix = "<<s<<"\nPrefix = "<<ans;
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
	// obj.largest_rectangle_with_all_ones(v);
	// cout<<"\n\n"<<__cplusplus;
	// obj.check_get_min_sfsq();
	// obj.evaluate_postfix(obj.convert_infix_to_postfix("2^2^2^2^2"));
	// obj.convert_infix_to_prefix("a*(b+c/e)^(r*(t+s)-x)^t");
	obj.convert_infix_to_prefix("((x+y)/z-w)*u");
}