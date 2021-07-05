#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class SearchingAlgos
{
	public:
	int b_srch(int a[],int n, int k)
	{
		int st=0,end=n-1;
		while(st<=end)
		{
			int pos=(st+end)/2;
			//cout<<
			if(a[pos] == k)
			{
				return (pos+1);
			}
			else if(a[pos]>k)
			{
				end=pos-1;
			}
			else
			{
				st=pos+1;
			}
		}
		return -1;
	}
	int rec_b_srch(int a[],int st,int end,int chk)
	{
		if(st>end)
		return -1;
		int mid=(st+end)/2;
		if(a[mid]==chk)
		return (mid+1);
		else if(a[mid]> chk)
		return rec_b_srch(a,st,mid-1,chk);
		else
		return rec_b_srch(a,mid+1,end,chk);
	}
	int first_occ(int a[],int n, int k)
	{
		int st=0,end=n-1;
		while(st<=end)
		{
			int pos=(st+end)/2;
			//cout<<
			if(a[pos] == k)
			{
				if(a[pos-1]!=k)
				return (pos+1);
				else 
				end=pos-1;
			}
			else if(a[pos]>k)
			{
				end=pos-1;
			}
			else
			{
				st=pos+1;
			}
		}
		return -1;
	}
	int rec_first_occ(int a[],int st,int end,int chk)
	{
		if(st>end)
		return -1;
		int mid=(st+end)/2;
		if(a[mid]==chk)
		{
			if(a[mid-1]!=chk)
			return (mid+1);
			else 
			return rec_first_occ(a,st,mid-1,chk);
		}
		else if(a[mid]> chk)
		return rec_first_occ(a,st,mid-1,chk);
		else
		return rec_first_occ(a,mid+1,end,chk);
	}
	int rec_last_occ(int a[],int st,int end,int chk)
	{
		if(st>end)
		return -1;
		int mid=(st+end)/2;
		if(a[mid]==chk)
		{
			if(a[mid+1]!=chk)
			return (mid+1);
			else 
			return rec_last_occ(a,mid+1,end,chk);
		}
		else if(a[mid]> chk)
		return rec_last_occ(a,st,mid-1,chk);
		else
		return rec_last_occ(a,mid+1,end,chk);
	}
	int count_occ(int a[],int n, int chk)
	{
		//return ((rec_last_occ(a,0,n,chk)-rec_first_occ(a,0,n,chk))+1);
		int last=rec_last_occ(a,0,n,chk);
		if(last<0)
		return -1;
		else
		return (last-rec_first_occ(a,0,n,chk)+1);
	}
	int sq_root_floor(int n)
	{
		int st=1,end=n,ans=-1;
		while(st<=end)
		{
			int i=(end+st)/2;
			int isq=(i*i);
			if(isq==n)
				return i;
			else if(isq>n)
				end=i-1;
			else
			{
				st=i+1;
				ans=i;
			}
			//cout<<"ans = "<<ans<<" st = "<<st<<" end = "<<end<<" i = "<<i<<" isq = "<<isq<<endl;
		}
		return ans;
	}
	int infinite_sorted_arr_srch(int a[],int n,int chk )
	{
		/*ANSWER IS CORRECT BUT THERE IS ANOTHER METHOD TO DO IT
		if(a[0]>chk)
		return -1;
		int i=pow(2,1);
		while(true)
		{
			if(a[i]==chk)
			{
				return (i+1);
			}
			else if(a[i]>chk && a[i-1]>=chk)
			{
				i=(i/2+i)/2;
			}
			else if(a[i]<chk && a[i+1]<=chk)
			{
				i=i*2;
			}
			else
			return -1;
			cout<<"i = "<<i<<endl;
		}*/
		//KNOWN AS UNBOUNDED BINARY SERACH
		if(a[0]==chk) return 0;
		
		int i=1;
		while(a[i]<chk)
		i=i*2;

		if(a[i]==chk)
		return i;

		return rec_b_srch(a,((i/2)+1),i-1,chk);//did rec because normal doesnot have starting point
	}
	int rotated_arr_b_srch(int a[],int n, int chk)
	{
		int st=0,end=n-1;
		while(st<=end)
		{
			int mid= (st+end)/2;
			if(a[mid]==chk)
			return (mid+1);
			else if(a[st]<a[mid])//this means left half is sorted
			{
				if(chk>=a[st] && chk<a[mid])//element exists between st and mid
				end=mid-1;
				else//element does not exist between st and mid
				st=mid+1;
			}
			else//left half is not sorted
			{
				if(chk>a[mid] && chk<=a[end])//element exists between mid and end
				st=mid+1;
				else//element does not exist between mid and end
				end=mid-1;
			}
		}
		return -1;
	}
	int peak_unsorted_arr(int a[], int n)
	{
		/*
		1. Every array has atleast one peak element, the elemnt that is graeter than its neighbouring two elements
		2. If we check at the mid of an array, and none of its adjecent elemnts are greater thant it, then it is the peak elemnet
		3. If one of its adjecent elemnt is greater than we will surely find one peak in that half of the array
		*/
		int st=0,end=n-1;
		while(st<=end)
		{
			int mid=(st+end)/2;
			//cout<<"mid = "<<mid<<"\ta[mid] = "<<a[mid]<<endl;
			if((mid==0 || a[mid-1]<=a[mid]) && (mid==n-1 || a[mid+1]<=a[mid]))
			return mid;
			if(mid>0 && a[mid-1]>=a[mid])
			end=mid-1;
			else
			st=mid+1;
		}
		return -1;
	}
	void particular_sum__sorted_arr(int a[],int n, int req_sum)
	{
		int st=0,end=n-1;
		while(st<end)
		{
			int curr_sum=(a[st]+a[end]);
			if(curr_sum==req_sum)
			{
				cout<<"pos "<<(st+1)<<" + "<<" pos "<<(end+1)<<endl;
				return;
			}
			
			else if(curr_sum>req_sum)
			end=end-1;
			else
			st=st+1;
		}
		cout<<"Not Present\n";
	}
	double median_of_sorted_arrays(int a[],int n, int b[], int m)
	{
		/* O(max(n,m)) time
		int i=0,j=0,k=0,temp=(n+m),last_elem;
		double sum=0.0;
		while(k<max(n,m))
		{
			if(i<n && j<m)
			{
				if(a[i]<b[j])
				{
					last_elem=a[i];
					i++;
					k++;
				}
				else
				{
					last_elem=b[j];
					j++;
					k++;
				}
			}
			if(i>n && j<m)
			{
				last_elem=b[j];
				j++;
				k++;
			}
			if(i<n && j>m)
			{
				last_elem=a[i];
				i++;
				k++;
			}
			if(k==((temp-1)/2) || k==(temp/2))
			{
				sum+=(double)(last_elem);
			}
		}
		if(temp%2==0)
		cout<<"Median = "<<(sum/2)<<endl;
		else
		cout<<"Median = "<<sum<<endl;*/

		//O(log(min(n,m))) time
		int beg1=0, end1=n;
		while(beg1<=end1)
		{
			int i=(beg1+end1)/2;
			int j=(n+m+1)/2 -i;
			cout<<"i = "<<i<<"\tj = "<<j<<endl;
			//i is the start of right side of merged array in terms of a[], similarly j is for b[]
			int min1=((i==(n-1))?50000:a[i]);
			int max1=((i==0)?-50000:a[i-1]);
			cout<<max1<<"\t"<<min1<<endl;
			int min2=((j==(m-1))?50000:b[j]);
			int max2=((j==0)?-50000:b[j-1]);
			cout<<max2<<"\t"<<min2<<endl;
			if(max1<=min2 && max2<=min1)//checks if we have reached the mid point
			{
				if((n+m)%2 == 0)
				return (((double)max(max1,max2) + min(min1,min2))/2);
				else
				return (double)max(max1,max2);
			}
			else if(max1>min2)
			end1=i-1;
			else
			beg1=i+1;
		}
	}
	void find_repeating(int arr[],int n)
	{
		int slow=arr[0]+1;
		int fast = arr[0]+1;
		do
		{
			slow=arr[slow]+1;
			fast=arr[arr[fast]+1]+1;
		}while(slow != fast);
		slow=arr[0]+1;
		while(slow != fast)
		{
			fast=arr[fast]+1;
			slow=arr[slow]+1;
		}
		cout<<"Repeating element = "<<(slow-1)<<endl;//can be fast too, as both are equal
	}
	int majority_element(int a[],int n)
	{
		int res_indx=0, count=1;
		for(int i=1;i<n;i++)
		{
			if(a[res_indx]==a[i])
			count++;
			else
			count--;
			if(count == 0)
			{
				res_indx=i;
				count=1;
			}
		}
		count=0;
		for(int i=0;i<n;i++)
		{
			if(a[res_indx]==a[i])
			{
				count++;
			}
			
		}
		if(count<=(n/2))
		{
			res_indx=-1;
		}
		// return res_indx;
		return (res_indx==-1?res_indx:a[res_indx]);
	}
	inline int abs(int x)
	{
		if (x<0) 
		return -1*(x);

		return x;
	}
    	// int minNumber(int a[], int low, int high)
    	// {
	// 	if(a[low]<a[high])
	// 	return a[low];
	// 	low++;
	// 	while(low<=high)
	// 	{
	// 		int mid=(low+high)/2;
	// 		if(a[mid-1]>a[mid])
	// 		return a[mid];
	// 		else if(a[mid]<a[high])
	// 		low=mid+1;
	// 		else
	// 		high=mid-1;
	// 	}
    	// }
};
int main()
{
	int a1[10]={10,11,12,13,14,15,17,18,19,20};
	int a2[2]={20,20};
	int a3[10]={4,5,10,11,12,20,20,20,20,300};
	int a4[10]={14,15,16,19,21,31,355,7,8,9};
	int a5[6]={2,3,4,5,100,1};
	int a6[8]={600,700,100,110,111,112,113,114};
	int a7[6]={0,2,1,3,2,2};
	int a8[10]={8,9,10,8,8,8,8,8,9,9};
	int a[93]={404,412,420,436,444,461,469,472,488,500,502,508,515,523,548,563,576,583,656,657,679,686,696,712,721,725,729,730,735,751,776,782,792,793,801,812,832,840,859,864,881,886,889,905,917,919,950,951,961,967,970,982,1,11,15,17,31,32,47,54,55,64,85,108,111,125,127,129,163,166,185,186,220,230,252,259,262,267,282,289,300,309,318,322,332,343,350,362,372,387,390,391,396};
	SearchingAlgos obj;
	int n;
	//cin>>n;
	//cout<<"Count n = "<<obj.rotated_arr_b_srch(a5,6,n)<<endl;
	//cout<<"Count n = "<<obj.rotated_arr_b_srch(a6,8,n)<<endl;
	//cout<<"SQRT(n) = "<<obj.sq_root_floor(n);
	//cout<<"Pos of n = "<<obj.peak_unsorted_arr(a4,10)<<endl;
	//obj.particular_sum__sorted_arr(a3,10,n);
	//double m=obj.median_of_sorted_arrays(a1,10,a2,2);
	//cout<<"Median = "<<m<<endl;
	// obj.find_repeating(a7,6);
	// cout<<"Major Element = "<<obj.majority_element(a8,10);
	// cout<<"Min num = "<<obj.minNumber(a,0,92);
	// cout<<"a[56] = "<<a[56];
}