/*
题目：
农夫约翰为了修理栅栏，要将一块很长的木板分割成N块。
准备切成的木板的长度为L1、L2、……、Ln. 未切割木板的长度恰好为切割木板的长度和。
每次切断木板时，需要的开销为这块木板的长度。
例如，长度为21的木板切割成5、8、8的三块木板。
长为21的木板切割成13、8时，开销为21.
再将长度为13的木板切割成长度5、8时，开销为13.于是合计开销为34。
于是按题目要求将木板切割完，最小的开销是多少？
限制条件：
1<=N<=2000
0<=Li<=5000

输入样例：
N=3, L={8, 5, 8}
输出样例：
34

Sample Input
3
8
5
8
Sample Output
34
*/

#include<iostream> // (NlogN*(N-1)) 模拟优先队列+贪心 
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
//程序设计竞赛第二版例子（一） //  迭代更新  (N^2) 
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
	LL ans=0;     //总的费用。。。。。。

	while(N>1) {    //
		int min_one=0,min_two=1;    //最小的min_one，初始化为第1个，次小的min_two，初始化为第2个
		if(plank[min_one]>plank[min_two])
			swap(min_one,min_two);  //每次开始，确保plank[min_one]<=plank[min_two]

		for(int i=2; i<N; i++)  //找到最小的min_one，和次小的min_two  //i一定要从2开始。。。
			if(plank[i]<plank[min_one]) {
				min_two=min_one;
				min_one=i;
			} else if(plank[i]<plank[min_two])
				min_two=i;

        //printf("min_one=%d\nmin_two=%d\n\n",min_one,min_two);
		LL temp=plank[min_one]+plank[min_two];  //把最小的两个合并
		cout<<"plank[min_one]= "<<plank[min_one]<<" plank[min_two]= "<<plank[min_two]<<endl; 
		ans+=temp;

		if(min_one==N-1)
			swap(min_one,min_two);  //如果最小的那个正好是数组最后一个，那么交换
		plank[min_one]=temp;        //plank[min_one]存放最小的那个
		
		plank[min_two]=plank[N-1];  //上面如果最小的那个正好是数组最后一个，交换后就是自己等于自己，
									//如果上面不是最后一个，把最后一个赋给plank[min_two]，因为下面N--，不赋值的话就会少了。。。
		N--;
	}
	printf("%I64d\n",ans);
	return 0;
}

---------------------------------------------
//程序设计竞赛第二版例子（二）优先队列+贪心 (NlogN)
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
