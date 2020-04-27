//增量构造法 
// 0-n 范围的子集生成  
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100;
int A[maxn];

void print_subset(int n, int* A, int cur)
{
	for(int i=0; i<cur; i++) printf("%d ", A[i]);
	
	cout<<endl;
	
	int s = cur? A[cur-1]+1 : 0;   /*
										s = cur ->   s=A[cur-1]
										s != cur ->  s=0
									*/ 
	
	for(int i=s; i<n; i++) {
		A[cur]=i;
		print_subset(n, A, cur+1);
	}
}

int main(void)
{
	int n;
	cin>>n;
	
	print_subset(n,A,0);

	return 0;
}
