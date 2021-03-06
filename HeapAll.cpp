#include<bits/stdc++.h>
#include<cstdlib>
#define bhmn binary_heap_min
using namespace std;
struct binary_heap_min
{
	int *a,size,cap;
	bhmn(int x)
	{
		a = new int(x);
		size=0;
		cap=x;
	}
	inline int left(int i)
	{
		return (2*i+1);
	}
	inline int right(int i)
	{
		return (2*i+2);
	}
	inline int parent(int i)
	{
		return ((i-1)/2);
	}
	void insert_array_elements(int x)
	{
		if((x+size)<=cap)
		{
			cout<<"Enter "<<x<<" elements :\n";
			while(x)
			{
				cin>>a[size++];
				x--;
			}
		}
	}
	void insert(int x)
	{
		if(size==cap)
		{
			cout<<"Overflow\n";
			return;
		}
		
		size++;
		a[size-1]=x;
		int i=size-1;
		while(i!=0 && a[parent(i)]>a[i])
		{
			int temp=a[i];
			a[i]=a[parent(i)];
			a[parent(i)]=temp;
			i=parent(i);
		}
	}
	void min_heapify(int i)
	{
		int lt=left(i),rt=right(i),smallest=i;
		if(lt<size && a[lt]<a[smallest])
		smallest=lt;
		if(rt<size && a[rt]<a[smallest])
		smallest=rt;
		if(smallest!=i)
		{
			int temp=a[i];
			a[i]=a[smallest];
			a[smallest]=temp;
			min_heapify(smallest);
		}
	}
	int extract_min()
	{
		if(size==0)
		{
			cout<<"UNDERFLOW\n";
			return INT_MIN;
		}
		else if(size==1)
		{
			size--;
			return a[0];
		}
		else
		{
			int temp=a[0];
			a[0]=a[size-1];
			a[size-1]=temp;
			size--;
			min_heapify(0);
			return temp;
		}
	}
	void change_val(int i,int val)
	{
		a[i]=val;
		while(i!=0 && a[i]<a[parent(i)])
		{

		}
	}
	void build_heap_min()
	{
		for(int i=(size-2)/2;i>=0;i--)
		min_heapify(i);
	}
	void heap_sort_dec()
	{
		int temp=size;
		build_heap_min();
		for(int i=size-1;i>=0;i--)
		{
			swap(a[0],a[i]);
			size--;
			min_heapify(0);
		}
		size=temp;
	}
};
class HeapQuestions{
	public:
	void sort_k_sorted_array(int a[],int n,int k)
	{
		// an element at index i can be present at any index 
		// from i-k to i+k in the sorted array
		
	}

};
int main()
{
	// bhmn hp(25);
	// hp.insert_array_elements(10);
	// hp.heap_sort_dec();
	// for(int i=0;i<hp.size;i++)
	// {
	// 	cout<<hp.a[i]<<"\t";
	// }
	
}