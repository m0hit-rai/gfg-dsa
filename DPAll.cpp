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
	int num_of_ways(vector<int> &coins,int sum, int n)
	{
		// cout<<"sum = "<<sum<<"\t n = "<<n<<"\n";
		if(sum==0) return 1;
		if(n==0) return 0;

		int res=num_of_ways(coins,sum,n-1);
		if(coins[n-1]<=sum)
		res+=num_of_ways(coins,sum-coins[n-1],n);

		return res;
	}
	int num_of_ways_dp(vector<int> coins,int sum)
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
				// these lines similar to recursive soln.
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
				tail[c]=v[i];
			}
		}
		return len;
	}
	int ceilIdx(vector<int> tail,int l,int r, int x)
	{
		while(r>l)
		{
			int m=l+(r-l)/2;
			if(tail[m]>=x)
			{
				// tail[r] > x so it can be the ceil
				r=m;
			}
			else
			{
				// tail[l] < x so it can never be ceil 
				l=m+1;
			}
		}
		return r;
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
					cout<<i<<" "<<j<<" "<<k<<" "<<gap<<"\n";
					dp[i][j]=min(dp[i][j],(dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]));
				}
			}
		}
		for(auto it:dp)
		{
			for(auto itt:it)
			{
				cout<<itt<<" ";
			}
			cout<<"\n";
		}
		return dp[0][n-1];
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
	// cout<<"ans = "<<obj.num_of_ways(coins,10,coins.size());
	// cout<<"\ndp ans = "<<obj.num_of_ways_dp(coins,10);
	
	// cout<<"s1 = "<<s1<<" s2 = "<<s2<<"\n";
	// cout<<"editDistance = "<<obj.edit_distance(s2,s1);
	
	vector<int> v={3,4,2,8,10,5,1};
	cout<<"LIS = "<<obj.longest_increasing_subsequence_optimised(v);

	// vector<int>m={2 ,2 ,4 ,2 ,6};
	// cout<<obj.matrix_chain_rec(m,0,4)<<"\n"<<obj.matrix_chain_dp(m);
}