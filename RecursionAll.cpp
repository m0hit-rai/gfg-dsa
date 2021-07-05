#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void revRecPrint(int n)
{
	if(n==0)
	{
		return;
	}
	cout<<n<<"\t";
	revRecPrint(n-1);
}
void fwdRecPrint(int n,int k)
{
	if(n==0)
	{
		return;
	}
	//fwdRecPrint(n-1);
	cout<<k<<"\t";
	fwdRecPrint(n-1,k+1);
}
long factTailRec(int n,long fact)
{
	if(n==1)
	return fact;
	else
	{
		return factTailRec(n-1,fact*(n));
	}
}
void printFib(int n,int a, int b, int c)
{
	
	if(n==0)
	return;
	cout<<c<<"\t";
	a=b;
	b=c;
	c=a+b;
	printFib(n-1,a,b,c);
}
int nat_num_sum(int n,int k)
{
	if(n==1)
	return k;
	return nat_num_sum(n-1,k+n);
}
bool check_pall(string s)
{
	if(s.length()==1) 
	return true;
	if(s.length()==2 && s[1]==s[0])
	return true;
	else
	return false;
	if(s[0]==s[s.length()-1] && check_pall(s.substr(1,(s.length()-2))))
	return true;
	
}
int sum_of_digits(int n)
{
	if(n==0)
	return 0;
	return n%10+sum_of_digits(n/10);
}
//(INFAMOUS) Rope Cutting Problem
int pieces(int n, int a, int b, int c)
{
	if(n==0)
	return 0;
	if(n<0)
	return -1;

	int aa=pieces(n-a,a,b,c);
	int bb=pieces(n-b,a,b,c);
	int cc=pieces(n-c,a,b,c);

	if(aa<0 && bb<0 && cc<0)
	return -1;

	return 1+max(aa,max(bb,cc));
}
//(INFAMOUS) Josephus Problem
int josephus(int n,int k)
{
	if(n==1)
	return 0;

	return (k+josephus(n-1,k))%n;
}
//Sum of subsets
int subsets(int arr[], int n, int req_sum)
{	
	if(n==0 )
	return req_sum==0?1:0;

	return subsets(arr,n-1,req_sum-arr[n-1])+subsets(arr,n-1,req_sum);
}
int digitalRoot(int n)
{
	if(n<=9)
	return n;
	int sum=n%10+digitalRoot(n/10);
	digitalRoot(sum);
}
//TOH
void toh_moves(int n, int a, int c, int b)
    {
        if(n == 1)
        {
            cout<<"move disk 1 from rod "<<a<<" to rod "<<c<<endl;
            return; 
        }
        toh_moves(n-1,a,c,b);
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
        toh_moves(n-1,b,a,c);
        
    }
string letters[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void p_w_fn(int a[],int n,int i,string str)
{
      if(i==n)
      {
      	cout<<str<<"\t";
            return;
      }
      for(int j=0;j<letters[a[i]].length();j++)
      {
            p_w_fn(a,n,i+1,str+letters[a[i]][j]);
		p_w_fn(a,n,i+1,str);
      }
}
int main()
{
	//revRecPrint(10);
	//cout<<endl;
	//fwdRecPrint(10,1);
	//cout<<"\nFact = "<<factTailRec(7,1l);
	//cout<<"Fibonacci Seq : \n";
	//printFib(15,0,1,0);
	//cout<<"SUM = "<<nat_num_sum(20,1);
	//cout<<check_pall("aabbcbba");
	//cout<<"SUM = "<<sum_of_digits(29178);
	/*cout<<"\n(INFAMOUS) Rope Cutting Problem \nSol (23,11,9,12) = "<<pieces(23,11,9,12);
	cout<<"\n(INFAMOUS) Rope Cutting Problem \nSol (9,2,2,2) = "<<pieces(9,2,2,2);
	cout<<"\n(INFAMOUS) Rope Cutting Problem \nSol (5,2,5,1) = "<<pieces(5,2,5,1);
	cout<<"\n(INFAMOUS) Rope Cutting Problem \nSol (5,4,2,6) = "<<pieces(5,4,2,6);*/
	/*cout<<"\n(10,3) = "<<josephus(10,3);
	cout<<"\n(9,3) = "<<josephus(9,3);*/
	/*int arr[5]={10,20,15,25,5};
	cout<<"SUM = "<<subsets(arr,5,25);*/
	//cout<<"DGRT = "<<digitalRoot(12345);
	//cout<<"TOH MOVES  :  \n";
	//toh_moves(2,1,3,2);
	int arr[8]={6,4,8};
	p_w_fn(arr,3,0,"");
}
