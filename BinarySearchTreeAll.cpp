#include<bits/stdc++.h>
#define tftq tree_for_tree_ques 
using namespace std;
struct tree_for_tree_ques
{
	int data;
	tftq *left, *right;
	tftq(int x)
	{
		data=x;
		left=right=NULL;
	}
};
class BSTQuestions
{
	public:
	tftq *create_binary_search_tree()
	{
		char ch;
		int x;
		tftq *root=NULL;
		cout<<"No. of nodes to be inserted : ";
		cin>>x;
		cout<<"Enter "<<x<<" values \n";
		while(x-- )
		{
			int d;
			cin>>d;
			root=insert_node_in_binary_search_tree(root,d);
		}
		return root;
	}
	tftq *insert_node_in_binary_search_tree(tftq *root,int key)
	{
		if(root==NULL)
		{
			tftq *temp = new tftq(key);
			return temp;
		}
		
		if(key > root->data )
		{
			root->right=insert_node_in_binary_search_tree(root->right,key);
		}
		else if(key < root->data )
		{
			root->left=insert_node_in_binary_search_tree(root->left,key);
		}
		
		return root;
	}
	void level_order_traversal_line_by_line(tftq *root)
	{
		cout<<"\n\n";
		queue<tftq *> q;
		q.push(root);
		while(!q.empty())
		{
			int n=q.size();
			for (int i = 0; i < n; i++)
			{
				tftq *temp=q.front();
				q.pop();
				cout<<temp->data<<"\t";
				if(temp->left)
				q.push(temp->left);
				if(temp->right)
				q.push(temp->right);
			}
			cout<<"\n";
		}
		cout<<"\n\n";
	}
};
int main()
{
	BSTQuestions obj;
	tftq *root=obj.create_binary_search_tree();
	obj.level_order_traversal_line_by_line(root);
}