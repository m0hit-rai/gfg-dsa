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
		unordered_set<int> s;
		for(int i=0;i<n;i++)
		{	
			if(s.find((req_sum-a[i]))!=s.end())
			{
				cout<<"Yes\n";
				return;
			}
			s.insert(a[i]);
		}
		cout<<"No\n";
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
	// obj.count_distinct(a1,10);
	// obj.frequency_of_element(a1,10);
	// obj.intersection_of_two_arrays(a1,10,a2,5);
	obj.pair_with_given_sum(a3,5,107);
}