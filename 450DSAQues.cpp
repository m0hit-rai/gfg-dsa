// questions in "450 DSA by ❤️🦁" not available for solving online
#include<bits/stdc++.h>
using namespace std;
struct Job
{
	int startTime,endTime,profit;
	
};
static bool myCmpST(Job x,Job y)
{
	return x.startTime<y.startTime;
}
static bool myCmpET(Job x,Job y)
{
	return x.endTime<y.endTime;
}
static bool myCmpPr(Job x,Job y)
{
	return x.profit<y.profit;
}
class Solution
{
	vector<int>nums;
	public:
	int count_subsequence_with_product_less_than_k(vector<int> v, int k)
	{
		// nums=v;
		// vector<int> x;
		// cout<< count_subsequence_with_product_less_than_k_rec(x,k,0);
		int n=v.size();
		vector<vector<int>> dp(k+1,vector<int>(n+1,0));
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=dp[i][j-1];
				if(v[j-1]<=i)
				{
					dp[i][j]+=dp[i/v[j-1]][j-1]+1;
				}
				// else
				// {
					
				// }
			}
		}
		return dp[k][n];
	}
	// int count_subsequence_with_product_less_than_k_rec(vector<int> x,int k, int i)
	// {
	// 	// cout<<" ( "<<k<<" , "<<nums.size() <<" , "<<i<<" )\n";
	// 	if(i==((int)nums.size()))
	// 	{
	// 		int curr_prod=1;
	// 		for(auto it : x)
	// 		curr_prod*=it;
	// 		if(curr_prod<k && x.size()>=1) 
	// 		{
	// 			print_vec(x);
	// 			return 1;
	// 		}
	// 		else return 0;
	// 	}
	// 	int cnt=0;
	// 	// while(i<nums.size())
	// 	// {
	// 		cnt+=count_subsequence_with_product_less_than_k_rec(x,k,i+1);
	// 		x.push_back(nums[i]);
	// 		cnt+=count_subsequence_with_product_less_than_k_rec(x,k,i+1);
	// 	// 	i++;
	// 	// }
	// 	return cnt;
	// }
	void print_vec(vector<int>x)
	{
		for(auto it : x)
		cout<<it<<" ";
		cout<<"\n";
	}
	// Maximum subsequence sum such that no three are consecutive
	int max_sub_sum_no_3_cons_rec(vector<int>&v, int n)
	{
		if(n==2) return v[n-1]+v[n-2];
		if(n==1) return v[n-1];
		if(n<1) return 0;
		return max(v[n-1]+max_sub_sum_no_3_cons_rec(v,n-2),v[n-1]+v[n-2]+max_sub_sum_no_3_cons_rec(v,n-3));
	}
	int max_sub_sum_no_3_cons_dp(vector<int> &v)
	{
		int n=v.size();
		vector<int> dp(n+1,0);
		dp[0]=0;
		dp[1]=v[0];
		dp[2]=v[0]+v[1];
		for(int i=3;i<=n;i++)
		{
			dp[i]=max(v[i-1]+dp[i-2],v[i-1]+v[i-2]+dp[i-3]);
		}
		return dp[n];
	}
	void arrange_neg_pos_alternate(vector<int> &v)
	{
		int n=v.size();
		for(int i=0;i<n;i++)
		{
			
		}
	}
	void rotate_mat_by_90(vector<vector<int>>&mat)
	{
		int n=mat.size();
		vector<vector<int>> v(n,vector<int>(n));
		for(auto it : mat)
		{
			for(auto itt : it )
			{
				cout<<itt<<"\t";
			}
			cout<<"\n";
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				v[j][n-i-1]=mat[i][j];
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				mat[i][j]=v[i][j];
			}
		}
		cout<<"\n";
		for(auto it : mat)
		{
			for(auto itt : it )
			{
				cout<<itt<<"\t";
			}
			cout<<"\n";
		}
	}
	int findPages(int a[], int n, int m) 
    {
        //code here
        int mx=INT_MIN,mn=INT_MAX,sum=0;
        for(int i=0;i<n;i++)
        {
            mn=min(a[i],mn);
            mx=max(a[i],mx);
            sum+=a[i];
        }
        int st=mx,end=sum-mn,res;
        res=end;
        while(st<=end)
        {
            int c_stu=1,curr=0,mid=(st+end)>>2;
            cout<<st<<" "<<end<<" "<<mid<<" "<<res;
            for(int i=0;i<n;i++)
            {
                // cout<<a[i]<<" "<<curr<<"\n";
                if((curr+a[i])>mid)
                {
                    curr=0;
                    c_stu++;
                    if(c_stu>m) break;
                }
                curr+=a[i];
            }
            cout<<" "<<c_stu<<"\n";
            if(c_stu==m) 
            {
                end=mid-1;
                res=min(res,mid);
            }
			else if(c_stu<m)
			{
				end=mid-1;
			}
            else
            {
                st=mid+1;
            }
        }
        return res;
	}
	void jobScheduling()
	{
		int n;
		cout<<"Enter n : ";
		cin>>n;
		Job arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i].startTime>>arr[i].endTime>>arr[i].profit;
		}
		sort(arr,arr+n,myCmpST);
		int mx=INT_MIN;
		for(int i=0;i<n;i++)
		{
			mx=max(mx,jobSchedulingRec(arr,n,i));
		}
		cout<<mx;
	}
	int jobSchedulingRec(Job arr[],int n,int i)
	{
		int next_startTime=i;
		while(arr[i].startTime==arr[next_startTime].startTime)next_startTime++;
		int ans=INT_MIN;
		while(i<next_startTime)
		{
			int j=next_startTime;
			while(j<n)
			{
				if(arr[i].endTime<arr[j].startTime)
				ans+=max(ans,arr[i].profit+jobSchedulingRec(arr,n,j));
			}
		}
		return ans;
	}
	// Function to find Number of customers who could not get a computer
	void customer_unsatisfied()
	{
		string customers;
		cin>>customers;
		int computers;
		cin>>computers;
		unordered_set<char> current_customers,unsatisfied;
		for(int i=0;i<customers.length();i++)
		{
			if(current_customers.count(customers[i]) && unsatisfied.count(customers[i])==0)
			{
				current_customers.erase(customers[i]);
				computers++;
			}
			else if(current_customers.count(customers[i])==0 && unsatisfied.count(customers[i])==0)
			{
				if(computers>=1)
				{
					computers--;
					current_customers.insert(customers[i]);
				}
				else
				{
					unsatisfied.insert(customers[i]);
				}
			}
		}
		cout<<"Unsatisfied Customers = "<<unsatisfied.size();
	}
};
int main()
{
	Solution obj;
	// vector<int> v={1, 2, 3, 4};
	// cout<<obj.count_subsequence_with_product_less_than_k(v,10);

	// vector<int> v={2, 1, 3};
	// cout<<obj.max_sub_sum_no_3_cons_rec(v,v.size())<<"\n"<<obj.max_sub_sum_no_3_cons_dp(v);

	// vector<vector<int>> v = {{1,2,3,10}
	// 				,{4,5,6,11}
	// 				,{7,8,9,12}
	// 				,{13,14,15,16}};
	// obj.rotate_mat_by_90(v);

	// int arr[]={12,34,67,90};
	// obj.findPages(arr,4,2);

	// obj.jobScheduling();

	obj.customer_unsatisfied();
}
