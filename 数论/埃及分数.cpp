//��������
/*
��һ������a/b, �ֽ�����ɸ���λ����1/x�ĺ͡�Ҫ���ҵ�����������������С�ĵ�λ�������ķ���
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 1000;
LL ans[maxn],v[maxn];
int maxd,kcase;
int gcd(LL a,LL b) //���Լ��������Լ��
{
    LL temp;
    while(b)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
LL get_first(LL a, LL b) //����1/c<=a/b����Сc
{
    return b/a + 1;
}
bool better(int d) //��������ֵ�������ǰ��v��Ŀǰ���Ž�ans���ţ�����ans
{
    for(int i=d; i>=0; i--)
        if(v[i] != ans[i])
            return ans[i] == -1 || v[i] < ans[i];
    return false;
}
//��ǰ���Ϊd����ĸ����С��from������֮��ǡ��Ϊaa/bb
bool dfs(int d,int from,LL aa,LL bb)
{
    if(d == maxd) //��ȴﵽ��ǰö�ٸ���
    {
        if(bb % aa) return false;//aa/bb�����ǰ�������
        v[d] = bb/aa;//�����ĸ
        if(better(d)) memcpy(ans,v,sizeof(LL)*(d+1));//�������Ž�
        return true;//���سɹ�
    }
    bool ok = false;//���ڷ��ر��εݹ�Ľ��
    from = max((LL)from,get_first(aa,bb));//ö�ٵ����
    for(int i=from; ; i++)
    {
        if(bb * (maxd+1-d) <= i*aa) break;//��֦�����ʣ�µ�maxd+1-d������ȫ������1/i����������Ȼ������aa/bb�����޽⣡ (maxd+1-d)/i <= aa/bb
        v[d] = i;//�����ĸ
        //����aa/bb - 1/i������Ϊa2/b2
        LL b2 = bb*i;
        LL a2 = aa*i - bb;
        LL g = gcd(a2,b2);//����Լ��
        if(dfs(d+1,i+1,a2/g,b2/g)) ok = true;//�ҵ��ⷵ�سɹ�
    }
    return ok;
}

void solve(int a,int b)
{
    int ok = 0;
    for(maxd = 1; ; maxd++) //ö����ȣ�����ʽ��ӵĸ���
    {
        memset(ans,-1,sizeof(ans));
        if(dfs(0,get_first(a,b),a,b)) //�ݹ��ҵ�ʱ���سɹ�
        {
            ok = 1;
            break;//��ǲ��˳�ö��
        }
    }
    printf("Case %d: %d/%d=",++kcase,a,b);
    if(ok)
    {
        for(int i=0; i<maxd; i++) printf("1/%lld+",ans[i]);
        printf("1/%lld\n",ans[maxd]);
    }
    else printf("%d/%d\n",a,b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
        solve(a,b);
    return 0;
}

