/*
Ψһ�ֽⶨ���ֳ�Ϊ���������������������ǣ�
ÿ������1����Ȼ����Ҫô�������������Ҫô����дΪ2�������ϵ������Ļ���������Щ�����Ӱ���С����֮��д������һ�ַ�ʽ��
����һ�ַ�����ʾ���ǣ�
�����κ�һ������1��������,������һ����׼�ķֽ�ʽ:  N=p1^a1 * p2^a2*������*pn^an;������һϵ��anΪָ����pnΪ������
�˶���������κ�һ������ 1 �������������Ա�ʾΪ�����Ļ���

����������ʽ�ӣ�
��F(n)����n�������ӵ���������F(n)=(a1+1)*(a2+1)*(a3+1)*������������*(an+1)��
��G(n)����n�������ӵĺͣ���G(n)=(1+p1^2+p1^3+...+p1^a1)*(1+p2^2+p2^3+...p2^a2)*....*
*/

/*
���һ���������������Ĵ��룺
primel [ ]��������

ll getfac(ll x)
{
    ll ans=1;
    for(int i=1;i<=cnt&&primel[i]<=x;i++)
    {
        ll sum=0;//��ǰ����������ָ��
        while(x%primel[i]==0)//���������������ʱ
        {
            sum++;
            x/=primel[i];
        }
        ans*=(sum+1);//Ӧ�ö���Ľ���
    }
    if(x>1)//������������ʱ����������������һ����ô���������϶�������������ָ����1
    ans*=2;
    return ans;
}

*/


/*
Sample Input
2
10 2
12 2
Sample Output
Case 1: 1
Case 2: 2
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+20;
int primel[maxn]; //������
bool isp[maxn];
int cnt;
void makel()//ŷ��ɸ��ӡ������
{
    cnt=0;
    memset(isp,true,sizeof(isp));
    for(int i=2; i<maxn; i++)
    {
        if(isp[i])
            primel[++cnt]=i;
        for(int j=1; j<=cnt; j++)
        {
            if(i*primel[j]>maxn)
                break;
            isp[i*primel[j]]=false;
            if(i%primel[j]==0)
                break;
        }
    }
}
ll getfac(ll x)//Ψһ�ֽⶨ��
{
    ll ans=1;
    for(int i=1; i<=cnt&&primel[i]*primel[i]<=x; i++)
    {
        ll sum=0;
        while(x%primel[i]==0)
        {
            sum++;
            x/=primel[i];
        }
        ans*=(sum+1);
    }
    if(x>1)
        ans*=2;
    return ans;
}
int main()
{
    int t;
    int cas=0;
    ll a,b;
    cin>>t;
    makel();

//    for(int i=1;i<10;i++)
//        cout<<primel[i]<<" ";
//    cout<<endl;

    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        if(a<b*b)//�����ֽܷ�Ϊ��b��������
        {
            printf("Case %d: 0\n",++cas);
            continue;
        }
        ll count=getfac(a)/2;//�����ظ�
        for(int i=1; i<b; i++) //ȥ��С��b������
        {
            if(a%i==0)
                count--;
        }
        printf("Case %d: %lld\n",++cas,count);
    }
    return 0;
}



