/*
------------------------------------
[����]
n=5�� s={1,2,,4,6,8},t={3,5,7,9,10}
------------------------------------
[���]
3(ѡ��1,3,5)
-------------------------------------
[�㷨]
�ڿ�ѡ��ʱ���ڣ�ÿ�ζ�ѡ�����ʱ������Ĺ���!!!

5
1 2 4 6 8
3 5 7 9 10
*/

#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N=100000;
int N; //ʱ�����
int S[MAX_N],T[MAX_N];

pair<int,int> itv[MAX_N]; //���ڹ��������pair����

bool cmp(const pair<int,int> &a,const pair<int,int> &b)   //�����Բ��������ɸı�
{
	return  a.first  <  b.first;
}

void solve()
{
	//��pair�ֵ���Ƚ�
	// ��T����frist��S����second
	for(int i=0; i<N; i++) {
		itv[i].first=T[i];
		itv[i].second=S[i];
	}
	
	sort(itv,itv+N,cmp);
	
//	for(int i=0; i<N; i++) {
//		cout<<"("<<itv[i].first<<" "<<itv[i].second<<")"<<endl;;
//		//printf("(%d, %d)\n",itv[i].first )
//	}

	//t�������ѡ�����Ľ���ʱ��
	int ans=0,t=0;
	for(int i=0; i<N; i++) {
		if(t<itv[i].second) {
			ans++;
			t=itv[i].first;
		}
	}

	cout<<ans<<endl;
}


int main(void)
{
	while(cin>>N) {
		for(int i=0; i<N; i++)	cin>>S[i];
		for(int i=0; i<N; i++)	cin>>T[i];
		solve();
	}
	return 0;
}




//�Լ�д�� 
////��������
//// n = 5
//// s = 1 2 4 6 8
//// t = 3 5 7 9 10
///*
//5
//1 2 4 6 8
//3 5 7 9 10
//*/
//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//int main(void)
//{
//	int n;
//	int s[n], t[n];
//	cin>>n;
//	for(int i=0; i<n; i++)	cin>>s[i];
//	for(int i=0; i<n; i++)	cin>>t[i];
//
//	int Count=0;
//	int jump;
//
//	for(int i=0; i<n; i++) {
//		for(int j=i+1; j<n; j++) {
//			if(s[j]>t[i]){
////					cout<<"j= "<<j<<endl;
//					jump = j;
//					Count++; 
//			}
//		}
//		i = jump;
//	}
//
//	cout<<Count<<endl;
//	return 0;
//}



