//此算法仅仅是输出下标，实际应用应输入另一个数组来进行存储数据
//A数组是下标数组，每次输出的是下标集合
#include<iostream>

using namespace std;

void print_subset(int n, int *A, int cur)  //cur是当前A数组的位置
{
	for(int i = 0; i < cur; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");


	int s = cur ? A[cur - 1] + 1 : 0;
	//当cur等于0的时候，这是第一次进入函数，所以选取的集合下标元素为0就可以了
	//cur不等于0的时候，即cur前面还有下标元素，为了得到全部的子集，所以这里不能漏掉，便从最小的那一个选择
	//那为什么A[cur-1]+1就是最小的下标呢，刚刚输出的最后一个下标就是A[cur-1]，所以这一个下标+1，即还未选择过的最小下标

	//然后就是从当前最小的还未选择过的下标作为下一个下标集合的首元素开始选取
	//直到n-1的下标位置，每一次选取首下标之后都开始递归
	for(int i = s; i < n; ++i) {
//		cout<<"S= "<<s<<" cur= "<<cur<<endl;
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
	
}

int main()
{
	int n;
	int A[10];//该数组存放的是数据数组的下标，为了简单，并没有定义数据数组，数据数组在输出的时候才用得上
	while(scanf("%d", &n) == 1) {
		print_subset(n, A, 0);
	}
	return 0;
}
