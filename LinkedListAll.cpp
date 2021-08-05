#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	node *next;
	node(int x)
	{
		data=x;
		next=NULL;
	}
};
struct node_dll
{
	int data;
	node_dll *next;
	node_dll *prev;
	node_dll(int x)
	{
		data=x;
		next=NULL;
		prev=NULL;
	}
};
class LinkedListQuestions
{
	public:
	void rec_node_print(node *head)
	{
		if(head!=NULL)
		{
			cout<<head->data<<"\t";
			rec_node_print(head->next);
		}
	}
	node *insert_at_end(node * head, int val)
	{
		if(head==NULL)
		{
			node* temp=new node(val);
			head=temp;
		}
		else
		{
			node *curr,*prev;
			curr=head;
			while(curr!=NULL)
			{
				prev=curr;
				curr=curr->next;
			}
			node* temp=new node(val);
			prev->next=temp;
		}
		return head;
	}
	void print_dll(node_dll *head)
	{
		while(head!=NULL)
		{
			cout<<head->data<<"\t";
			head=head->next;
		}
	}
};
int main()
{
	LinkedListQuestions obj;
	// node *head=new node(10);
	// node *t1=new node(20);
	// node *t2=new node(30);
	// node *t3=new node(40);
	// head->next=t1;
	// t1->next=t2;
	// t2->next=t3;
	// head=obj.insert_at_end(head,50);
	// obj.rec_node_print(head);
	node_dll *head=new node_dll(10);
	node_dll *t1=new node_dll(20);
	node_dll *t2=new node_dll(30);
	node_dll *t3=new node_dll(40);
	head->next=t1;
	t1->next=t2;
	t2->next=t3;
	t3->prev=t2;
	t2->prev=t1;
	t1->prev=head;
	cout<<"Before Reverse\n";
	obj.print_dll(head);
}