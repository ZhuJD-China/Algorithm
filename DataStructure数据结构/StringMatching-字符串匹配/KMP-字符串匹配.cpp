#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void ComputePrefix(string s,int next[])
{
	int n = s.length();
	int j,i;

	next[0] = 0;

	for(i=0,j=1; j<n; j++) {
		
		while(i>0 && s[i]!=s[j]) {
			i = next[i-1];
			break;
		}
		if(s[i]==s[j]) {
			i++;
		}
		next[j] = i;
	}

	//打印next数组
	cout<<"next[]: "<<endl;
	for(int k=0; k<n; k++) {
		cout<<s[k]<<" ";
	}
	cout<<endl;
	for(int k=0; k<n; k++) {
		cout<<next[k]<<" ";
	}
	cout<<endl;
}

void KMPMatcher(string text,string pattern)
{
	int t_length = text.length();  //主串的长度
	int p_length = pattern.length();  //字串的长度

	int next[pattern.length()];		//next数组长度为字串的长度

	ComputePrefix(pattern, next);

	for(int i=0,j=0; i<t_length; i++) {

		while( j > 0 &&  pattern[j] != text[i] )
			j = next[j];

		if( pattern[j] == text[i] )
			j++;

		if( j == p_length ) {
			cout<<"res= "<< i - p_length + 1 <<endl;
			j=0;
		}
	}
}

int main()
{
	string text = "aabcdabcaaabaabaaaskjfgakfliabcabcdabcabcdadfabcdabcagabaas,jfhgasukaabcdabcabcfdgsvabcdabcacd";
	string pattern  ="abcdabca";

	KMPMatcher(text, pattern);

	return 0;
}

