/*
��Ŀ��
ũ��Լ��Ϊ������դ����Ҫ��һ��ܳ���ľ��ָ��N�顣
׼���гɵ�ľ��ĳ���ΪL1��L2��������Ln. δ�и�ľ��ĳ���ǡ��Ϊ�и�ľ��ĳ��Ⱥ͡�
ÿ���ж�ľ��ʱ����Ҫ�Ŀ���Ϊ���ľ��ĳ��ȡ�
���磬����Ϊ21��ľ���и��5��8��8������ľ�塣
��Ϊ21��ľ���и��13��8ʱ������Ϊ21.
�ٽ�����Ϊ13��ľ���и�ɳ���5��8ʱ������Ϊ13.���Ǻϼƿ���Ϊ34��
���ǰ���ĿҪ��ľ���и��꣬��С�Ŀ����Ƕ��٣�
����������
1<=N<=2000
0<=Li<=5000

����������
N=3, L={8, 5, 8}
���������
34

Sample Input
3
8
5
8
Sample Output
34
*/

#include<iostream> // (NlogN*(N-1)) ģ�����ȶ���+̰�� 
#include<algorithm>
using namespace std;

const int maxn=100;

int N;
int L[maxn];

int main(void)
{
	cin>>N;
	for(int i=0; i<N; i++)	cin>>L[i];
	int ans=0, res=0;
	int index=0;
	sort(L, L+N);	
	while(index!=N-1) {
		ans = L[index]+L[index+1];
		L[index+1] = ans;
		index++;
		sort(L+index, L+N);
		res+=ans;
	}
	cout<<res<<endl;
	return 0;
}

/*
//������ƾ����ڶ������ӣ�һ�� //  ��������  (N^2) 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define LL __int64

LL plank[20010];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%I64d",plank+i);
	LL ans=0;     //�ܵķ��á�����������

	while(N>1) {    //
		int min_one=0,min_two=1;    //��С��min_one����ʼ��Ϊ��1������С��min_two����ʼ��Ϊ��2��
		if(plank[min_one]>plank[min_two])
			swap(min_one,min_two);  //ÿ�ο�ʼ��ȷ��plank[min_one]<=plank[min_two]

		for(int i=2; i<N; i++)  //�ҵ���С��min_one���ʹ�С��min_two  //iһ��Ҫ��2��ʼ������
			if(plank[i]<plank[min_one]) {
				min_two=min_one;
				min_one=i;
			} else if(plank[i]<plank[min_two])
				min_two=i;

        //printf("min_one=%d\nmin_two=%d\n\n",min_one,min_two);
		LL temp=plank[min_one]+plank[min_two];  //����С�������ϲ�
		cout<<"plank[min_one]= "<<plank[min_one]<<" plank[min_two]= "<<plank[min_two]<<endl; 
		ans+=temp;

		if(min_one==N-1)
			swap(min_one,min_two);  //�����С���Ǹ��������������һ������ô����
		plank[min_one]=temp;        //plank[min_one]�����С���Ǹ�
		
		plank[min_two]=plank[N-1];  //���������С���Ǹ��������������һ��������������Լ������Լ���
									//������治�����һ���������һ������plank[min_two]����Ϊ����N--������ֵ�Ļ��ͻ����ˡ�����
		N--;
	}
	printf("%I64d\n",ans);
	return 0;
}

---------------------------------------------
//������ƾ����ڶ������ӣ��������ȶ���+̰�� (NlogN)
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n;
long long ans;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	scanf("%d",&n);
	int t;
	for(int i=1; i<=n; i++) {
		scanf("%d",&t);
		q.push(t);
	}
	for(int i=1; i<=n-1; i++) {
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		ans=ans+a+b;
		q.push(a+b);
	}
	printf("%lld",ans);
	return 0;
} 

*/
