#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<string>
#define qfqqua queue_for_queue_ques_using_array
#define ll linked_list
using namespace std;
struct queue_for_queue_ques_using_array
{
	static const int n=10;
	int arr[n],front,rear;
	qfqqua()
	{
		front=rear=-1;
	}
	bool isEmpty()
	{
		return (front==-1);
	}
	int size()
	{
		if(front<=rear)
		return (rear-front+1);

		return ((n-front) + rear +1);
	}
	int get_front()
	{
		if(front!=-1)
		return arr[front];

		cout<<"\n\nError\n";
		return INT_MIN;
	}
	int get_rear()
	{
		if(rear!=-1)
		return arr[rear];
		cout<<"\n\nError\n";
		return INT_MIN;
	}
	// void enqueue(int x)
	// {
	// 	if(front==-1)
	// 	{
	// 		front++;
	// 		rear++;
	// 		arr[front]=x;
	// 	}
	// 	else if(rear<9)
	// 	{
	// 		rear++;
	// 		arr[rear]=x;
	// 	}
	// 	else
	// 	{
			
	// 		cout<<"\n\nError in inserting new element\n";
	// 	}
	// }
	// void dequeue()
	// {
	// 	if(isEmpty())
	// 	{
	// 		cout<<"\n\nError in deleting element\n";
	// 	}
	// 	else
	// 	{
	// 		for(int i=0;i<rear-1;i++)
	// 		arr[i]=arr[i+1];
	// 		rear--;
	// 		if(rear==-1) 
	// 		front=rear;
	// 	}
	// }
	// -------------------
	// Circular Array Implementation
	void enqueue(int x)
	{
		if(front==-1)
		{
			front++;
			rear++;
			arr[front]=x;
		}
		else if(((rear+1)%n)!=front)
		{
			rear++;
			rear%=n;
			arr[rear]=x;
		}
		else
		{
			cout<<"\n\nError in inserting new element\n";
		}
	}
	void dequeue()
	{
		if(isEmpty())
		{
			cout<<"\n\nError in deleting element\n";
		}
		else
		{
			front++;
			front%=n;
			if(front==rear)
			front=rear=-1;
		}
	}
};
struct linked_list
{
	int data;
	ll* next;
	ll(int x)
	{
		data=x;
	}
};
struct queue_ll
{
	ll *f, *r;
	int size;
	queue_ll()
	{
		f=r=NULL;
		size=0;
		// cout<<"just checking whether this executes or not \n";
	}
	void enqueue(int data)
	{
		ll *x=new ll(data);
		if(f==NULL)
		{
			f=r=x;
		}
		else
		{
			r->next=x;
			r=r->next;
		}
		size++;
	}
	void dequeue()
	{
		ll *x=f;
		if(f==NULL)
		{
			cout<<"Error : Nothing present to delete\n";
			return;
		}
		else if(f==r)
		{
			f=r=NULL;
		}
		else
		{
			f=f->next;
		}
		delete x;
		size--;
	}
	int get_node_data(ll *x)
	{
		if(x==NULL)
		{
			cout<<"Error : Null Pointer\n";
			return INT_MIN;
		}
		else
		return x->data;
	}
};
struct stack_using_queue
{
	queue_ll st;
	int size()
	{
		return st.size;
	}
	void push(int x)
	{
		st.enqueue(x);
	}
	int top()
	{
		return st.get_node_data(st.r);
	}
	void pop()
	{
		queue_ll q_temp;
		while(st.size!=1)
		{
			q_temp.enqueue(st.get_node_data(st.f));
			st.dequeue();
		}
		st.dequeue();
		st=q_temp;
	}
};
class QueueQuestions
{
	public:
	void reverse_queue(queue_ll &q)
	{
		if(q.size!=0)
		{
			int x=q.f->data;
			q.dequeue();
			reverse_queue(q);
			q.enqueue(x);
		}
		// return q;
	}
	void generate_numbers(int n, vector<int> v)
	{
		queue<string> q;
		for(auto it : v)
		q.push(to_string(it));
		for(int i=0;i<n;i++)
		{
			string s=q.front();
			cout<<s<<"\t";
			q.pop();
			// q.push(s+"5");
			// q.push(s+"6");
			for(auto it : v)
			q.push(s + to_string(it));
		}
	}
};
int main()
{
	// qfqqua q;
	// for(int i=0; i<11;i++)
	// {
	// 	q.enqueue((i+i*3 + 17));
	// 	cout<<"\nFront = "<<q.get_front()<<"\t"<<q.front<<"\tRear = "<<q.get_rear()<<"\t"<<q.rear;
	// }
	// for(int i=0; i<5;i++)
	// {
	// 	// q.enqueue((i+i*3 + 17));
	// 	cout<<"\nFront = "<<q.get_front()<<"\t"<<q.front<<"\tRear = "<<q.get_rear()<<"\t"<<q.rear;
	// 	q.dequeue();
	// }
	// for(int i=0; i<3;i++)
	// {
	// 	q.enqueue((i+i*3 + 17));
	// 	cout<<"\nFront = "<<q.get_front()<<"\t"<<q.front<<"\tRear = "<<q.get_rear()<<"\t"<<q.rear;
	// }
	// queue_ll q;
	// for(int i=0; i<11;i++)
	// {
	// 	q.enqueue((i+i*3 + 17));
	// 	cout<<"\nFront = "<<q.f->data<<"\tRear = "<<q.r->data;
	// }
	// cout<<"\n\n\n\n";
	// for(int i=0; i<12;i++)
	// {
	// 	q.dequeue();
	// 	cout<<"\nFront = "<<q.get_node_data(q.f)<<"\tRear = "<<q.get_node_data(q.r);
	// }
	// stack_using_queue st;
	// for (int i = 0; i < 10; i++)
	// {
	// 	st.push((i^6) * i +13);
	// 	cout<<"\nTop = "<<st.top();
	// }
	// cout<<"\n\n\n\n";
	// for (int i = 0; i < 5; i++)
	// {
	// 	// st.push((i^6) * i +13);
	// 	st.pop();
	// 	cout<<"\nTop = "<<st.top();
	// }
	// queue_ll q;
	// for(int i=0; i<11;i++)
	// {
	// 	q.enqueue((i+i*3 + 17));
	// 	cout<<"\nFront = "<<q.f->data<<"\tRear = "<<q.r->data;
	// }
	QueueQuestions obj;
	// obj.reverse_queue(q);
	// cout<<"\n\n\n\n";
	// for(int i=0; i<6;i++)
	// {
	// 	q.dequeue();
	// 	cout<<"\nFront = "<<q.get_node_data(q.f)<<"\tRear = "<<q.get_node_data(q.r);
	// }
	vector<int> v= {0,1,2};
	obj.generate_numbers(59,v);
}