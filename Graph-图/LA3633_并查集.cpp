/*
题目大意：有一些简单的化合物，每个化合物由两种元素组成，把这些化合物按顺序装车，
若k个化合物正好包含k种元素，那么就会爆炸。避免爆炸，有些化合物就不能装车。
求有多少个不能装车。

题目分析：若k个化合物正好包含k种元素，那么就会爆炸。我们把每种元素看成一个顶点，
每种化合物看成一条边，若有环存在的时候正好是爆炸的情况，所以避免成环记录不能放的数量就行了。

我们可以用一个并查集来维护图的连通分量集合，
每次得到一个简单化合物(x,y)时检查x和y是否在同一个集合中。
如果是，则拒绝，反之则接受。
*/
#include <cstdio>
const int maxn = 100000 + 10;
int pa[maxn];

// 并查集的查找操作，带路径压缩
int findset(int x)
{
    return pa[x] != x ? pa[x] = findset(pa[x]) : x;
}
/*
Sample Input:
1 2
3 4
3 5
3 1
2 3
4 1
2 6
6 5
-1

Sample Output:
3
*/

int main()
{
    int x, y;
    while(scanf("%d", &x) == 1)
    {
        for(int i = 0; i <= maxn; i++) pa[i] = i;
        int refusals = 0;
        while(x != -1)
        {
            scanf("%d", &y);
            x = findset(x);
            y = findset(y);
            if(x == y) ++refusals; // 如果x和y在同一个集合，则拒绝
            else pa[x] = y; // 否则合并。这里没有使用启发式合并
            scanf("%d", &x);
        }
        printf("%d\n", refusals);
    }
    return 0;
}
