#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int power(int n, int p)
{
	if(p==1)
	return n;
	else
	{
		if(p%2==0)
		return power(n,p/2)*power(n,p/2);
		else
		return power(n,p-1)*n;
	}
}
int main()
{
	int n,p;
	cin>>n>>p;
	int ans=power(n,p);
	cout<<"Ans = "<<ans;
}