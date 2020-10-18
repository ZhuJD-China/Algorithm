/*
״̬��ƣ�F [ i ] ������ A [ i ] ��β�� LIS �ĳ���

״̬ת�ƣ�F [ i ] = max { F [ j ] + 1 ��F [ i ] } (1 <= j <  i��A[ j ] < A[ i ])

�߽紦��F [ i ] = 1 (1 <= i <= n)

ʱ�临�Ӷȣ�O (n^2)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 103, INF = 0x7f7f7f7f;
int a[maxn], f[maxn];
int n,ans = -INF;
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<i; j++)
            if(a[j] < a[i])
                f[i] = max(f[i], f[j]+1);
    for(int i=1; i<=n; i++)
        ans = max(ans, f[i]);
    printf("%d\n", ans);
    return 0;
}

*/

//̰��+����
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn =300003, INF = 0x7f7f7f7f;
int low[maxn], a[maxn];
int n, ans;

int binary_search(int *a, int R, int x)
//���ֲ��ң�����a�����е�һ��>=x��λ��
{
    int L = 1, mid;
    while(L <= R)
    {
        mid = (L+R) >> 1;
        if(a[mid] <= x)
            L = mid + 1;
        else
            R = mid - 1;
    }
    return L;
}

int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        low[i] = INF;   //����low�д������Сֵ������low��ʼ��ΪINF
    }
    low[1] = a[1];
    ans = 1;   //��ʼʱLIS����Ϊ1
    for(int i=2; i<=n; i++)
    {
        if(a[i] > low[ans])    //��a[i]>=low[ans]��ֱ�Ӱ�a[i]�ӵ�����
            low[++ans] = a[i];
        else       //�����ҵ�low�е�һ��>=a[i]��λ��low[j]����a[i]����low[j]
            low[binary_search(low, ans, a[i])] = a[i];
    }
    printf("%d\n", ans);   //�����
    return 0;
}

/*
lower_bound( )������
������ʹ��lower_bound�Ż�����������С�
���ڳ�����ͬ������������ֻ��Ҫ�����β��С���Ǹ��������ȵ���ʱ
��β���ֵĴ�СҲ�ǵ����ġ�����������о����ҳ�������ĵ�һ������
ǰ�����������С����������������ĳ�����ͬ��Ȼ���������Ƚ�Ȼ��С�������ҵ����Ǹ�ֵ��

#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int num[10]={3,6,3,2,4,6,7,5,4,3};

const int INF=0x3f3f3f3f;
int l=10, g[100], d[100];

int main()
{
    fill(g, g+l, INF);
    int max_=-1;
    for(int i=0; i<l; i++)
    {
        int j = lower_bound(g, g+l, num[i]) - g;
        d[i] = j+1;
        if(max_<d[i])
            max_=d[i];
        g[j] = num[i];
    }
    printf("%d\n", max_);
    return 0;
}
*/


/*
��״����ά��
DP��״̬ת�Ʒ��̣�F [ i ] = max { F [ j ] + 1 ��F [ i ] }  (1 <= j <  i��A[ j ] < A[ i ])
�����ڵ���F�����ʱ��ÿ�ζ�Ҫ��F����ɨһ����F[ j ]�����ֵ��ʱ�俪���Ƚϴ����ǿ��Խ������ݽṹ���Ż�������̡�
����״������ά��F���飨��˵�ֿ�Ҳ�ǿ��Եģ����Ƿֿ���O(n*sqrt(n)����ʱ�临�Ӷȣ�������״�����ܵÿ죩
���Ȱ�A�����С��������ͬʱ��A[ i ]������֮ǰ����ż�¼������
Ȼ���С����ö��A[ i ]��ÿ���ñ��С�ڵ���A[ i ]��ŵ�Ԫ�ص�LIS����+1�����´𰸣�ͬʱ�ѱ�Ŵ��ڵ���A[ i ]���Ԫ�ص�LIS����+1��
��ΪA�����Ѿ�������ģ����Կ���ֱ�Ӹ���

��״������LIS��ȥ�صĻ��ͱ��������½���������

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn =103,INF=0x7f7f7f7f;
struct Node{
    int val,num;
}z[maxn];
int T[maxn];
int n;
bool cmp(Node a,Node b)
{
    return a.val==b.val?a.num<b.num:a.val<b.val;
}
void modify(int x,int y)//��val[x]�滻Ϊval[x]��y�нϴ����
{
    for(;x<=n;x+=x&(-x)) T[x]=max(T[x],y);
}
int query(int x)//����val[1]~val[x]�е����ֵ
{
    int res=-INF;
    for(;x;x-=x&(-x)) res=max(res,T[x]);
    return res;
}
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&z[i].val);
        z[i].num=i;//��סval[i]�ı�ţ��е���������ɢ���Ĵ�����û��ȥ��
    }
    sort(z+1,z+n+1,cmp);//��ȨֵΪ��һ�ؼ��ִ�С��������
    for(int i=1;i<=n;i++)//��Ȩֵ��С����ö��
    {
        int maxx=query(z[i].num);//��ѯ���С�ڵ���num[i]��LIS��󳤶�
        modify(z[i].num,++maxx);//�ѳ���+1����ȥ����ǰ���LIS����
        ans=max(ans,maxx);//���´�
    }
    printf("%d\n",ans);
    return 0;
}
*/
