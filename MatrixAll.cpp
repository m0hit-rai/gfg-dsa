#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include<vector>
#define vvint vector<vector<int>>
#define th (*this)
using namespace std;
class MatrixAll
{
	public:
	vvint v;
	int r,c;
	public:
	void insert_matrix(int m,int n)
	{
		cout<<"Enter a "<<m<<" x "<<n <<" matrix :\n";
		for(int i=0;i<m;i++)
		{
			vector<int> row;
			for(int j=0;j<n;j++)
			{
				int x;
				cin>>x;
				row.push_back(x);
			}
			v.push_back(row);
		}
		// print_matrix(v);
		r=m;
		c=n;
	}
	void print_matrix(string s="0")
	{
		if(s!="0")
		cout<<s<<endl;

		for(int i=0;i<v.size();i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				cout<<v[i][j]<<"\t";
			}
			cout<<endl;
		}
		cout<<"\n\n";
	}
	void snake_pattern()
	{
		for(int i=0;i<r;i++)
		{
			if(i%2==0)
			{
				int j=0;
				while(j<c)
				{
					cout<<v[i][j]<<"\t";
					j++;
				}
			}
			else
			{
				int j=c-1;
				while(j>=0)
				{
					cout<<v[i][j]<<"\t";
					j--;
				}
			}
		}
	}
	void boundry_traversal()
	{
		// First Row
		for(int j=0;j<c;j++)
		{
			cout<<v[0][j]<<"\t";
		}
		// last column
		for(int i=1;i<r;i++)
		{
			cout<<v[i][c-1]<<"\t";
		}
		// Last row & column
		if(c>1 && r>1)
		{
			for(int j=c-2;j>=0;j--)
			{
				cout<<v[r-1][j]<<"\t";
			}
			for(int i=r-2;i>0;i--)
			{
				cout<<v[i][0]<<"\t";
			}
		}

	}
	MatrixAll create_transpose()
	{
		// WRONG BECAUSE THIS CREATES A TEMPORARY ARRAY(or a temp obj)
		// MatrixAll obj;
		// obj.r=c;
		// obj.c=r;
		// for(int j=0;j<c;j++)
		// {
		// 	vector<int> row_new;
		// 	for(int i=0;i<r;i++)
		// 	{
		// 		row_new.push_back(v[i][j]);
		// 	}
		// 	obj.v.push_back(row_new);
		// }
		// return obj;
		for(int i=0;i<r;i++)
		{
			for(int j=i+1;j<c;j++)
			{
				int temp=v[i][j];
				v[i][j]=v[j][i];
				v[j][i]=temp;
			
			}
		}
		return *this;
	}
	MatrixAll rotate_by_90()
	{
		*this= th.create_transpose();
		for(int i=0;i<r/2;i++)
		{
			vector<int> temp=v[i];
			v[i]=v[r-i-1];
			v[r-i-1]=temp;
		}
		return *this;
	}
	void spiral_matrix()
	{
		int m=0,n=0;
		while(((2*m)<r) && ((2*n)<c))
		{
			// top row
			for(int j=n;j<c-n;j++)
			{
				cout<<v[m][j]<<"\t";
			}
			// last column
			for(int i=m+1;i<r-m;i++)
			{
				cout<<v[i][c-n-1]<<"\t";
			}
			// Bottom row & first column
			if(((c-2*n)>1) || ((r-2*m)>1))
			{
				for(int j=c-n-2;j>=n;j--)
				{
					cout<<v[r-m-1][j]<<"\t";
				}
				for(int i=r-m-2;i>m;i--)
				{
					cout<<v[i][n]<<"\t";
				}
			}
			m++;
			n++;
		}
	}
	void matrix_search(int k)
	{
		int m=0,n=c-1;
		while(m<r && n>=0 )
		{
			if(v[m][n]==k)
			{
				cout<<"Found "<<k<<" at "<<m+1<<" , "<<n+1<<endl;
				return;
			}
			else if(v[m][n]>k)
			{
				n--;
			}
			else
			{
				m++;
			}
		}
		cout<<"Not found ";
	}

};
int main()
{
	MatrixAll obj;
	obj.insert_matrix(4,4);
	obj.print_matrix("Original Mat : ");
	obj.snake_pattern();
	// obj.boundry_traversal();
	// obj=obj.create_transpose();
	// obj.print_matrix("New Matrix After Transpose  :  \n");
	// obj.rotate_by_90();
	// obj.print_matrix("New Matrix After Rotation  :  \n");
	// obj.spiral_matrix();
	// obj.matrix_search(29);
}