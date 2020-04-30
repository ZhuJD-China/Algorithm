/*
Description
��������Ϊn���ַ���S��Ҫ����һ������Ϊn���ַ���T�������T�ǿմ�����󷴸������������������
1����S��ͷ��ɾ��һ���ַ�,�ӵ�T��β��
2����S��β��ɾ��һ���ַ�,�ӵ�T��β��
Ŀ���ǹ����ֵ�����С���ַ���T(1<=n<=2000)
Input
��һ��Ϊ�ַ�������n��֮��n��ÿ��һ���ַ����ַ���ֻ������д��ĸ
Output
����ֵ�����С���ַ���T�����ʱһ��ֻ�����80���ַ�
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
		//�������������ַ����Ƚ� 
		for(int i=0; begin+i<=end; i++) {
			if(S[begin+i] < S[end-i]) {
				left = true;
				break;
			} else if(S[begin+i] > S[end-i]) {
				left = false;
				break;
			}
		}

		if(left) putchar(S[begin++]); //�������ķ��Ͼʹ�ӡ��׷���ַ����� 
		else	putchar(S[end--]);
	}
	return 0;
}



