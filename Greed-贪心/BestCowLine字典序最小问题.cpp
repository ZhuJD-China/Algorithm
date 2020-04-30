/*
Description
给定长度为n的字符串S，要构造一个长度为n的字符串T。起初，T是空串，随后反复进行下列任意操作：
1、从S的头部删除一个字符,加到T的尾部
2、从S的尾部删除一个字符,加到T的尾部
目标是构造字典序最小的字符串T(1<=n<=2000)
Input
第一行为字符串长度n，之后n行每行一个字符，字符串只包含大写字母
Output
输出字典序最小的字符串T，输出时一行只能输出80个字符
*/
#include<iostream>
#include<string>
using namespace std;

const int maxn = 1000;

int main(void)
{
	int N;
	cin>>N;
	char S[maxn];
	for(int i=0; i<N; i++)	cin>>S[i];

	int begin=0, end=N-1;

	bool left = false;

	while(begin <= end) {
		//将左起和右起的字符串比较 
		for(int i=0; begin+i<=end; i++) {
			if(S[begin+i] < S[end-i]) {
				left = true;
				break;
			} else if(S[begin+i] > S[end-i]) {
				left = false;
				break;
			}
		}

		if(left) putchar(S[begin++]); //如果左起的符合就打印（追加字符串） 
		else	putchar(S[end--]);
	}
	return 0;
}



