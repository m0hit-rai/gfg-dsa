#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class ImplementHash_Chaining
{
	list<int> *table;
	public:
	ImplementHash_Chaining(int size)
	{
		table= new list<int>[size];
	}
	inline int hash_func(int x)
	{
		return (x%7);
	}
	void insert()
	{
		cout<<"Enter the value : ";
		int val;
		cin>>val;
		int key=hash_func(val);
		table[key].push_back(val);
	}
	void search()
	{
		cout<<"Enter value for searching : ";
		int val;
		cin>>val;
		int key=hash_func(val);
		bool flag=false;
		for(auto it : table[key])
		{
			if(it==val)
			{
				cout<<"Found \n";
				flag=true;
			}
		}
		if(!flag)
		cout<<"Not found\n";
	}
	void del()
	{
		cout<<"Enter value for deletion : ";
		int val;
		cin>>val;
		int key=hash_func(val);
		table[key].remove(val);
	}
};
class ImplmentHash_Open_Address
{
	public:
	int *arr;
	int size;
	public:
	ImplmentHash_Open_Address(int s)
	{
		size=s;
		arr=new int[size];
		for(int i=0;i<size;i++)
		{
			arr[i]=-1;
		}
	}
	inline int h_main(int key)
	{
		return key%7;
	}
	void insert()
	{
		cout<<"Enter value for insertion : ";
		int x;
		cin>>x;
		int i=h_main(x);
		while(arr[i]>-1)
		{
			i=(i+1)%size;
		}
		arr[i]=x;
	}
	void print()
	{
		for(int i=0;i<size;i++)
		{
			cout<<arr[i]<<"\t";
		}
	}
	void del()
	{
		cout<<"Enter value for deletion : ";
		int x;
		cin>>x;
		int i=h_main(x);
		while(arr[i]!=x)
		{
			i=(i+1)%size;
		}
		arr[i]=-2;
	}
	void search()
	{
		cout<<"Enter value for searching : ";
		int x;
		cin>>x;
		int i=h_main(x);
		int first_key=h_main(x);
		while(arr[i]!=-1)
		{
			if(arr[i]==x)
			{
				cout<<"Found\n";
				return;
			}
			i=(i+1)%size;
			if(i==first_key)
				break;
		}
		cout<<"Not Found\n";
	}
};
class HashingOnline
{
	public:
	void count_distinct(int a[],int n)
	{
		// we can directly create an unordered set by array elements
		unordered_set<int> s(a,a+n);
		// for(int i=0;i<n;i++)
		// {
		// 	s.insert(a[i]);
		// }
		cout<<"Number of distinct elements : "<<s.size()<<endl;
	}
	void frequency_of_element(int a[],int n)
	{
		unordered_map<int,int> m;
		for(int i=0;i<n;i++)
		{
			m[a[i]]++;
		}
		for(auto it : m)
			cout<<it.first<<" : "<<it.second<<endl;
	}
	void intersection_of_two_arrays(int a[],int n,int b[],int m)
	{
		unordered_set<int> s;
		for(int i=0;i<n;i++)
			s.insert(a[i]);
		int count=0;
		for(int i=0;i<m;i++)
			if(s.count(b[i]))
			{
				count++;
				s.erase(b[i]);
			}
		cout<<"Intersection : "<<count<<endl;
	}
	void pair_with_given_sum(int a[],int n,int req_sum)
	{
		// If we first insert all elements and then check if the sum exists then there are 2 problems : 
		// 1. We are traversing the array twice
		// 2. If the required sum is twice of any element present in the set, we will get output as true
		// Because effective search = sr(2*a[i]-a[i]) = sr(a[i]); a[i] has been inserted already
		unordered_set<int> s;
		for(int i=0;i<n;i++)
		{	
			if(s.count((req_sum-a[i])))
			{
				cout<<"Yes\n";
				return;
			}
			s.insert(a[i]);
		}
		cout<<"No\n";
	}
	void subarray_with_zero_sum(int a[], int n)
	{
		int pref_sum=0;
		unordered_set<int> s;
		for(int i=0;i<n;i++)
		{
			// if(a[i]==0)
			// {
			// 	cout<<"Yes\n";
			// 	return;
			// }
			pref_sum+=a[i];
			// if adding 10 numbers gives you the same sum as you got by adding the first 4 numbers
			// then the last 6 numbers add upto zero
			// Eg: 1+2+3 + 5-10+6+7-4-4 +4 = 10
			// sum at 3rd element is equal to sum at 9th element hence there is a subarray that has 0 sum
			if(pref_sum==0 || s.count(pref_sum)==1)
			{
				cout<<"Yes\n";
				return;
			}
			s.insert(pref_sum);
		}
		cout<<"No\n";
	}
	void subarray_with_given_sum(int a[], int n,int req_sum)
	{
		int pref_sum=0;
		unordered_set<int> s;
		for(int i=0;i<n;i++)
		{
			// if(a[i]==0)
			// {
			// 	cout<<"Yes\n";
			// 	return;
			// }
			pref_sum+=a[i];
			if(pref_sum==req_sum || s.count(pref_sum-req_sum)==1)
			{
				cout<<"Yes\n";
				return;
			}
			s.insert(pref_sum);
		}
		cout<<"No\n";
	}
	void longest_subarray_with_given_sum(int a[], int n,int req_sum)
	{
		unordered_map<int,int> m;
		int longest_array_length=-1;
		int pref_sum=0;
		for(int i=0;i<n;i++)
		{
			pref_sum+=a[i];
			if(pref_sum==req_sum)
				longest_array_length=i+1>longest_array_length?i+1:longest_array_length ;
			else if(m.find(pref_sum-req_sum)!=m.end())
			{
				int x=(i-m[pref_sum-req_sum]);
				longest_array_length = (x>longest_array_length)?x:longest_array_length;
			}
			else
				m[pref_sum]=i;
			// cout<<"i = "<<i<<"\tlongest_array_length = "<<longest_array_length<<endl;
		}
		cout<<longest_array_length<<endl;
	}
	void longest_subarray_with_equal_0_1(int a[], int n)
	{
		unordered_map<int,int> m;
		int longest_array_length=-1;
		int pref_sum=0;
		for(int i=0;i<n;i++)
		{
			pref_sum+= a[i]?1:-1;
			if(pref_sum==0)
				longest_array_length=i+1;
			else if(m.find(pref_sum)!=m.end())
			{
				int x=(i-m[pref_sum]);
				longest_array_length = max(x,longest_array_length);
			}
			else
				m[pref_sum]=i;
		}
		cout<<longest_array_length<<endl;
	}
	// subarrays in both arrays start from same index and end at same index
	// assumtion : both arrays have same size
	void longest_subarrays_with_same_sums(int a[], int b[],int n)
	{
		unordered_map<int,int> m;
		int longest_array_length=-1;
		int pref_sum=0;
		for(int i=0;i<n;i++)
		{
			pref_sum+= a[i]-b[i];
			if(pref_sum==0)
				longest_array_length=i+1;
			else if(m.find(pref_sum)!=m.end())
			{
				int x=(i-m[pref_sum]);
				longest_array_length = max(x,longest_array_length);
			}
			else
				m[pref_sum]=i;
		}
		cout<<longest_array_length<<endl;
	}
	// may look like n^2 but it ain't
	void longest_consecutive_subsequence(int a[],int n)
	{
		unordered_set<int> s(a,a+n);
		int cnt=0,res=0;
		for(int i=0;i<n;i++)
		{
			if(s.count(a[i]-1)==0)
			{
				cnt=1;
				while(s.count(a[i]+cnt))
					cnt++;
				res=max(res,cnt);
			}
		}
		cout<<res<<endl;
	}
	void count_distinct_elements_in_window(int a[],int n,int k)
	{
		unordered_map<int,int> m;
		for(int i=0;i<k;i++)
		{
			m[a[i]]++;
		}
		cout<<m.size()<<"\t";
		for(int i=k;i<n;i++)
		{
			m[a[i-k]]--;
			if(m[a[i-k]]==0)
				m.erase(a[i-k]);
			m[a[i]]++;
			cout<<m.size()<<"\t";
		}
	}
	void print_elements_more_than_n_by_k(int a[],int n,int k)
	{
		unordered_map<int , int> m;
		for(int i=0;i,n;i++)
		{
			m[a[i]]++;
		}
		for(auto it:m)
		{
			if(it.second>(n/k))
				cout<<it.first<<"\t";
		}
	}
	void print_elements_more_than_n_by_k_modified_moore_algo(int a[],int n, int k)
	{
		unordered_map<int, int> m;
		for(int i=0;i<n;i++)
		{
			m[a[i]]++;
			if(m.size()>k-1)
			{
				for(auto it : m)
				{
					it.second--;
					if(it.second==0)
						m.erase(it.first);
				}
			}
		}
		for(auto it : m)
		{
			int count=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]==it.first)
					count++;
			}
			if(count>(n/k))
				cout<<it.first<<"\t";
		}
	}
};
int main()
{
	// ImplementHash_Chaining obj(7);
	// ImplmentHash_Open_Address obj(7);
	// obj.insert();
	// obj.insert();
	// obj.insert();
	// obj.insert();
	// obj.insert();
	// obj.insert();
	// obj.insert();
	// obj.print();
	// obj.search();
	// obj.search();
	// obj.search();
	// obj.del();
	// obj.print();
	// obj.search();
	// obj.print();
	// unordered_map<string,int> m;
	// m["2 = "]=1;
	// m["3 = "]=99;
	// m.insert({"55 = ",10101});
	// for(auto it : m)
	// 	cout<<it.first<<it.second<<endl;
	HashingOnline obj;
	int a1[10]={15,12,13,13,14,18,12,15,19,18};
	int a2[5]={10,12,12,13,14};
	int a3[5]={3,2,8,15,-8};
	int a4[7]={11,12,5,-1,-1,10,5};
	int a5[7]={15,2,8,10,-5,-8,6};
	int a6[9]={8,3,1,5,-6,6,2,2};
	int a7[15]={0,1,0,0,0,0};
	int a8[15]={1,0,1,0,0,1};
	int a9[5]={9,10,11,7,8};
	int a10[6]={10,20,10,10,30,40};
	// obj.count_distinct(a1,10);
	// obj.frequency_of_element(a1,10);
	// obj.intersection_of_two_arrays(a1,10,a2,5);
	// obj.pair_with_given_sum(a3,5,107);
	// obj.subarray_with_zero_sum(a4,7);
	// obj.subarray_with_given_sum(a5,7,3);
	// obj.longest_subarray_with_given_sum(a6,8,4);
	// obj.longest_subarray_with_equal_0_1(a7,8);
	// obj.longest_subarrays_with_same_sums(a7,a8,6);
	// obj.longest_consecutive_subsequence(a9,5);
	// obj.count_distinct_elements_in_window(a10,6,4);
}