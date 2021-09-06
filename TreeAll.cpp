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
	int curr=0;
	int max_diameter=0;
	int burn_leaf=-1;
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
	int size_of_binary_tree(tftq *root)
	{
		if(root==NULL)
		return 0;

		return (1+size_of_binary_tree(root->left)+size_of_binary_tree(root->right));
	}
	tftq *create_binary_tree()
	{
		char ch;
		int d,x;
		cout<<"Data : ";
		cin>>d;
		tftq *root=new tftq(d);
		// cout<<"\nEnter more[y/n] : ";
		// cin>>ch;
		cout<<"No. of more nodes : ";
		cin>>x;
		while(x-- )
		{
			// cout<<"\nData : ";
			cin>>d;
			tftq *temp=new tftq(d);
			insert_node_in_binary_tree(root,temp);
			// cout<<"\nEnter more[y/n] : ";
			// cin>>ch;
		}
		return root;
	}
	void insert_node_in_binary_tree(tftq *root,tftq *temp)
	{
		// if(root->left==NULL && root->right==NULL)
		// {
		if(temp->data >= root->data && root->right==NULL)
		{
			root->right=temp;
		}
		else if(temp->data >= root->data && root->right!=NULL)
		{
			insert_node_in_binary_tree(root->right,temp);
		}
		else if(temp->data < root->data && root->left==NULL)
		{
			root->left=temp;
		}
		else if(temp->data < root->data && root->left!=NULL)
		{
			insert_node_in_binary_tree(root->left,temp);
		}
		// }
	}
	int maximum_element_in_binary_tree(tftq *root)
	{
		if(root == NULL)
		{
			return INT_MIN;
		}
		return max(root->data,max(maximum_element_in_binary_tree(root->left),maximum_element_in_binary_tree(root->right)));
	}
	void left_view_of_binary_tree(tftq *root)
	{
		queue<tftq * > q;
		q.push(root);
		while(!q.empty())
		{
			int n=q.size();
			for(int i=0;i<n;i++)
			{
				if(i==0)
				{
					cout<<q.front()->data<<"\t";
				}
				if(q.front()->left)
				{
					q.push(q.front()->left);
				}
				if(q.front()->right)
				{
					q.push(q.front()->right);
				}
				q.pop();
			}
		}
	}
	void right_view_of_binary_tree(tftq *root)
	{
		queue<tftq * > q;
		q.push(root);
		while(!q.empty())
		{
			int n=q.size();
			for(int i=0;i<n;i++)
			{
				if(i==(n-1))
				{
					cout<<q.front()->data<<"\t";
				}
				if(q.front()->left)
				{
					q.push(q.front()->left);
				}
				if(q.front()->right)
				{
					q.push(q.front()->right);
				}
				q.pop();
			}
		}
	}
	int check_for_balanced_tree(tftq *root)
	{
		if(root==NULL)
		return 0;
		
		int l=check_for_balanced_tree(root->left);
		if( l==-1 )
		return -1;

		int r=check_for_balanced_tree(root->right);
		if( r==-1 )
		return -1;

		if(abs(l-r)>1)
		return -1;

		return (max(l,r)+1);
		// return (height_of_binary_tree(root->left)-height_of_binary_tree(root->right))
	}
	int maximum_width(tftq *root)
	{
		if(root == NULL)
		return 0;
		queue<tftq *> q;
		q.push(root);
		int ans=q.size();
		while(!q.empty())
		{
			int n=q.size();
			ans=max(n,ans);
			for(int i=0;i<n;i++)
			{
				tftq *temp=q.front();
				q.pop();
				if(temp->left)
				q.push(temp->left);
				if(temp->right)
				q.push(temp->right);
			}
		}
		return ans;
	}
	tftq *create_binary_tree_from_in_and_pre(int in[],int pre[], int l,int h)
	{
		if(l>h)
		return NULL;
		
		tftq *temp = new tftq(pre[curr++]);
		int i=l;
		while(i<=h && in[i]!=temp->data)
		i++;
		// if(i>h)
		// return NULL;
		temp->left= create_binary_tree_from_in_and_pre(in,pre,l,i-1);
		temp->right = create_binary_tree_from_in_and_pre(in,pre,i+1,h);
		return temp;
	}
	void spiral_tree_traversal(tftq *root)
	{
		stack<tftq *> st;
		stack<tftq *> q;
		// queue<tftq *> q;
		q.push(root);
		int lvl=1;
		while(!q.empty() || !st.empty())
		{
			// int n=q.size();
			// for (int i = 0; i < n; i++)
			// {
			// 	tftq *t=q.front();
			// 	q.pop();
			// 	if(lvl%2) // odd
			// 	cout<<t->data<<"\t";
			// 	else
			// 	st.push(t->data);
			// 	if(t->left)
			// 	q.push(t->left);
			// 	if(t->right)
			// 	q.push(t->right);
			// }
			// if(!(lvl%2))
			// {
			// 	while (!st.empty())
			// 	{
			// 		cout<<st.top()<<"\t";
			// 		st.pop();
			// 	}	
			// }
			// Printing done at last takes extra time
			if(lvl%2) // odd
			{
				while (!q.empty())
				{
					tftq *t=q.top();
					q.pop();
					cout<<t->data<<"\t";
					if(t->left)
					st.push(t->left);
					if(t->right)
					st.push(t->right);
				}
			}
			else //even
			{
				while (!st.empty())	
				{
					tftq *t=st.top();
					st.pop();
					cout<<t->data<<"\t";
					if(t->right)
					q.push(t->right);
					if(t->left)
					q.push(t->left);
				}
			}
			lvl++;
		}
	}
	int diameter_of_the_tree(tftq *root)
	{
		if(root==NULL)
		return 0;
		int l=diameter_of_the_tree(root->left);
		int r=diameter_of_the_tree(root->right);
		max_diameter=max(max_diameter,(l+r+1));
		return (max(l,r)+1);
	}
	// This function stores in the vector the path of reaching node n1 in reverse order.
	bool least_common_ancestor_naive_solution(tftq *root,tftq *n1,vector<tftq *> &v)
	{
		if(root==NULL)
		return false;

		if(root==n1 || least_common_ancestor_naive_solution(root->left,n1,v) || least_common_ancestor_naive_solution(root->right,n1,v))
		{
			v.push_back(root);
			return true;
		}
	}
	tftq * least_common_ancestor_better_solution(tftq *root,tftq *n1,tftq *n2)
	{
		if(root==NULL)
		return NULL;
		if(root==n1 || root==n2)
		return root;
		tftq * x1=least_common_ancestor_better_solution(root->left,n1,n2);
		tftq * x2=least_common_ancestor_better_solution(root->right,n1,n2);
		if((x1==n1 && x2==n2) || (x1==n2 && x2==n1))
		return root;

		if(!x1 && x2)
		return x2;

		if(x1 && !x2)
		return x1;

		return NULL;
	}
	int burn_binary_tree_from_given_leaf(tftq *root, tftq *burn, int &dist)
	{
		if(root==NULL)
		return 0;
		if(root == burn)
		{
			dist=0;
			return 1;
		}
		
		int ld,rd;
		ld=rd=-1;
		// ld = distance from the given burning starting point if it exixts 
		// in the left subtree || rd similarly for right subtree

		// lht = height of left subtree
		// rht =  "      " right  "
		int lht=burn_binary_tree_from_given_leaf(root->left,burn,ld);
		int rht=burn_binary_tree_from_given_leaf(root->right,burn,rd);

		if(ld!=-1)
		{
			// if burn exixts in left subtree
			dist=ld+1;
			burn_leaf=max(burn_leaf,(dist+rht));
		}
		else if(rd!=-1)
		{
			// if burn exixts in right subtree
			dist=rd+1;
			burn_leaf=max(burn_leaf,(dist+lht));
		}

		return (max(lht,rht)+1);
		
	}
	int count_nodes_in_binary_tree_noob(tftq* root)
	{
		if(root==NULL)
		return 0;
		
		return (1+count_nodes_in_binary_tree_noob(root->right)+count_nodes_in_binary_tree_noob(root->left));
	}
	int count_nodes_in_complete_binary_tree(tftq* root)
	{
		int l=1;
		tftq *temp=root->left;
		while(temp!=NULL)
		{
			temp=temp->left;
			l++;
		}
		int r=1;
		temp=root->right;
		while(temp!=NULL)
		{
			temp=temp->right;
			r++;
		}
		if(l==r)
		return (pow(2,l)-1);

		return (count_nodes_in_complete_binary_tree(root->left) + count_nodes_in_complete_binary_tree(root->right) +1);

	}
	void serialization(tftq *root,vector<int> &v)
	{
		queue<tftq *>q;
		q.push(root);
		while (!q.empty())
		{
			int n=q.size();
			for(int i=0;i<n;i++)
			{
				tftq *temp=q.front();
				q.pop();
				if(temp==NULL)
				{
					v.push_back(-1);
				}
				else
				{
					v.push_back(temp->data);
					// if(temp->left || temp->right)
					// {
						q.push(temp->left);
						q.push(temp->right);
					// }
				}
			}
		}
		
	}
	tftq *deserialization(vector<int>&v )
	{
		if(v[0]==-1)
		return NULL;

		tftq *root=new tftq(v[0]);
		queue<tftq *>q;
		q.push(root);
		int i=1;
		while(!q.empty())
		{
			int n=q.size();
			for (int j = 0; j < n; j++)
			{
				tftq *temp=q.front();
				q.pop();
				if(temp==NULL)
				continue;
				if(v[i]==-1)
				{
					temp->left=NULL;
				}
				else
				{
					temp->left=new tftq(v[i]);
				}
				i++;
				if(v[i]==-1)
				{
					temp->right=NULL;
				}
				else
				{
					temp->right=new tftq(v[i]);
				}
				q.push(temp->left);
				q.push(temp->right);
				i++;
			}
			
		}
		return root;

	}
};
int main()
{
	// tftq *root=new tftq(10);
	// root->left=new tftq(20);
	// root->right=new tftq(5);
	// root->left->left=new tftq(30);
	// root->left->right=new tftq(18);
	// root->left->right->left=new tftq(19);
	TreeQuestions obj;
	// obj.tree_traversal_inorder(root);
	// cout<<"\n\n\n";
	// obj.tree_traversal_postorder(root);
	// cout<<"\n\n\n";
	// obj.tree_traversal_preorder(root);
	// cout<<"Height = "<<obj.height_of_binary_tree(root);
	// obj.print_nodes_at_k_distance(root,obj.height_of_binary_tree(root)-1);
	// obj.level_order_traversal(root);
	// obj.level_order_traversal_line_by_line(root);
	// cout<<"Size = "<<obj.size_of_binary_tree(root);
	tftq *root=obj.create_binary_tree();
	// obj.level_order_traversal(root);
	// cout<<"\n\n\n";
	obj.level_order_traversal_line_by_line(root);
	// cout<<"Size = "<<obj.size_of_binary_tree(root);
	// tftq *root1=NULL;
	// cout<<"Maximum = "<<obj.maximum_element_in_binary_tree(root1);
	// obj.left_view_of_binary_tree(root);
	// obj.right_view_of_binary_tree(root);
	// cout<<"Balanced = "<<((obj.check_for_balanced_tree(root)!=-1)?"yes":"no");
	// cout<<"Max width = "<<obj.maximum_width(root);
	// obj.tree_traversal_inorder(root);
	// cout<<"\n\n";
	// obj.tree_traversal_preorder(root);
	// int in[]={10,20,30,40,60,70,80};
	// int pre[]={10,20,30,40,60,70,80};
	// tftq *root=obj.create_binary_tree_from_in_and_pre(in,pre,0,7);
	// obj.level_order_traversal_line_by_line(root);
	// obj.tree_traversal_inorder(root);
	// cout<<"\n\n";
	// obj.tree_traversal_preorder(root);
	// obj.spiral_tree_traversal(root);
	// int x = obj.diameter_of_the_tree(root);
	// vector<tftq *>v;
	// obj.least_common_ancestor_naive_solution(root,root->left->right->right->left,v);
	// cout<<"max diameter = "<<(obj.max_diameter);
	// reverse(v.begin(),v.end());
	// for(auto it:v)
	// {
	// 	cout<<it->data<<" -> ";
	// }
	// cout<<"NULL\n";
	// tftq *lca=obj.least_common_ancestor_better_solution(root,root->left->left,root->left->right->right->left);
	// cout<<"LCA of "<<root->left->left->data <<" and "<<root->left->right->right->left->data <<" is "<<lca->data;
	// int dist=-1;
	// obj.burn_binary_tree_from_given_leaf(root,root->left->right->right->left,dist);
	// cout<<obj.burn_leaf<<"\tGiven node = "<<root->left->right->right->left->data<<"\tdist = "<<dist;
	// int x=0;
	// cout<<obj.count_nodes_in_binary_tree_noob(root);
	// cout<<obj.count_nodes_in_complete_binary_tree(root);
	
	vector<int> v;
	obj.serialization(root,v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<"\t";
	}
	cout<<"\n\n\n";

	tftq *r2d2=obj.deserialization(v);
	obj.level_order_traversal_line_by_line(r2d2);
}