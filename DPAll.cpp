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
	int num_of_coins(vector<int> &coins,int sum, int n)
	{
		// cout<<"sum = "<<sum<<"\t n = "<<n<<"\n";
		if(sum==0) return 1;
		if(n==0) return 0;

		int res=num_of_coins(coins,sum,n-1);
		if(coins[n-1]<=sum)
		res+=num_of_coins(coins,sum-coins[n-1],n);

		return res;
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
};
int main()
{
	DPQuestions obj;
	// string s1="axxbce",s2="aadbbxxc";
	// vector<vector<int>>memo_lcs(s1.length()+1,vector<int>(s2.length()+1,-1));
	// cout<<"Ans = "<<obj.lcs(memo_lcs,s1,s2,s1.length(),s2.length());
	// cout<<"LCS of \""<<s1<<"\" and \""<<s2<<"\" is of length = "<<obj.lcs_tabulation(s1,s2);
	// obj.lcs_tabulation(s1,s2);
	// vector<int> coins={5,2,3,6};
	// cout<<"ans = "<<obj.num_of_coins(coins,10,coins.size());


	vector<int>m={2,3,4,5,6};
	cout<<obj.matrix_chain_rec(m,0,4);
}