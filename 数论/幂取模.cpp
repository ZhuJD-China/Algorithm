#include <iostream>
#include <cstdio>
using namespace std;
/*�����㷨*/
/*��ʾa��b����Ȼ���cȡ��Ľ��*/
int power1(int a, int b, int c)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
        res = (res * a) % c;
    return res;
}
/*�������㷨*/
int power2(int a, int b, int c)
{
    int res = 1;
    a %= c;
    while (b)
    {
        if (b & 1)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}

/*���η�*/
int pow_mod(int a,int n,int m)
{
	int ans=1;
	int k=a%m;
	while(n>0)
	{
	   if(n%2==1)
		  ans=ans*k%m;
	    n=n/2;
	    k=(k*k)%m;
	}
		return ans;
}

int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        cout << power2(2, n, 9997) << endl;
        cout << power1(2, n, 9997) << endl;
        cout<<pow_mod(2,n,9997)<<endl;

    }
    return 0;
}
