/*
ALL PROGRAMS OF ARRAY TAUGHT IN GFG DSA COURSE BY SANDEEP JAIN
*/
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
using namespace std;
class ArrFn 
{
	public:
	void printArr(int a[],int n,int ch=0)
	{
		if(ch==1)
		cout<<"OLD : \n";
		else
		cout<<"NEW : \n";

		for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";

		cout<<endl;
	}
	int * left_shift_by_d_naive(int a[],int d,int n)
	{
	//O(n) time 
	//O(d) space
		int temp[d];
		for(int i=0;i<d;i++)
		{
			temp[i]=a[i];
		}
		for(int i=(d);i<n;i++)
		{
			a[(i-d)]=a[i];
		}
		for(int i=(n-d);i<n;i++)
		{
			a[i]=temp[i+d-n];
		}
		return a;
	}
	int * left_shift_by_d_efficient(int a[],int d,int n)
	{
	//O(n) time
	//O(1) space
		a=reverse_arr(a,0,d-1);
		a=reverse_arr(a,d,n-1);
		a=reverse_arr(a,0,n-1);
		return a;
	}
	int * reverse_arr(int a[],int low, int high)
	{
		while(low<high)
		{
			int temp=a[low];
			a[low]=a[high];
			a[high]=temp;
			low++;
			high--;
		}
		return a;
	}
	void leaders_of_array(int a[],int n)
	{
		int max=a[n-1];
		cout<<max<<"\t";
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>max)
			{
				max=a[i];
				cout<<max<<"\t";
			}
		}
	}
	void max_diff(int a[],int n)
	{
		int res=a[0]-a[1];
		int minval=a[0];
		for(int i=0;i<n;i++)
		{
			res=max(res,a[i]-minval);
			minval=min(minval,a[i]);
		}
		cout<<"Max diff = "<<res<<endl;
	}
	void freq_sorted_arr(int a[],int n)
	{
		int count=0,last_distinct_element=a[0];
		for(int i=0;i<n;i++)
		{
			if(last_distinct_element==a[i])
			{
				count++;
				continue;
			}
			cout<<last_distinct_element<<"\t"<<count<<endl;
			count=1;
			last_distinct_element=a[i];
		}
		cout<<a[n-1]<<"\t"<<count<<endl;
	}
	void stock_buy_sell(int a[],int n)
	{
		/*MY APPROACH, CORRECT BUT IMPLEMENTATION IS WROBNG i.e. TOO MUCH CALCULATION
		int temp_res=a[1]-a[0];
		int res=0;
		int min_val=a[0];
		for(int i=1;i<n;i++)
		{
			if(min_val>a[i])
			{
				min_val=a[i];
				res=res+temp_res;
				temp_res=0;
				continue;
			}
			if((a[i]-min_val)>temp_res)
			{
				temp_res=(a[i]-min_val);
			}
		}
		res=(res+temp_res);
		if(res<0)
		res=0;*/
		int res=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				res+=a[i]-a[i-1];
			}
		}
		cout<<"Max Profit : "<<res<<endl;
	}
	void trapping_rainwater(int a[],int n)
	{
		/*---------------WA----------------/*
		int temp=0,final=0,max=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
				final+=temp;
				temp=0;
				continue;
			}
			temp+=max-a[i];
		}
		if(final<0)
		final=0;*/
		int res=0;
		int lmax[n],rmax[n];

		lmax[0]=a[0];
		for(int i=1;i<n;i++)
		{
			lmax[i]=max(lmax[i-1],a[i]);
		}

		rmax[n-1]=a[n-1];
		for(int i=n-2;i>=0;i--)
		{
			rmax[i]=max(rmax[i+1],a[i]);
		}
		
		for(int i=0;i<n;i++)
		res+=min(lmax[i],rmax[i])-a[i];

		cout<<"Rainwater collected : "<<res<<endl;
	}
	void max_cons_ones(int a[],int n)
	{
		int count=0,max_c=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==0)
			count=0;
			else
			{
				count++;
				if(count>max_c)
				max_c=count;
			}
		}
		cout<<"Max Ones = "<<max_c<<endl;
	}
	int max_sum_subarray(int a[],int n)
	{
		int max_sum[n];
		max_sum[0]=a[0];
		int mx=a[0];
		for(int i=1;i<n;i++)
		{
			max_sum[i]=max((max_sum[i-1]+a[i]),a[i]);
			mx=max(max_sum[i],mx);
		}
		return mx;
		// cout<<"Max Subarray Sum = "<<mx;
	}
	void max_len_subarray(int a[],int n)
	{
		int last=a[0]%2;
		int c=1,mxc=0;
		for(int i=1;i<n;i++)
		{
			if(last==((a[i]+1)%2))
			{
				c++;
				mxc=max(c,mxc);
			}
			else
			{
				c=1;
			}
			last=a[i]%2;
		}
		cout<<"Max EVEN ODD Subarray length = "<<mxc<<endl;
	}
	int max_circular_subarray_sum(int a[],int n)
	{
		// calculate normal sum, and if it is less it means all elements are less than zero
		// so this is the correct answer
		int max_normal=max_sum_subarray(a,n);
		if(max_normal<=0)
			return max_normal;
		// now we invert the array and calculate the total sum
		int arr_sum=0;
		for(int i=0;i<n;i++)
		{
			arr_sum+=a[i];
			a[i]=-a[i];
		}
		// after inverting, the max sum of this subarray will be the min sum of the original array
		// to calulate we would subtract the min sum subarray, but as the the subarray is already -ve, we add it!
		int circu_sum=arr_sum+max_sum_subarray(a,n);
		return max(circu_sum,max_normal);

	}
	void majority_element(int arr[],int n)// appears more than n/2 times
	{
		//MOORE'S Majority Algorithm
		int res, count=1;
		for(int i=1;i<n;i++)
		{
			if(arr[res]==arr[i])
			count++;
			else
			count--;
			if(count == 0)
			{
				res =i;
				count=1;
			}
		}
		count =0;
		for(int i=0;i<n;i++)
		{
			if(arr[res] == arr[i])
			count++;
		}
		if(count <= n/2)
		cout<<"NO Majority element"<<endl;
		else
		cout<<"Majority Element = "<<arr[res]<<endl;

	}
	void min_group_flips(int arr[],int n)
	{
		int flipgrp;
		if(arr[0] == arr[n-1])
		flipgrp=(arr[0]+1)%2;
		else
		flipgrp=arr[0];

		for(int i=0;i<n;i++)
		{
			if(flipgrp == arr[i])
			{
				cout<<"from "<<i<<" to ";
				
				while(flipgrp==arr[i] && i<n)
				i++;

				cout<<(i-1)<<endl;
			}
		}
	}
	void max_sum_of_k_cons_elements(int a[],int n,int k)//a.k.a. WINDOW SLIDING TECHNIQUE
	{
		/*MY APPROACH, Perfectly correct, but requires O(n) extra space
		int sum_a[n];
		sum_a[0]=a[0];
		for(int i=1;i<n;i++)
		{
			sum_a[i]=sum_a[i-1]+a[i];
		}
		int res=sum_a[k-1];
		for(int i=k;i<n;i++)
		{
			res=max(res,(sum_a[i]-sum_a[i-k]));
		}
		cout<<"RESULT = "<<res<<endl;*/
		int curr_win=0;
		for(int i=0;i<k;i++)
		curr_win+=a[i];
		//create a window of size k, hten one element is added and one element is subtracted
		int res=curr_win;
		for(int i=k;i<n;i++)
		{
			curr_win+=a[i]-a[i-k];
			res=max(res,curr_win);
		}

		cout<<"RESULT = "<<res<<endl;
	}
	//Given an array of all non-negative ints, check is the sum of any of its subarrays is equal to a given number Using WST from above 
	void check_subarray_sum(int a[],int n, int req_sum)
	{
		int curr_win=a[0];
		int st=0,end=0;
		for(int end=1;end<n;end++)
		{
			curr_win+=a[end];
			while(curr_win>req_sum && st<end)
			{
				curr_win-=a[st];
				st++;
			}
			if(curr_win=req_sum)
			{
				cout<<"YES\n";
				return;
			}
		}
		cout<<"NO\n";
	}
	//Print M, N-bonacci numbers. N-bonacci means any element is the sum of previous N elements USING WST
	void print_n_bonacci(int m,int n)
	{
		int num[m];
		int i=0;
		for(;i<n-1;i++)
		num[i]=0;

		num[i]=1;
		i++;
		int curr_win=1;
		for(;i<m;i++)
		{
			num[i]=curr_win;
			//curr_win+=num[i]-num[i-n];
			curr_win+=num[i];
		}

		for(int i=0;i<m;i++)
		cout<<num[i]<<"\t";
	}
	int equilibriumPoint(int a[], int n)
	{
      	//calculate total sum, then create a window, check if that window is equal to the total sum minus current element
		//if yes, then return; else keep increasing the size of window and decreasing the size of total sum of the array
		int sum=0;
      	for(int i=0;i<n;i++)
      	sum+=a[i];
      	int curr_win=0;
      	for(int i=0;i<n;i++)
        	{
			if(curr_win == (sum-a[i]))
			{
		    		return (i+1);
			}
			curr_win+=a[i];
			sum-=a[i];
		}
		return -1;
	}
	void missingNumber(int arr[], int n) 
    	{ 
      	printArr(arr,n,1);
		int lspve=0;
        	for(int i=0;i<n;i++)
        	{
            	if(arr[i]>0)
            	{
				int temp=arr[lspve];
				arr[lspve]=arr[i];
				arr[i]=temp;
                		lspve++;
            	}
        	}
		cout<<"lspve = "<<lspve<<"\ta[lspve] = "<<arr[lspve]<<endl;
		printArr(arr,n,1);
        	for(int i=0;i<lspve;i++)
        	{
            	int x=abs(arr[i]);
			if((x-1)<n && (x-1)>=0 && arr[x-1]>0)
			//if((x-1)<lspve && (x-1)>=0 )
            	{	
                		
				arr[x-1]= arr[x-1]*(-1);
				//cout<<"a[i] = "<<arr[i]<<"\ta[a[i]] = "<<arr[arr[i]]<<endl;
            	}
        	}
		printArr(arr,n);
		int i;
        	for(i=0;i<lspve;i++)
        	{
            	if(arr[i]>0)
			{
				cout<<(i+1)<<endl;
				return;
			}
        	}

        	int res=max(lspve+1,i+1);
	  	cout<<(res)<<endl;
        	return;
		  
	} 
	// Given an array with both -ve and +ve int, find the max sum of a subarray
	int kadanes_algo(int arr[],int n)
	{
		int maxsum=arr[0];
		int currsum=arr[0];
		for(int i=1;i<n;i++)
		{
			currsum=max(currsum+arr[i],arr[i]);
			maxsum=max(maxsum,currsum);
		}
		return maxsum;
	}
};
int main()
{
	int arr1[7]={121,122,123,124,125,126,127};
	int arr2[7]={10,15,5,25,35,4,1};
	int arr3[7]={7,6,5,4,3,2,1};
	int arr4[5]={5,0,6,2,3};
	int arr5[20]={1,1,0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,0,1};
	int arr6[7]={-5,1,-2,3,-1,2,-2};
	int arr7[7]={-8,4,25,-118,1,20,-1};
	int arr8[5]={-1,-1,-1,-1,-1};
	int arr9 [9]={-6,7,6,6,6,6,8,9,111};
	int arr10[7]={1,4,20,3,10,5};
	int arr11[85]={-47, 1, 4, 49, -18, 10, 26, 18, -11, -38, -24, 36, 44, -11, 45, 20, -16, 28, 17, -49, 47, -48, -33, 42, 2, 6, -49, 30, 36, -9, 15, 39, -6, -31, -10, -21, -19, -33, 47, 21, 31, 25, -41, -23, 17, 6, 47, 3, 36, 15, -44, 33, -31, -26, -22, 21, -18, -21, -47, -31, 20, 18, -42, -35, -10, -1, 46, -27, -32, -5, -4, 1, -29, 5, 29, 38, 14, -22, -9, 0, 43, -50, -16, 14, -26};
	int arr12[4]={7,4,0,9};
	ArrFn obj;
	//obj.printArr(arr,7,1);
	//obj.left_shift_by_d_naive(arr,4,7);
	//obj.left_shift_by_d_efficient(arr,4,7);
	//obj.printArr(arr,7);
	//obj.leaders_of_array(arr,7);
	//obj.max_diff(arr,7);
	//obj.freq_sorted_arr(arr,7);
	//obj.stock_buy_sell(arr1,7);
	//obj.trapping_rainwater(arr3,7);
	//obj.max_cons_ones(arr5,20);
	//obj.max_sum_subarray(arr6,7);
	/*obj.max_len_subarray(arr1,7);
	obj.max_len_subarray(arr5,20);
	obj.max_len_subarray(arr2,7);*/
	//obj.max_circular_subarray_sum(arr7,7);
	//obj.majority_element(arr9,9);
	//obj.min_group_flips(arr5,20);
	/*obj.max_sum_of_k_cons_elements(arr7,7,3);
	obj.max_sum_of_k_cons_elements(arr6,7,3);*/
	//obj.check_subarray_sum(arr10,6,15);
	//obj.print_n_bonacci(20,7);
	//obj.missingNumber(arr11,85);
	// obj.trapping_rainwater(arr12,4);
	// cout<<"Max sum subarray = "<<obj.kadanes_algo(arr11,85);
	obj.max_circular_subarray_sum(arr7,7);
}