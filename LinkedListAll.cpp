#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
#define dll node_dll
#define cll node_cll
#define cdll node_cdll
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
struct node_cll
{
	int data;
	node_cll *next;
	node_cll(int x)
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
struct node_cdll
{
	int data;
	node_cdll *next;
	node_cdll *prev;
	node_cdll(int x)
	{
		data=x;
		next=NULL;
		prev=NULL;
	}
};
class LinkedListQuestions
{
	public:
	void rec_node_print_ll(node *head)
	{
		if(head!=NULL)
		{
			cout<<head->data<<"\t";
			rec_node_print_ll(head->next);
		}
		else
			cout<<"\n\n";
	}
	node *insert_at_end_ll(node * head, int val)
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
	dll* reverse_dll(dll *head)
	{
		if(head!=NULL)
		{
			dll *curr=head;
			while(curr!=NULL)
			{
				dll *t1=curr->next;
				curr->next=curr->prev;
				curr->prev=t1;
				if(t1==NULL)
					head=curr;
				curr=t1;
			}
			
		}
		return head;
	}
	void print_cll(cll *head)
	{
		if(head==NULL) 
		{
			cout<<"NULL\n";
			return;
		}
		cll *ptr=head;
		do
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}while(ptr!=head);
		cout<<"\n";
	}
	cll* insert_at_beg_cll(cll *head,int val)
	{
		cll* t=new cll(val);
		if(head == NULL)
		{
			t->next=t;
			return t;
		}
		else
		{
			// TAKES O(N) TIME
			// t->next=head;
			// cll* ptr=head;
			// while(ptr->next != head)
			// 	ptr=ptr->next;
			// ptr->next=t;
			// -----------
			// Insert a new node after head, swap the data of head and new nodw, return head;
			t->next=head->next;
			head->next=t;
			int sw=head->data;
			head->data=t->data;
			t->data=sw;
			return head;
		}
	}
	cll* insert_at_end_cll(cll *head,int val)
	{
		cll* t=new cll(val);
		if(head == NULL)
		{
			t->next=t;
		}
		else
		{
			// Insert a new node after head, swap the data of head and new nodw, return new node;
			t->next=head->next;
			head->next=t;
			int sw=head->data;
			head->data=t->data;
			t->data=sw;
		}
		return t;
	}
	cll* delete_head_cll(cll*head)
	{
		if(head==NULL || head->next==head) 
		{
			delete head;
			return NULL;
		}
		cll* t=head->next;
		head->data=head->next->data;
		head->next=head->next->next;
		delete t;
		return head;
	}
	cll* delete_kth_cll(cll* head, int k)
	{
		if(head==NULL || k==1)
		{
			return delete_head_cll(head);
		}
		cll* crr=head;
		for(int i=0;i<k-2;i++)
		crr=crr->next;
		cll* temp=crr->next;

		if(temp==head)
		return delete_head_cll(head);

		crr->next=crr->next->next;
		delete temp;
		return head;
	}
	void print_cdll(cdll*head)
	{
		if(head==NULL)
		{
			cout<<"NULL\n";
			return;
		}
		cdll*ptr=head;
		do
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}while(ptr!=head);
		cout<<"\n";
	}
	void print_rev_cdll(cdll*head)
	{
		if(head==NULL)
		{
			cout<<"NULL\n";
			return;
		}
		cdll*ptr=head->prev;
		do
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->prev;
		}while(ptr!=(head->prev));
		cout<<"\n";
	}
	cdll* insert_at_beg_cdll(cdll *head, int val)
	{
		cdll * temp= new cdll(val);
		if(head==NULL)
		{
			temp->next=temp;
			temp->prev=temp;
			return temp;
		}
		temp->next=head;
		temp->prev=head->prev;
		head->prev->next=temp;
		head->prev=temp;
		return temp;
	}
	node* sorted_insert_ll(node* head,int val)
	{
		node* t=new node(val);
		if(head==NULL || val<head->data )
		{
			t->next=head;
			return t;
		}
		node* ptr=head;
		while(ptr->next!=NULL && ptr->next->data<val )
		ptr=ptr->next;
		t->next=ptr->next;
		ptr->next=t;
		return head;
	}
	// Fast Poiter approach
	void middle_of_ll(node *head)
	{
		if(head==NULL)
		{
			return;
		}
		node *ptr,*ptr2;
		ptr=ptr2=head;
		while(true)
		{
			ptr2=ptr2->next;
			if(ptr2==NULL)
			{
				cout<<"MID : "<<ptr->data<<endl;
				return;
			}
			ptr=ptr->next;
			ptr2=ptr2->next;
			if(ptr2==NULL)
			{
				cout<<"MID : "<<ptr->data<<endl;
				return;
			}
		}
	}
	void print_nth_node_from_end_ll(node *head,int n)
	{
		if(head==NULL)
		return;
		node *f=head, *s=head;
		while(f && n--)
		f=f->next;
		if(n>=0)
		return;
		while(f)
		{
			f=f->next;
			s=s->next;
		}
		cout<<"Node from end : "<<s->data<<endl;
	}
	node* reverse_ll(node* head)
	{
		if(head==NULL || head->next == NULL)
		{
			return head;
		}
		node *curr=head;
		node *prev=NULL;
		while(curr!=NULL)
		{
			// if(prev && ptr && nxt)
			// cout<<"\nprev = "<<nxt->data<<"\tptr = "<<nxt->next->data<<"\tnxt = "<<nxt->next->next->data<<endl;
			// cout<<"\nCurrent Scenario : ";
			// rec_node_print_ll(curr);
			node *nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
		}
		return prev;
	}
	node* rec_reverse_ll(node* ptr,node *prev)
	{
		if(ptr==NULL)
			return prev;
		node* nxt=ptr->next;
		ptr->next=prev;
		return rec_reverse_ll(nxt,ptr);
	}
	node* remove_duplicates_ll(node* head)
	{
		if(head==NULL)
		{
			return NULL;
		}
		node* ptr=head;
		while(ptr!= NULL)
		{
			node* ptr2=ptr->next;
			while(ptr2 && ptr2->data==ptr->data)
			{
				node* temp=ptr2;
				ptr2=ptr2->next;
				delete temp;
			}
			ptr->next=ptr2;
			ptr=ptr->next;
		}
		return head;
	}
	node* rec_reverse_in_size_of_k_ll(node *head, int k)
	{
		node *curr=head, *nxt=NULL,*prev=NULL;
		int cnt=0;
		while(curr && cnt<k)
		{
			nxt=curr->next;
			curr->next=prev;
			prev=curr;
			curr=nxt;
			cnt++;
		}
		if(nxt)
		{
			node *rest_head=rec_reverse_in_size_of_k_ll(nxt,k);
			head->next=rest_head;
			/*
			Q.)}] 1->2->3->4->5->6->7, k=3
			when the first 3 nodes are rev : 3->2->1   6->4->5->7
			the head is still pointing at 1
			so we change next of 1 to 6, which is rest of the rev ll's head
			and return prev, which is pointing at 3 
			*/
		}
		return prev;
	}
	node* reverse_in_size_of_k_ll(node *head, int k)
	{
		node *curr=head,*prev_head=NULL;
		while(curr)
		{
			int c=0;
			node *rest_head=curr,*prev=NULL;
			while(curr && c<k)
			{
				node *nxt= curr->next;
				curr->next=prev;
				prev=curr;
				curr=nxt;
				c++;
			}
			if(!prev_head)
			{
				head=prev;
			}
			else
			{
				prev_head->next=prev;
			}
			prev_head=rest_head;
		}
		return head;
	}
	void loop_detect_ll(node *head)
	{
		node *slow,*fast;
		slow=fast=head;
		while(fast && fast->next)
		{
			slow=slow->next;
			fast=fast->next->next;
			if(slow==fast)
			{
				cout<<"Loop Detected \n";
				return;
			}
		}
		cout<<"Loop Not Detected \n";
	}
	node *segregate_even_odd_ll(node* head)
	{
		// node* last_even,*curr;
		// curr=last_even=head;
		// while(curr!=NULL)
		// {
		// 	if(curr->data%2 == 0)
		// 	{
		// 		int t=curr->data;
		// 		curr->data=last_even->data;
		// 		last_even->data=t;
		// 		last_even=last_even->next;
		// 	}
		// 	curr=curr->next;
		// }
		// return head;
		// ---------------
		// Above algorithm is not stable
		node *es,*ee,*os,*oe,*curr=head;
		es=ee=os=oe=NULL;
		// make two LLs, even & odd
		// maintain start and end for both
		// es,ee;os,oe = even start, end; odd start,end.
		while(curr!=NULL)
		{
			if(curr->data%2==0)
			{
				if(es)
				{
					ee->next=curr;
					ee=ee->next;
				}
				else
				{
					es=ee=curr;
				}
			}
			else
			{
				if(os)
				{
					oe->next=curr;
					oe=oe->next;
				}
				else
				{
					os=oe=curr;
				}
			}
			curr=curr->next;
		}
		if(!os||!es)
		return head;

		ee->next=os;
		oe->next=NULL;
		return es;
	}
	node* merge_sorted_ll(node* h1, node* h2)
	{
		node *a=h1,*b=h2;
		node *head,*tail;
		if(a->data <= b->data )
		{
			head=tail=a;
			a=a->next;
		}
		else
		{
			head=tail=b;
			b=b->next;
		}
		while(a && b)
		{
			if(a->data <= b->data)
			{
				tail->next=a;
				tail=a;
				a=a->next;
			}
			else
			{
				tail->next=b;
				tail=b;
				b=b->next;
			}
		}
		if(a)
			tail->next=a;
		else
			tail->next=b;
		return head;
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
	// node_dll *head=new node_dll(10);
	// node_dll *t1=new node_dll(20);
	// node_dll *t2=new node_dll(30);
	// node_dll *t3=new node_dll(40);
	// head->next=t1;
	// t1->next=t2;
	// t2->next=t3;
	// t3->prev=t2;
	// t2->prev=t1;
	// t1->prev=head;
	// cout<<"Before Reverse\n";
	// obj.print_dll(head);
	// head=obj.reverse_dll(head);
	// cout<<"\nAfter Reverse\n";
	// obj.print_dll(head);
	// cll*head=NULL;
	// for(int i=10;i<=100;i+=10)
	// {
	// 	// obj.print_cll(head);
	// 	head=obj.insert_at_end_cll(head,i);
	// }
	
	// obj.print_cll(head);
	// for(;head!=NULL;)
	// {
	// 	head=obj.delete_head_cll(head);
	// 	obj.print_cll(head);
	// }
	// head=obj.delete_kth_cll(head,11);
	// obj.print_cll(head);
	// cdll *head=NULL;
	// for(int i=10;i<=100;i+=10)
	// {
	// 	// obj.print_rev_cdll(head);
	// 	head=obj.insert_at_beg_cdll(head,i);
	// }
	// obj.print_rev_cdll(head);
	// obj.print_cdll(head);
	node *head =NULL,*h2=NULL;
	// cout<<"Enter Elements for list : ";
	for(int i=1;i<50;i+=5)
	{
		// int x;
		// cin>>x;
		// for(int j=0;j<i;j++)
		head=obj.insert_at_end_ll(head,i);
		// obj.rec_node_print_ll(head);
		// obj.middle_of_ll(head);
	}
	for(int i=20;i<31;i+=1)
	{
		h2=obj.insert_at_end_ll(h2,i);
	}
	cout<<"ORIGINAL  1 : \n";
	obj.rec_node_print_ll(head);
	cout<<"ORIGINAL  2 : \n";
	obj.rec_node_print_ll(h2);
	// obj.middle_of_ll(head);
	// obj.print_nth_node_from_end_ll(head,8);
	// head=obj.reverse_ll(head);
	// head=obj.rec_reverse_ll(head,NULL);
	// cout<<"\n\nREVERSED : \n";
	// obj.rec_node_print_ll(head);
	// head=obj.remove_duplicates_ll(head);
	// head=obj.reverse_in_size_of_k_ll(head,2);
	// head=obj.segregate_even_odd_ll(head);
	node *h3=obj.merge_sorted_ll(head,h2);
	cout<<"After Change : \n";
	obj.rec_node_print_ll(h3);
	// obj.loop_detect_ll(head);
	
}