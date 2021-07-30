#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
using namespace std;
class SortingAll
{
	public:
	inline int abso(int x)
	{
		if(x<0)
		return -1*x;
		return x;
	}
	void printArr(int a[],int n,int ch=0)
	{
		if(ch) cout<<"\n-------"<<ch<<"-------"<<endl;
		for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";

		cout<<endl;
	}
	void bubble_sort(int a[],int n)
	{
		int k=0;
		printArr(a,n,k);
		for(int i=n-1;i>=0;i--)
		{
			bool swap=false;
			for(int j=0;j<i;j++)
			{
				if(a[j]<a[j+1])
				{
					int temp =a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					swap=true;
				}
				//k++;
				//printArr(a,n,k);
				
			}
			if(swap==false)//If the array has become sorted, then if condition will be false and swap will remain false and loop will break!
				break;
		}
	}
	void selection_sort(int a[],int n)
	{
		int k=0;
		printArr(a,n,k);
		for(int i=0;i<n-1;i++)
		{
			int j=i;
			for(;j<n;j++)
			{
				if(a[j]<a[i])
				{
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
				k++;
				printArr(a,n,k);
			}
		}
	}
	void insertion_sort(int a[],int n)
	{
		int k=0;
		printArr(a,n,k);
		for(int i=1;i<n;i++)
		{
			int j=i-1;
			int key=a[i];
			while(j>=0 && a[j]>key)
			{
				a[j+1]=a[j];
				j--;
			}
			a[j+1]=key;
			k++;
			printArr(a,n,k);
		}
	}
	void print_two_sorted_array(int a1[],int a2[],int n1, int n2)
	{
		int i=0,j=0;
		while(true)
		{
			if(i<n1 && j<n2)
			{
				if(a1[i]<=a2[j])
				{
					cout<<a1[i]<<"\t";
					i++;
				}
				else
				{
					cout<<a2[j]<<"\t";
					j++;
				}
			}
			else if(i<n1)
			{
				cout<<a1[i]<<"\t";
				i++;
			}
			else if(j<n2)
			{
				cout<<a2[j]<<"\t";
				j++;
			}
			else
			{
				cout<<endl;
				break;
			}
		}
	}
	void merge_sorted_subarray(int a[],int low, int mid, int high)//l,m,h are indexes
	{
		int i=low,j=mid+1,k=0;
		int merged_arr[high+1];
		while(true)
		{
			if(i<=mid && j<=high)
			{
				if(a[i]<=a[j])
				{
					merged_arr[k]=a[i];
					k++;
					i++;
				}
				else
				{
					merged_arr[k]=a[j];
					k++;
					j++;
				}
			}
			else if(i<=mid)
			{
				merged_arr[k]=a[i];
				k++;
				i++;
			}
			else if(j<=high)
			{
				merged_arr[k]=a[j];
				k++;
				j++;
			}
			else
			{
				break;
			}
		}

		for(i=low;i<=high;i++)
		a[i]=merged_arr[i-low];
	}
	void merge_sort(int a[],int low,int high)
	{
		if(low<high)
		{
			int m=low+(high-low)/2;
			merge_sort(a,low,m);
			merge_sort(a,m+1,high);
			merge_sorted_subarray(a,low,m,high);
		}
	}
	void intersection_of_sorted_arrays(int a1[],int a2[],int n1, int n2)
	{
		int i=0,j=0;
		while(i<n1 && j<n2)
		{
			if(i>0 && a1[i]==a1[i-1])
			{
				i++;
				continue;
			}
			if(a1[i]<a2[j])
			{
				i++;
			}
			else if(a2[j]<a1[i])
			{
				j++;
			}
			else
			{
				cout<<a1[i]<<"\t";
				i++;
				j++;
			}
		}
		cout<<endl;
	}
	void union_of_sorted_arrays(int a1[],int a2[], int n1,int n2)
	{		
		int i=0,j=0;
		while(true)
		{
			if(i>0 && a1[i]==a1[i-1])
			{
				i++;
				continue;
			}
			if(j>0 && a2[j]==a2[j-1])
			{
				j++;
				continue;
			}
			if(i<n1 && j<n2)
			{
				if(a1[i]<a2[j])
				{
					cout<<a1[i]<<"\t";
					i++;
				}
				else if(a2[j]<a1[i])
				{
					cout<<a2[j]<<"\t";
					j++;
				}
				else
				{
					cout<<a2[j]<<"\t";
					i++;
					j++;
				}
			}
			else if(i<n1)
			{
				cout<<a1[i]<<"\t";
				i++;
			}
			else if(j<n2)
			{
				cout<<a2[j]<<"\t";
				j++;
			}
			else
			{
				cout<<endl;
				break;
			}
		}
	}
	int count_and_merge(int a[],int low,int mid, int high)
	{
		int i=low,j=mid+1,k=0,res=0;
		int merged_arr[high+1];
		while(true)
		{
			if(i<=mid && j<=high)
			{
				if(a[i]<=a[j])
				{
					merged_arr[k]=a[i];
					k++;
					i++;
				}
				else
				{
					merged_arr[k]=a[j];
					k++;
					j++;
					res+=((mid-low+1)-i);
					//when we see an element that is in the right half and is smaller than an element of left half
					//then that r.h.e. will be smaller than all the remaining l.h.e too BECAUSE THE ARRAY IS SORTED!!
				}
			}
			else if(i<=mid)
			{
				merged_arr[k]=a[i];
				k++;
				i++;
			}
			else if(j<=high)
			{
				merged_arr[k]=a[j];
				k++;
				j++;
			}
			else
			{
				break;
			}
		}

		for(i=low;i<=high;i++)
		a[i]=merged_arr[i-low];

		return res;
	}
	int count_inversion(int a[], int low, int high)
	{
		int res=0;
		if(low<high)
		{
			int m=(low+high)/2;
			res+=count_inversion(a,low,m);
			res+=count_inversion(a,m+1,high);
			res+=count_and_merge(a,low,m,high);
		}
		return res;
	}
	//LOMUTO PARTITION
	int lomuto_partition(int a[],int l, int h)//always considering that partitioning index is h
	{
		int pivot=a[h];
		int i=l-1;
		for(int j=l;j<=(h-1);j++)
		{
			if(a[j]<pivot)
			{
				//if any element is found lesser than the pivot element, we move it to start or at 'i'th index
				i++;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		//moving pivot to the middle
		int temp=a[i+1];
		a[i+1]=a[h];
		a[h]=temp;
		// cout<<"i+1 = "<<i+1<<endl;
		// printArr(a,h+1,h);
		return (i+1);
	}
	// HOARE'S PARTITION
	int hoare_partition(int a[],int l,int h)
	{
		int pivot=a[l];
		int i=l-1,j=h+1;
		while(true)
		{
			do{
				i++;
			}while(a[i]<pivot);

			do{
				j--;
			}while(a[j]>pivot);

			if(i>=j) return j;

			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	void qsort_lomuto(int a[],int l, int h)
	{
		if(l<h)
		{
			int p=lomuto_partition(a,l,h);
			qsort_lomuto(a,l,p-1);
			qsort_lomuto(a,p+1,h);
		}
	}
	void qsort_hoare(int a[],int l,int h)
	{
		if(l<h)
		{
			int p=hoare_partition(a,l,h);
			qsort_hoare(a,l,p);
			qsort_hoare(a,p+1,h);
		}
	}
	// kth smallest element, will return the index of the element
	int kth_smallest(int a[],int n,int k)
	{
		int l=0,r=n-1;
		while(l<=r)
		{
			int p=lomuto_partition(a,l,r);
			// this returns the index of pivot, if index of pivot is equal to k-1 
			// that means k-1 elements are less than pivot, hence pivot is the kth smallest element
			// if p is greater that means kth smallest will be less than the present pivot
			// else it means kth smallest will be greater than present pivot
			if(p==(k-1))
			return p;
			else if(p>k-1)
			r=p-1;
			else
			l=p+1;
		}
		return -1;
	}
	// chocolate distribution problem
	// a has packets of chocolate, to be distributed among m children and diff btw max and min is min
	int chocolateDistri(int a[],int m,int n)
	{
		qsort_lomuto(a,0,n-1);
		int res=a[m-1]-a[0];
		for(int i=1;i<=m-n;i++)
		{
			res=min(res,a[m-i-1]-a[i]);
		}
		return res;
	}
	void sortBinaryArr(int a[],int n)// aka sort even odd array, sort +ve -ve array
	{
		int last_zero_index=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				int temp=a[i];
				a[i]=a[last_zero_index];
				a[last_zero_index]=temp;
				last_zero_index++;
			}
		}
	}
	void sort_three_type_arr(int a[],int n,int h, int l)// arr elements = 1,2,3 OR between a range [low,high]
	{
		int last_index=0;
		int h_ind,l_ind;
		for(int i=0;i<n;i++)
		{
			if(a[i]<l)
			{
				int temp=a[i];
				a[i]=a[last_index];
				a[last_index]=temp;
				last_index++;
			}
			if(a[i]==l)
			l_ind=i;
		}
		int temp=a[l_ind];
		a[l_ind]=a[last_index];
		a[last_index]=temp;
		last_index++;
		for(int i=last_index;i<n;i++)
		{
			if(a[i]>l && a[i]<h)
			{
				temp=a[i];
				a[i]=a[last_index];
				a[last_index]=temp;
				last_index++;
			}
			if(a[i]==h)
			h_ind=i;
		}
		temp=a[h_ind];
		a[h_ind]=a[last_index];
		a[last_index]=temp;
	}
	void minimum_diff(int a[],int n)
	{
		qsort_hoare(a,0,n-1);
		int res=INT_MAX;
		for(int i=1;i<n;i++)
		{
			res=min(res,abso(a[i-1]-a[i]));
		}
		cout<<"minimum_diff = "<<res;
	}
	void cycle_sort_distinct(int a[],int n)
	{
		for(int cs=0;cs<n;cs++)
		{
			int item = a[cs];
			int pos=cs;
			for(int i=cs+1;i<n;i++)
			{
				// checks the correct position of first item when the cycle starts cycle 	
				if(a[i]<item)
				pos++;
			}
			int temp=a[pos];
			a[pos]=item;
			item=a[pos];
			while(pos!=cs)
			{
				// runs until the cycle is completed and we are back at cs
				// that is when pos = cs(cycle start)
				pos=cs;
				for(int i=cs+1;i<n;i++)
				{
					if(a[i]<item)
					pos++;
				}
				int temp=a[pos];
				a[pos]=item;
				item=a[pos];
			}
		}		
	}
	// O(n+k) complexity, but if k becomes large the complexity will incerease. arr[i]<k 
	void counting_sort(int a[],int n, int k)
	{
		int i=0,j=0;
		while(i<n && j<k)
		{
			for(int l=i;(l<n && i<n);l++)
			{
				if(a[l]==j)
				{
					int temp=a[l];
					a[l]=a[i];
					a[i]=temp;
					i++;
				}
			}
			j++;
		}
	}
};
int main()
{
	SortingAll obj;
	int a1[5]={10,27,27,27,32};
	int a2[7]={20,27,27,27,32,32,83};
	int a3[15]={10,18,27,32,35,40,900,1,20,25,27,32,80,83,90};
	int a4[7]={75,9,67,91,4,55,63};
	int a5[15]={1,0,0,0,0,1,1,1,0,1,1,0,1,0,1};
	int a6[11]={75,9,67,91,4,55,63,27,25,32,33};
	int a7[15]={1,3,3,9,8,3,2,1,1,7,5,6,9,8,7};
	// obj.bubble_sort(a1,4);
	// obj.selection_sort(a1,4);
	// obj.insertion_sort(a1,4);
	// obj.print_sorted_array(a1,a2,4,7);
	// obj.merge_sorted_subarray(a3,0,6,14);
	// obj.merge_sort(a4,0,6);
	// obj.printArr(a4,7);
	// obj.intersection_of_sorted_arrays(a2,a2,7,7);
	// obj.union_of_sorted_arrays(a1,a1,5,5);
	// cout<<"Inversions = "<<obj.count_inversion(a3,0,14);
	// obj.qsort_lomuto(a3,0,14);
	// obj.printArr(a3,15,1000);
	// sort(a3,a3+15);
	// obj.printArr(a3,15,2);
	// obj.qsort_hoare(a3,0,14);
	// obj.printArr(a3,15);
	// obj.printArr(a4,7);
	// cout<<"kth smallest where k = 4 is \t"<<a4[obj.kth_smallest(a4,7,4)];
	// obj.sortBinaryArr(a5,15);
	// obj.printArr(a6,11);
	// obj.sort_three_type_arr(a6,11,63,27);
	// obj.printArr(a6,11);
	// obj.minimum_diff(a6,11);
	obj.counting_sort(a7,15,10);
	obj.printArr(a7,15);
	// char ch='z';
	// cout<<"ch = "<<ch<<endl;
	// ch++;
	// cout<<"ch = "<<ch<<endl;
	// string x="mohitkumarraianandlokcolonyfaizabadroadchinhatlucknow";
	// cout<<"ch = "<<x.length()<<endl;
}