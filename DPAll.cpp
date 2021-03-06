#include<bits/stdc++.h>
using namespace std;
class DPQuestions
{
	public:
	int lcs(vector<vector<int>>&memo,string &s1,string &s2, int m,int n)
	{
		// largest common subsequence
		// we check the last letter of strings
		// if the last letters have not already been checked we compute the value
		// the matrix looks like this initially
		// // A  B  C (->s2,n)
		// A -1 -1 -1
		// X -1 -1 -1
		// D -1 -1 -1
		//(s1,m)
		if(m==0 || n==0)
		{
			memo[m][n]=0;
		}
		if(memo[m][n]==-1)
		{
			if(s1[m]==s2[n])
			{
				// recursively calling for previous letters
				memo[m][n]=1+lcs(memo,s1,s2,m-1,n-1);
			}
			else
			{
				// recursively calling for previous letters
				// but as we don't know which two letters can match we call like this
				memo[m][n]=max(lcs(memo,s1,s2,m-1,n),lcs(memo,s1,s2,m,n-1));
			}
		}
		return memo[m][n];
	}
	int lcs_tabulation(string &s1,string &s2)
	{
		int m=s1.length(),n=s2.length();
		// first row and column are to be set as zero
		vector<vector<int>>dp(m+1,vector<int>(n+1,0));
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s1[i-1]==s2[j-1])
				// when same char is found diagonal value is taken and is
				// increased by one
				dp[i][j]=1+dp[i-1][j-1];
				else
				// otherwise the max of left and above value is taken
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<"\n";
		}
		int i=m,j=n;
		string ans="";
		while(i>0 && j>0 && dp[i][j]>0)
		{
			if(s1[i-1]==s2[j-1])
			{
				ans=s1[i-1]+ans;
				i--;
				j--;
			}
			else
			{
				if(dp[i-1][j]>dp[i][j-1])
				i--;
				else
				j--;
			}
		}
		cout<<"LCS of \""<<s1<<"\" and \""<<s2<<"\" is "<<ans;
		return dp[m][n];
	}
	int coin_change(vector<int> &coins,int sum, int n)
	{
		// cout<<"sum = "<<sum<<"\t n = "<<n<<"\n";
		if(sum==0) return 1;
		if(n==0) return 0;

		int res=coin_change(coins,sum,n-1);
		if(coins[n-1]<=sum)
		res+=coin_change(coins,sum-coins[n-1],n);

		return res;
	}
	int coin_change_dp(vector<int> coins,int sum)
	{
		int n=coins.size();
		vector<vector<int>> dp(sum+1,vector<int>(n+1,0));
		for(int i=0;i<=n;i++)
		{
			// when sum is zero, there is always one way to get the answer
			// i.e. to not pick any coins
			dp[0][i]=1;
		}
		// when number of coins is zero and if sum >=1 then 
		// there are zero ways to get the answer
		for(int i=1;i<=sum;i++)
		{
			for(int j=1;j<=n;j++)
			{
				// these lines are similar to recursive soln.

				// when no. of coins=j then there are atleast same no. of ways to
				// get the answer as there were when no. of coins was j-1
				dp[i][j]=dp[i][j-1];
				// i=curr sum
				if(coins[j-1]<=i)
				{
					// if coins[j-1] is less than curr sum then add the number of ways
					// it takes for same no. of coins after subtracting coins[j-1]
					dp[i][j]+=dp[i-coins[j-1]][j];
				}
			}
		}
		return dp[sum][n];
	}
	// convert S1 to S2 with minimum operations of replace, insert or delete
	int edit_distance(string s1,string s2)
	{
		int m=s1.size(),n=s2.size();
		vector<vector<int>>dp(m+1,vector<int>(n+1,0));
		for(int i=0;i<=m;i++)
		dp[i][0]=i;
		for(int i=0;i<=n;i++)
		dp[0][i]=i;

		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(s1[i-1]==s2[j-1])
				{
					dp[i][j]=dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
				}
			}
		}
		// for (int i = 0; i < m+1; i++)
		// {
		// 	for (int j = 0; j < n+1; j++)
		// 	{
		// 		cout<<dp[i][j]<<"\t";
		// 	}
		// 	cout<<"\n";
		// }
		
		return dp[m][n];
	}
	// LIS : longest subsequence that is sorted in increasing/ascending order
	int longest_increasing_subsequence_dp(vector<int> v)
	{
		// O(n^2)
		int n=v.size();
		// LIS of each element is atleast 1, starts with the same element 
		// and ends with the same element
		vector<int> lis(n,1);
		int res=lis[0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(v[j]<v[i])
				{
					// if element at j is less than element at i then only can we append
					// v[i] at the end of its LIS
					lis[i]=max(lis[i],1+lis[j]);
					// we search for highest LIS before i and then add 1 to it
				}
				// if there is no element smaller than i then LIS remains 1
			}
			res=max(lis[i],res);
		}
		return res;
	}
	int longest_increasing_subsequence_optimised(vector<int>v)
	{
		// O(nlog(n))
		int n=v.size();
		vector<int> tail(n);
		// tail[len] = stores the maximum possible tail value for LIS of length (len)
		// at any given index i, the value at tail[len] will be value at which lis[i] ends
		// example in copy
		int len=1;
		tail[0]=v[0];
		for (int i = 0; i < n; i++)
		{
			if(v[i]>tail[len-1])
			{
				tail[len]=v[i];
				len++;
			}
			else
			{
				int c=ceilIdx(tail,0,len-1,v[i]);
				// search a value in tail that is just greater than v[i]
				tail[c]=v[i];
			}
		}
		return len;
	}
	int ceilIdx(vector<int> tail,int st,int end, int x)
	{
		while(end>st)
		{
			int mid =st+(end-st)/2;
			if(tail[mid]>=x)
			{
				// tail[end] > x so it can be the ceil
				end=mid;
			}
			else
			{
				// tail[st] < x so it can never be ceil 
				st=mid+1;
			}
		}
		return end;
	}
	// variation of LIS
	// find the max-sum of any increasing subsequence
	int max_sum_increasing(vector<int> v)
	{
		int n=v.size();
		vector<int> msis(n);
		// for(int i=0;i<n;i++) msis[i]=v[i];
		int res=msis[0]=v[0];
		for(int i=1;i<n;i++)
		{
			msis[i]=v[i];
			for(int j=0;j<i;j++)
			{
				if(v[i]>v[j])
				{
					msis[i]=max(msis[i],v[i]+msis[j]);
				}
			}
			res=max(res,msis[i]);
		}
		return res;

	}
	int max_length_bitonic_subsequence(vector<int> v)
	{
		// O(n^2)
		// can be optimised similar to the optimisation of original LIS
		int n=v.size();
		vector<int> lis(n,1),lds(n,1);
		// lis
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(v[i]>v[j])
				{
					lis[i]=max(lis[i],1+lis[j]);
				}
			}
		}
		// lds=lis from right
		for(int i=n-2;i>=0;i--)
		{
			for(int j=n-1;j>i;j--)
			{
				if(v[i]>v[j])
				{
					lds[i]=max(lds[i],1+lds[j]);
				}
			}
		}
		int res=lis[0]+lds[0]-1;
		for(int i=1;i<n;i++)
		{
			res=max(res,(lis[i]+lds[i]-1));
		}
		return res;
	}
	int min_coins(int val,int a,int b, int c)
	{
		// Recursion
		// if(val==0)return 0;
		// if(val<0) return INT_MAX;

		// int res=min(min_coins(val-a,a,b,c),
		// 		min(min_coins(val-b,a,b,c),min_coins(val-c,a,b,c)));
		// // if()
		// if(res==INT_MAX) return res;
		// return (res+1);
		// -------------------------------------
		// DP
		vector<int>dp(val+1,INT_MAX);
		dp[0]=0;
		for(int i=1;i<=val;i++)
		{
			if((i-a)>=0)dp[i]=min(dp[i],dp[i-a]);
			if((i-b)>=0)dp[i]=min(dp[i],dp[i-b]);
			if((i-c)>=0)dp[i]=min(dp[i],dp[i-c]);
			if(dp[i]!=INT_MAX) dp[i]++;
		}
		return dp[val];
	}
	int min_jumps(vector<int>& v, int n)
	{
		// dp[i] = no. of steps to reach i starting from 0
		vector<int> dp(n,INT_MAX);
		dp[0]=0;
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if((v[j]+j)>=i && dp[j]!=INT_MAX)
				{
					// if we can reach i from j and j can be reached too 
					// then no. of steps to reach i will be one more than
					// no. of steps to reach j => dp[i]=dp[j]+1
					// but we need min jumps
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
		return dp[n-1];
	}
	int zero_one_knapsack_problem(int w,int wts[],int val[], int n)
	{
		// // here we can use one product only once
		// // not like coin, rope cutting or min jump
		// // hence we don't use a for loop to iterate over all values in recursion
		// if(n==0 || w==0) return 0;

		// if(wts[n-1] > w) 
		// // simply ignoring the wts if it is greater than the weight
		// return zero_one_knapsack_problem(w,wts,val,n-1);

		// // max of when considering curr wt and when not considering curr wt.
		// return max(zero_one_knapsack_problem(w,wts,val,n-1),
		// 		val[n-1] + zero_one_knapsack_problem(w,wts,val,n-1));
		// ---------------------------------------
		vector<vector<int>>dp(w+1,vector<int>(n+1,0));
		// base case handled
		for(int i=1;i<=w;i++)
		{
			for(int j=1;j<=n;j++)
			{
				// totally similar to Recursion
				if(wts[j-1]>i)
				{
					dp[i][j]=dp[i][j-1];
				}
				else
				{
					dp[i][j]=max(dp[i][j-1],(val[j-1]+dp[i-wts[j-1]][j-1]));
				}
			}
		}
		return dp[w][n];
	}
	int optimal_strategy(vector<int> v)
	{
		int n=v.size();
		vector<vector<int>> dp(n , vector<int>(n));
		// as two dimensions of dp are i&j and the final answer we get is when i=0 & j=n-1 so
		// our answer will be at top right corner, matrix is filled in bottom up manner
		// everytime we need elements of a diagonal below to fill current element
		// suppose i=0,j=6 then we call for (2,6),(1,5)&(0,4) acc. to recursion
		
		// and our base case is when j=i+1 i.e. when there are only two elements in the array
		for(int i=0;i<n-1;i++)
		dp[i][i+1]=max(v[i],v[i+1]);

		for(int gap=3;gap<n;gap+=2)
		{
			for(int i=0;i+gap<n;i++)
			{
				int j=i+gap;
				// we select one and give the best of remaining to opponent
				dp[i][j]=max((v[i] + min(dp[i+1][j-1],dp[i+2][j])),
						(v[j] + min(dp[i+1][j-1],dp[i][j-2])));
			}
		}
		return dp[0][n-1];
	}
	int egg_dropping_puzzle(int floor,int egg)
	{
		vector<vector<int>> dp(floor+1,vector<int>(egg+1,0));
		// eggs!=0
		for (int i = 1; i <=egg; i++)
		{
			dp[1][i]=1;
			dp[0][i]=0;
		}
		for (int i = 0; i<=floor; i++)
		{
			dp[i][1]=i;
		}
		for(int i=2;i<=floor;i++)
		{
			for(int j=2;j<=egg;j++)
			{
				// int res=INT_MAX;
				dp[i][j]=INT_MAX;
				for(int x=1;x<=i;x++)
				{
					dp[i][j]=min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
				}
				// dp[i][j]=res+1;
			}
		}
		for(auto it : dp)
		{
			for(auto i : it)
			{
				cout<<i<<"\t";
			}
			cout<<"\n";
		}
		return dp[floor][egg];
	}
	int count_BTSs(int n)
	{
		vector<int> dp(n+1,0);
		// when no nodes there is one BST that can be made
		dp[0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)
			{
				dp[i]+=dp[j]*dp[i-j-1];
			}
		}
		return dp[n];
	}
	int max_sum_with_no_consecutives(vector<int> &v,int n)
	{
		// vector<int> dp(n+1,0);
		// dp[1]=v[0];
		// dp[2]=v[1];
		// for (int i = 3; i <= n; i++)
		// {
		// 	dp[i]=max(dp[i-1],dp[i-2]+v[i-1]);
		// }
		// return dp[n];
		// --------------------------
		// Optimised Soln.
		if(n==1) return v[0];
		int prev_prev=v[0];
		int prev=max(v[0],v[1]);
		int res=prev;
		for(int i=3;i<=n;i++)
		{
			res=max(prev,prev_prev+v[i-1]);
			prev_prev=prev;
			prev=res;
		}
		return res;
	}
	int subset_sum_problem(vector<int>&v, int n, int sum)
	{
		// if(sum==0)
		// {
		// 	// for(auto it : subset)
		// 	// cout<<it<<" ";
		// 	// cout<<"\n";
		// 	return 1;
		// } 
		// if(n==0) return 0;

		// if(sum>=v[n-1])
		// {
		// 	// int x=subset_sum_problem(v,n-1,sum,subset);
		// 	// subset.push_back(v[n-1]);
		// 	// x+=subset_sum_problem(v,n-1,sum-v[n-1],subset);
		// 	// return x;
		// 	return (subset_sum_problem(v,n-1,sum)+subset_sum_problem(v,n-1,sum-v[n-1]));
		// }
		// return subset_sum_problem(v,n-1,sum,subset);

		vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
		for(int i=0;i<=n;i++)
		{
			dp[i][0]=1;
		}

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				// cout<<i<<" "<<j<<"\n";
				// dp[i][j]=0;

				if(j>=v[i-1])
				dp[i][j]=dp[i-1][j-v[i-1]] + dp[i-1][j];
				else
				dp[i][j]=dp[i-1][j];
			}
		}
		return dp[n][sum];
	}
	int matrix_chain_rec(vector<int> &arr, int i,int j)
	{
		if((i+1)==j)
		return 0;

		int res=INT_MAX;
		for(int k=i+1;k<j;k++)
		{
			// multiplying matrix between i,k the final matrix will have dimensions as (arr[i],arr[k])
			res=min(res,matrix_chain_rec(arr,i,k)+
				matrix_chain_rec(arr,k,j)+arr[i]*arr[k]*arr[j]);
			// when we have just two matrix, we can multiply their three different dimensions to know 
			// how many multiplications will be done in multiplying those two
		}
		return res;
	}
	int matrix_chain_dp(vector<int> &arr)
	{
		int n=arr.size();
		vector<vector<int>> dp(n,vector<int>(n));

		for(int i=0;i<n-1;i++) 
		{
			// here gap=1
			// gap=1 is the base case, when i+1=j
			dp[i][i+1]=0;
		}

		for(int gap=2;gap<n;gap++)
		{
			for(int i=0;(i+gap)<n;i++)
			{
				int j=i+gap;
				dp[i][j]=INT_MAX;
				for(int k=i+1;k<j;k++)
				{
					// cout<<i<<" "<<j<<" "<<k<<" "<<gap<<"\n";
					dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]));
				}
			}
		}
		// for(auto it:dp)
		// {
		// 	for(auto itt:it)
		// 	{
		// 		cout<<itt<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		return dp[0][n-1];
	}
	bool is_pall(string &s, int i, int j)
	{
		while(i<j)
		{
			if(s[i]!=s[j])
			return false;

			i++;
			j--;
		}
		return true;
	}
	int pallindrome_partitioning_rec(string &s, int i,int j)
	{
		if(i==j || is_pall(s,i,j))return 0;
		int res=INT_MAX;
		for(int k=i;k<j;k++)
		{
			res=min(res,( pallindrome_partitioning_rec(s,i,k)
					  +pallindrome_partitioning_rec(s,k+1,j)+1));
		}
		return res;
	}
	int pallindrome_partitioning_dp(string &s)
	{
		int n=s.size();
		vector<vector<int>> dp(n,vector<int>(n,INT_MAX));

		// primary diagonal i.e. where i=j is zero
		for(int i=0;i<n;i++)
		dp[i][i]=0;

		for(int gap=1;gap<n;gap++)
		{
			for(int i=0;(i+gap)<n;i++)
			{
				int j=i+gap;
				if(is_pall(s,i,j)) dp[i][j]=0;
				else
				{
					for(int k=i;k<j;k++)
					{
						dp[i][j]=min(dp[i][j],(1+dp[i][k]+dp[k+1][j]));
					}
				}
			}
		}
		return dp[0][n-1];
	}
	int arrSum(vector<int> &v, int st,int end )
	{
		int sum=v[st++];
		while(st<=end)
		{
			sum+=v[st++];
		}
		return sum;
	}
	int allocate_minimum_pages_rec(vector<int> &v,int n, int k)
	{
		if(n==1) return v[0];
		if(k==1) return arrSum(v,0,n-1);
		int res=INT_MAX;
		for(int i=1;i<n;i++)
		{
			res=min(res,max(allocate_minimum_pages_rec(v,i,k-1),arrSum(v,i,n-1)));
		}
		return res;
	}
	int allocate_minimum_pages_dp(vector<int> &v,int k)
	{
		int n=v.size();
		vector<vector<int>> dp(k+1,vector<int>(n+1,0));
		for (int i = 1; i < k+1; i++)
		{
			dp[i][1]=v[0];
			// base case 1
		}
		for (int i = 1; i < n+1; i++)
		{
			dp[1][i]=arrSum(v,0,i-1);
			// base case 2
		}
		for(int i=2;i<=k;i++)
		{
			for(int j=2;j<=n;j++)
			{
				dp[i][j]=INT_MAX;
				for(int partition=1; partition<n ; partition++)
				{
					dp[i][j]=min(dp[i][j],max(dp[i-1][partition],arrSum(v,partition,j-1)));
				}
			}
		}

		return dp[k][n];
	}
};
int main()
{
	DPQuestions obj;
	// string s1="computersecurity",s2="computerscience";
	// vector<vector<int>>memo_lcs(s1.length()+1,vector<int>(s2.length()+1,-1));
	// cout<<"Ans = "<<obj.lcs(memo_lcs,s1,s2,s1.length(),s2.length());
	// cout<<"LCS of \""<<s1<<"\" and \""<<s2<<"\" is of length = "<<obj.lcs_tabulation(s1,s2);
	// obj.lcs_tabulation(s1,s2);
	
	// vector<int> coins={5,2,3,6};
	// cout<<"ans = "<<obj.coin_change(coins,10,coins.size());
	// cout<<"\ndp ans = "<<obj.coin_change_dp(coins,10);
	
	// cout<<"s1 = "<<s1<<" s2 = "<<s2<<"\n";
	// cout<<"editDistance = "<<obj.edit_distance(s2,s1);
	
	// vector<int> v={3,4,2,8,10,5,1};
	// cout<<"LIS = "<<obj.longest_increasing_subsequence_optimised(v);

	// vector<int> v={1,11,2,10,4,5,2,1};
	// cout<<"MLBS = "<<obj.max_length_bitonic_subsequence(v);

	// cout<<"coins = "<<obj.min_coins(29,11,4,7);

	// vector<int> v={3,2,1,1,1,4,5,1};
	// cout<<"Jumps = "<<obj.min_jumps(v,v.size());

	// cout<<"Egg Dropping (f=10,e=2) = "<<obj.egg_dropping_puzzle(10,2);

	// vector<int> v={10,20,30,40,5,60,70};
	// cout<<obj.max_sum_with_no_consecutives(v,v.size());

	// vector<int> v={10,20,15,30,25,40,35};
	// vector<int> x;
	// cout<<obj.subset_sum_problem(v,v.size(),70);
	
	// vector<int>m={2 ,2 ,4 ,2 ,6};
	// cout<<obj.matrix_chain_rec(m,0,4)<<"\n"<<obj.matrix_chain_dp(m);

	// string s="aaaabababbababbbabbaabaaababbababbabbabababaaaaaaaaabbbbabababaaaababba";
	// cout<<"REC. Pallindrome partitioning for "<<s<<" : "<<obj.pallindrome_partitioning_rec(s,0,s.size()-1)<<"\n";
	// cout<<"DP Pallindrome partitioning for "<<s<<" : "<<obj.pallindrome_partitioning_dp(s)<<"\n";

	vector<int> v={1,2,3,4,5,6,2,3,7,5,6,7,8,9,1,2,3,4};
	cout<<"REC : "<<obj.allocate_minimum_pages_rec(v,v.size(),10)<<"\n";
	cout<<"DP : "<<obj.allocate_minimum_pages_dp(v,10)<<"\n";
}