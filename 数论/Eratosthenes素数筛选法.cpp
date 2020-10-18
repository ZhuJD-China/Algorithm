#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

//Eratosthenesɸ����������ɸ����
const int maxn=101;
int prime[maxn],pNum=0;
bool p[maxn]= {false}; // iΪ��������p[i]Ϊfalse

void Find_Prime()
{
    for(int i=2; i<maxn; i++)
    {
        if(p[i]==false)
            prime[pNum++] = i;
        for(int j=i+i; j<maxn; j+=i)
        {
            p[j]=true;
        }
    }
}

int main()
{
    Find_Prime();  //���1~100���ڵ���������
    for(int i=0; i<pNum; i++)
    {
        printf("%d ",prime[i]);
    }
    return 0;
}

//���Ӷ�̫�ߣ�������ʹ��
bool isPrime(int n)
{
    if(n<=1) return false; //����
    int sqr = (int)sqrt(1.0*n); //����
    for(int i=2; i<=sqr; i++)
    {
        if(n%i==0) return false; //n��i�ı�������n��������
    }
    return false;  //n������
}
