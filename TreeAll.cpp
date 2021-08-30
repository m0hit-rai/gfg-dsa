#include<iostream>
#include<cmath>
#include<vector>
#include<bits/stdc++.h>
#include<string>
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
class TreeQuestions
{
	public:
	void tree_traversal_preorder(tftq *root)
	{
		if(root!=NULL)
		{
			cout<<root->data<<"\t";
			tree_traversal_preorder(root->left);
			tree_traversal_preorder(root->right);
		}
	}
	void tree_traversal_inorder(tftq *root)
	{
		if(root!=NULL)
		{
			tree_traversal_inorder(root->left);
			cout<<root->data<<"\t";
			tree_traversal_inorder(root->right);
		}
	}
	void tree_traversal_postorder(tftq *root)
	{
		if(root!=NULL)
		{
			tree_traversal_postorder(root->left);
			tree_traversal_postorder(root->right);
			cout<<root->data<<"\t";
		}
	}
	int height_of_binary_tree(tftq *root)
	{
		if(root == NULL)
		return 0;

		return (1+max(height_of_binary_tree(root->left),height_of_binary_tree(root->right)));
	}
	void print_nodes_at_k_distance(tftq *root,int k)
	{
		if(root==NULL)
		{
			return;
		}
		if(k==0)
		{
			cout<<root->data<<"\t";
			return;
		}
		print_nodes_at_k_distance(root->left,k-1);
		print_nodes_at_k_distance(root->right,k-1);
	}
	// Breadth First Search
	void level_order_traversal(tftq *root)
	{
		queue<tftq *> q;
		q.push(root);
		while(!q.empty())
		{
			tftq *temp=q.front();
			q.pop();
			cout<<temp->data<<"\t";
			if(temp->left)
			q.push(temp->left);
			if(temp->right)
			q.push(temp->right);
		}
	}
	void level_order_traversal_line_by_line(tftq *root)
	{
		int h = height_of_binary_tree(root);
		for(int i=0;i<h;i++)
		{
			print_nodes_at_k_distance(root,i);
			cout<<"\n\n";
		}
	}
};
int main()
{
	tftq *root=new tftq(10);
	root->left=new tftq(20);
	root->right=new tftq(5);
	root->left->left=new tftq(30);
	root->left->right=new tftq(18);
	root->left->right->left=new tftq(19);
	TreeQuestions obj;
	// obj.tree_traversal_inorder(root);
	// cout<<"\n\n\n";
	// obj.tree_traversal_postorder(root);
	// cout<<"\n\n\n";
	// obj.tree_traversal_preorder(root);
	// cout<<"Height = "<<obj.height_of_binary_tree(root);
	// obj.print_nodes_at_k_distance(root,obj.height_of_binary_tree(root)-1);
	// obj.level_order_traversal(root);
	obj.level_order_traversal_line_by_line(root);
}