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
	void check_if_str_is_a_sbusequence(string s1,string s2)
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
	void rec_check_if_str_is_a_sbusequence(string s1,string s2)
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
				rec_check_if_str_is_a_sbusequence(s1.substr(1),s2.substr(1));
			else
				rec_check_if_str_is_a_sbusequence(s1.substr(1),s2);
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
	void leftmost_repeating_element(string s)
	{
		unordered_set<char> visited;
		int res=-1;
		for(int i=s.length()-1;i>=0;i--)
		{
			if(visited.count(s[i]))
				res=i;
			visited.insert(s[i]);
		}
		if(res==-1)
			cout<<"No repeating element\n";
		else
			cout<<"Leftmost repeating element : "<<s[res]<<endl;
	}
	void leftmost_non_repeating_element(string s)
	{
		unordered_set<char> visited;
		int res=-1;
		for(int i=s.length()-1;i>=0;i--)
		{
			if(visited.count(s[i])==0)
			{
				// if the char hasn't been visited, it could be a possible answer
				res=i;
			}
			else if(s[res]==s[i])
			{
				// if the char has been visited, but was set as a potential answer,
				// then this char is definitely not the answer as it is being visited again.
				res=-1;
			}
			visited.insert(s[i]);
		}
		if(res==-1)
			cout<<"No non-repeating element\n";
		else
			cout<<"Leftmost non-repeating element : "<<s[res]<<endl;
	}
	void rev_string(string &s, int st, int end)
	{
		while(st<end)
		{
			char temp=s[st];
			s[st]=s[end];
			s[end]=temp;
			st++;
			end--;
		}
		// return s;
	}
	void reverse_words_string(string s)
	{
		cout<<"Old string : "<<s<<endl;
		rev_string(s,0,s.length()-1);
		int last_white_space=-1;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				// s=rev_string(s,last_white_space+1,i-1);
				rev_string(s,last_white_space+1,i-1);
				last_white_space=i;
			}
		}
		// s=rev_string(s,last_white_space+1,s.length()-1);
		rev_string(s,last_white_space+1,s.length()-1);
		cout<<"New string : "<<s<<endl;
	}
	// ------- PATTERN SEARCHING ALGORITHMS------ //
	void improver_naive_patt_search(string text, string patt)
	{
		int n=text.length(),m=patt.length();
		for(int i=0;i<n;)
		{
			int j;
			for(j=0;j<m;j++)
			{
				if(patt[j]!=text[i+j])
				break;
			}
			if(j==m)
			cout<<i<<"\t";
			if(j==0)
			i++;
			else
			i=i+j;
		}
	}
	// KMP algo start
	void fill_LPS_array(string &s, int lps[])
	{
		lps[0]=0;
		int i=1,len=0,n=s.length();
		while(i<n)
		{
			if(s[i]==s[len])
			{
				lps[i++]=len++;
			}
			else
			{
				if(len==0)
				{	
					lps[i++]=len;
				}
				else
				{
					len=lps[len-1];
				}
			}
		}
	}
};
int main()
{
	StringQuestions obj;
	// obj.check_pallindrome("aaaaba");
	// obj.rec_check_if_str_is_a_susb equence("abcde","adb");
	// string s= "abcde";
	// cout<<s.substr(1);
	// obj.check_for_anagram("aab","bab");
	// obj.leftmost_repeating_element("MohIt_Kumar_Rai");
	// obj.leftmost_non_repeating_element("geeksforgeeks");
	// obj.reverse_words_string("red blue green yellow");
	// obj.reverse_words_string("nospacestring");
	// obj.improver_naive_patt_search("abcefabcdghababecdekabcd","abcd");
	string s1="abcefabcdghababecdekabcd";
	int lps[s1.length()]{0};
	obj.fill_LPS_array(s1,lps);
	for(int i=0;i<s1.length();i++)
		cout<<lps[i]<<"\t";
}