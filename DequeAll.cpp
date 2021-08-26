#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<string>
#define null __null
#define ddll deque_using_doubly_linked_list
#define dll doubly_linked_list
using namespace std;
struct doubly_linked_list
{
	dll *next, *prev;
	int data;
	dll(int z)
	{
		data=z;
		next=prev=NULL;
	}
};
struct deque_using_doubly_linked_list
{
	dll *f, *r;
	int size;
	ddll()
	{
		f=r=NULL;
		size=0;
	}
	void insert_front(int x)
	{
		dll *t = new dll(x);
		if(f== NULL)
		{
			f=r=t;
		}
		else
		{
			t->next=f;
			f->prev=t;
			f=t;
		}
		size++;
	}
	void delete_front()
	{
		dll *t=f;
		if(f!=NULL)
		{
			if(r==f)
			f=r=null;
			else
			f=f->next;
			size--;
		}
		else
		{
			cout<<"\n\nError : Deleting NULL ptr\n\n";
		}
		delete t;
	}
	void insert_back(int x)
	{
		dll *t= new dll(x);
		if(r==null)
		{
			f=r=t;
		}
		else
		{
			t->prev=r;
			r->next=t;
			r=t;
		}
		size++;
	}
	void delete_back()
	{
		dll *t=r;
		if(r!=null)
		{
			if(r==f)
			f=r=null;
			else
			r=r->prev;

			size--;
		}
		else
		{
			cout<<"\n\nError : Deleting NULL ptr\n\n";
		}
		delete t;
	}
	int get_front()
	{
		if(f!=null)
		return f->data;

		cout<<"\n\nError : Accessing NULL ptr\n\n";
		return INT_MIN;
	}
	int get_rear()
	{
		if(r!=null)
		return r->data;

		cout<<"\n\nError : Accessing NULL ptr\n\n";
		return INT_MIN;
	}
};
struct petrolPump
{
    int petrol;
    int distance;
};
class DequeQues
{
	public:
	void minimum_in_all_subarray_of_size_k(vector<int> &v, int k)
	{
		deque<int> dq;
		// First window
		for(int i=0;i<k;i++)
		{
			while(!dq.empty() && v[i]>v[dq.back()])
			{
				dq.pop_back();
			}
			dq.push_back(i);
		}
		for(int i=k;i<v.size();i++)
		{
			cout<<v[dq.front()]<<"\t";
			// Checking whether front of dq in eligible to be present in the window or not
			while(!dq.empty() && dq.front()<=(i-k))
			{
				dq.pop_front();
			}
			// Same thing as first window
			while(!dq.empty() && v[i]>v[dq.back()])
			{
				dq.pop_back();
			}
			dq.push_back(i);
		}
		cout<<v[dq.front()]<<"\n\n\n\n";
	}
};
int main()
{
	// ddll dq;
	// for(int i=0; i<15;i++)
	// {
	// 	if(i%2)
	// 	dq.insert_back((i+i*3 + 17));
	// 	else
	// 	dq.insert_front((i^7 -5));
	// 	cout<<"\nFront = "<<dq.get_front()<<"\tRear = "<<dq.get_rear();
	// }
	// cout<<"\n\n\n";
	// for(int i=0; i<16;i++)
	// {
	// 	cout<<"\nFront = "<<dq.get_front()<<"\tRear = "<<dq.get_rear();
	// 	if(i%2)
	// 	dq.delete_front();
	// 	else
	// 	dq.delete_back();
		// cout<<"\nFront = "<<dq.get_front()<<"\tRear = "<<dq.get_rear();
		// dq.delete_back();
		// cout<<"\nFront = "<<dq.get_front()<<"\tRear = "<<dq.get_rear();
	// }
	// vector<int> v= {10,5,8,1,2,1,1,3,4};
	// DequeQues obj;
	// obj.minimum_in_all_subarray_of_size_k(v,3);
	
}