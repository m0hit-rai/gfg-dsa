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
		if(root==NULL)
		return;
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
	tftq *get_successor(tftq *root)
	{
		root=root->right;
		while(root!=NULL && root->left!=NULL)
		{
			root=root->left;
		}
		return root;
	}
	tftq *delete_node_bst(tftq *root,int key)
	{
		if(root==NULL)
		{
			return NULL;
		}
		if(root->data > key)
		{
			root->left=delete_node_bst(root->left,key);
		}
		else if(root->data < key)
		{
			root->right = delete_node_bst(root->right,key);
		}
		else
		{
			if(root->left==NULL)
			{
				tftq *temp=root->right;
				delete root;
				return temp;
			}
			else if(root->right == NULL)
			{
				tftq *temp=root->left;
				delete root;
				return temp;
			}
			else
			{
				tftq *successor = get_successor(root);
				root->data=successor->data;
				root->right = delete_node_bst(root->right,successor->data);
			}
		}
		return root;
	}
	tftq *floor_in_a_BST(tftq *root,int key)
	{
		// RECURSIVE SOLUTION
		// if(root==NULL)
		// return NULL;
		// // cout<<root->data<<"\n";
		// tftq *temp;
		// if(root->data > key)
		// {
		// 	temp = floor_in_a_BST(root->left,key);
		// }
		// else if(root->data == key || ((root->right!=NULL) && (root->right->data>key)))
		// {
		// 	return root;
		// }
		// else
		// {
		// 	temp = floor_in_a_BST(root->right,key);
		// }

		// if(temp == NULL)
		// return root;
		// else
		// return temp;
		// -------------------------------------------
		tftq *prev=NULL;
		while(root!=NULL)
		{
			// CORRECT, BUT...
			// cout<<root->data<<"\n";
			// if(root->data > key)
			// {
			// 	prev=root;
			// 	root = root->left;
			// }
			// else if(root->data == key || ((root->right!=NULL) && (root->right->data>key) && (root->right->right==NULL) && (root->right->left==NULL)))
			// {
			// 	break;
			// }
			// else
			// {
			// 	prev=root;
			// 	root = root->right;
			// }
			// ---------------------------
			
			if(root->data == key)
			{
				return root;
			}
			else if(root->data>key)
			{
				root = root->left;
			}
			else
			{
				prev = root;
				root = root->right;
			}
		}

		// if(root)
		// return root;
		
		return prev;
	}
};
int main()
{
	BSTQuestions obj;
	tftq *root=obj.create_binary_search_tree();
	obj.level_order_traversal_line_by_line(root);
	// cout<<"Enter node to be deleted : ";
	// int x;
	// cin>>x;
	// root = obj.delete_node_bst(root,x);
	// obj.level_order_traversal_line_by_line(root);
	// --------------------------------------
	cout<<"Enter node to calculate floor : ";
	int x;
	cin>>x;
	cout<<"Answer = "<<obj.floor_in_a_BST(root,x)->data;


}