#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	/*int len=(int)sqrt(n);
	int div[3*len]{0};
	int count=0;
	for(int i=1;i<=len;i++)
	{
		if(n%i == 0)
		{
			div[count]=i;
			if(i != n/i)
			{
				count++;
				div[3*len-count]=n/i;
			}
		}
	}
	cout<<"DIVISORS : \n";
	for(int i=0;i<3*len;i++)
	{
		if(div[i]!=0)
		cout<<div[i]<<"\t";
	}*/
	cout<<"Divisors :\n";
	int i=1;
	for(;i*i<n;i++)//in perfect squares this works until 1 less than the sqrt
	{
		if(n%i == 0)
		cout<<i<<"\t";
	}
	for(;i>=1;i--)//in perfect squares this prints from the sqrt till the N
	{
		if(n%i == 0)
		cout<<(n/i)<<"\t";
	}
}