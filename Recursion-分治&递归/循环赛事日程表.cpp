//分治法，循环赛事日程表
#include <iostream>
#include <math.h>
using namespace std;


void input(int &k)
{
	cout<<"Input K: "<<endl;
	cin>>k;
}

void output(int **a,int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cout<<a[i][j]<<"   ";
		}
		cout<<endl;
	}
}

void Table(int k,int n,int **a)
{
	for(int i=1; i<=n; i++)
		a[1][i]=i;//设置日程表第一行

	int m = 1;//每次填充时，起始填充位置

	/*
	用一个for循环将问题分成几部分，对于k=3，n=8，将问题分成3大部分
	第一部分为，根据已经填充的第一行，填写第二行
	第二部分为，根据已经填充好的第一部分，填写第三四行
	第三部分为，根据已经填充好的前四行，填写最后四行
	*/
	for(int s=1; s<=k; s++)//由s控制的第一部分填完。然后是s++，进行第二部分的填充
	{
		n /= 2; /// 每一部分填充的次数（比如右下角等于左上角填一次记为一次 4->2->1）
		for(int t=1; t<=n; t++)
		{
			for(int i=m+1; i<=2*m; i++)//控制行
			{
				for(int j=m+1; j<=2*m; j++)//控制列
				{
					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];//右下角等于左上角的值
					a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];//左下角等于右上角的值
				}
			}
		}
		m *= 2; // 每次起点要往后跳m次*(这里变化的过程是 1->2->4)
	}
}
int main()
{
	int k;
	input(k);

	int n=1<<k;

	//根据n动态分配二维数组a
	int **a = new int *[n+1];
	for(int i=0;i<=n;i++)
	{
		a[i] = new int[n+1];
	}


	Table(k,n,a);

	cout<<"Cycle Tour Calendar: "<<endl;
	output(a,n);

	//释放空间
	for(int i=0;i<=n;i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

