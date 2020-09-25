//���η���ѭ�������ճ̱�
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
		a[1][i]=i;//�����ճ̱��һ��

	int m = 1;//ÿ�����ʱ����ʼ���λ��

	/*
	��һ��forѭ��������ֳɼ����֣�����k=3��n=8��������ֳ�3�󲿷�
	��һ����Ϊ�������Ѿ����ĵ�һ�У���д�ڶ���
	�ڶ�����Ϊ�������Ѿ����õĵ�һ���֣���д��������
	��������Ϊ�������Ѿ����õ�ǰ���У���д�������
	*/
	for(int s=1; s<=k; s++)//��s���Ƶĵ�һ�������ꡣȻ����s++�����еڶ����ֵ����
	{
		n /= 2; /// ÿһ�������Ĵ������������½ǵ������Ͻ���һ�μ�Ϊһ�� 4->2->1��
		for(int t=1; t<=n; t++)
		{
			for(int i=m+1; i<=2*m; i++)//������
			{
				for(int j=m+1; j<=2*m; j++)//������
				{
					a[i][j+(t-1)*m*2] = a[i-m][j+(t-1)*m*2-m];//���½ǵ������Ͻǵ�ֵ
					a[i][j+(t-1)*m*2-m] = a[i-m][j+(t-1)*m*2];//���½ǵ������Ͻǵ�ֵ
				}
			}
		}
		m *= 2; // ÿ�����Ҫ������m��*(����仯�Ĺ����� 1->2->4)
	}
}
int main()
{
	int k;
	input(k);

	int n=1<<k;

	//����n��̬�����ά����a
	int **a = new int *[n+1];
	for(int i=0;i<=n;i++)
	{
		a[i] = new int[n+1];
	}


	Table(k,n,a);

	cout<<"Cycle Tour Calendar: "<<endl;
	output(a,n);

	//�ͷſռ�
	for(int i=0;i<=n;i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

