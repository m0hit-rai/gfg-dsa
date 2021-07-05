#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<bool> arr((n+1),true);
	int i=2;
	cout<<"Prime Numbers are : \n";
	while(i<=n)
	{
		if(arr[i]==true)
		{
	
			cout<<i<<"\t";
			for(int j=i*i;j<=n;j+=i)
			{
				arr[j]=false;
			}
		}
		i++;
	}
}