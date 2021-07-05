#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter the number : ";
	int n;
	cin>>n;
	int mul5=0;//,mul2=0;
	//unsigned long long int fact=1;
	/*for(int i=2;i<=n;i++)
	{
		//if( i%2 == 0)
		//mul2++;

		if(i%5 == 0)
		mul5++;

		//fact*=i;
	}*/
	//cout<<"Factorial = "<<fact<<"\nNumber of trailing zeroes = "<<min(mul2,mul5);
	for(int i=5;i<=n;i=i*5)
	{
		mul5+=n/i;
	}
	cout<<"\nNumber of trailing zeroes = "<<mul5;
}
