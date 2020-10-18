/*
状态设计：F [ i ] 代表以 A [ i ] 结尾的 LIS 的长度

状态转移：F [ i ] = max { F [ j ] + 1 ，F [ i ] } (1 <= j <  i，A[ j ] < A[ i ])

边界处理：F [ i ] = 1 (1 <= i <= n)

时间复杂度：O (n^2)

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

//贪心+二分
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
//二分查找，返回a数组中第一个>=x的位置
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
        low[i] = INF;   //由于low中存的是最小值，所以low初始化为INF
    }
    low[1] = a[1];
    ans = 1;   //初始时LIS长度为1
    for(int i=2; i<=n; i++)
    {
        if(a[i] > low[ans])    //若a[i]>=low[ans]，直接把a[i]接到后面
            low[++ans] = a[i];
        else       //否则，找到low中第一个>=a[i]的位置low[j]，用a[i]更新low[j]
            low[binary_search(low, ans, a[i])] = a[i];
    }
    printf("%d\n", ans);   //输出答案
    return 0;
}

/*
lower_bound( )函数：
下面是使用lower_bound优化最长上升子序列。
由于长度相同的上升子序列只需要保存结尾最小的那个，而长度递增时
结尾数字的大小也是递增的。最长上升子序列就是找出比他大的第一个数。
前面的数都比他小，所以他和这个数的长度相同。然后由于他比较然后小，更新找到的那个值。

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
树状数组维护
DP的状态转移方程：F [ i ] = max { F [ j ] + 1 ，F [ i ] }  (1 <= j <  i，A[ j ] < A[ i ])
我们在递推F数组的时候，每次都要把F数组扫一遍求F[ j ]的最大值，时间开销比较大。我们可以借助数据结构来优化这个过程。
用树状数组来维护F数组（据说分块也是可以的，但是分块是O(n*sqrt(n)）的时间复杂度，不如树状数组跑得快）
首先把A数组从小到大排序，同时把A[ i ]在排序之前的序号记录下来。
然后从小到大枚举A[ i ]，每次用编号小于等于A[ i ]编号的元素的LIS长度+1来更新答案，同时把编号大于等于A[ i ]编号元素的LIS长度+1。
因为A数组已经是有序的，所以可以直接更新

树状数组求LIS不去重的话就变成了最长不下降子序列了

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
void modify(int x,int y)//把val[x]替换为val[x]和y中较大的数
{
    for(;x<=n;x+=x&(-x)) T[x]=max(T[x],y);
}
int query(int x)//返回val[1]~val[x]中的最大值
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
        z[i].num=i;//记住val[i]的编号，有点类似于离散化的处理，但没有去重
    }
    sort(z+1,z+n+1,cmp);//以权值为第一关键字从小到大排序
    for(int i=1;i<=n;i++)//按权值从小到大枚举
    {
        int maxx=query(z[i].num);//查询编号小于等于num[i]的LIS最大长度
        modify(z[i].num,++maxx);//把长度+1，再去更新前面的LIS长度
        ans=max(ans,maxx);//更新答案
    }
    printf("%d\n",ans);
    return 0;
}
*/
