#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
class StringQuestions
{
	public:
	void check_pallindrome(string str)
	{
		int st=0,end=str.length()-1;
		while(st<end)
		{
			if(str[st]!=str[end])
			{
				cout<<"NO";
				return;
			}
			st++;
			end--;
		}
		cout<<"YES";
	}
	void check_if_str_is_a_susequence(string s1,string s2)
	{
		// len s2 < len s1
		int i=0,j=0;
		while(i<s2.length() && j<s1.length())
		{
			if(s2[i]==s1[j])
			{
				i++;
				j++;
			}
			else
			{
				j++;
			}
		}
		if(i==s2.length())
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	void rec_check_if_str_is_a_susequence(string s1,string s2)
	{
		// len s2 < len s1
		if(s2.empty())
		{
			cout<<"Yes\n";
			return;
		}
		else if(s1.empty())
		{
			cout<<"No\n";
		}
		else
		{
			if(s1[0]==s2[0])
				rec_check_if_str_is_a_susequence(s1.substr(1),s2.substr(1));
			else
				rec_check_if_str_is_a_susequence(s1.substr(1),s2);
		}
	}
	void check_for_anagram(string s1,string s2)
	{
		// map<char,int> m1,m2;
		// for(int i=0;i<s1.length();i++)
		// {
		// 	m1[s1[i]]++;
		// 	m2[s2[i]]++;
		// }
		// for(auto it1=m1.begin(),it2=m2.begin();it1 != m1.end();it1++,it2++)
		// {
		// 	if(it1->second != it2->second)
		// 	{
		// 		cout<<"No\n";
		// 		return;
		// 	}
		// }
		// cout<<"Yes\n";
		if(s1.length()!=s2.length())
		{
			cout<<"No\n";
			return;
		}
		unordered_map<char,int> m;
		for(int i=0;i<s1.length();i++)
		{
			m[s1[i]]++;
			m[s2[i]]--;
			if(m[s1[i]]==0)
				m.erase(s1[i]);
			if(m[s2[i]]==0)
				m.erase(s2[i]);
		}
		if(m.size()==0)
			cout<<"Yes\n";
		else
			cout<<"NO\n";
	}
};
int main()
{
	StringQuestions obj;
	// obj.check_pallindrome("aaaaba");
	// obj.rec_check_if_str_is_a_susequence("abcde","adb");
	// string s= "abcde";
	// cout<<s.substr(1);
	obj.check_for_anagram("aab","bab");
}