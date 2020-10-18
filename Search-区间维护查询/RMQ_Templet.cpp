// UVa11235 Frequent Values

/*
Sample Input
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output
1
4
3
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100000 + 5;
const int maxlog = 20;

// 区间最*大*值
struct RMQ
{
    int d[maxn][maxlog];
    void init(const vector<int>& A)
    {
        int n = A.size();
        for(int i = 0; i < n; i++) d[i][0] = A[i];
        for(int j = 1; (1<<j) <= n; j++)
            for(int i = 0; i + (1<<j) - 1 < n; i++)
                d[i][j] = max(d[i][j-1], d[i + (1<<(j-1))][j-1]);


        cout<<"********************************"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<d[i][j]<<"  ";
            }cout<<endl;
        }

        cout<<"********************************"<<endl;
    }


    int query(int L, int R)
    {
        int k = 0;
        while((1<<(k+1)) <= R-L+1) k++; // 如果2^(k+1)<=R-L+1，那么k还可以加1
        cout<<"k= "<<k<<endl;
        return max(d[L][k], d[R-(1<<k)+1][k]);
    }
};

int a[maxn], num[maxn], left[maxn], right[maxn];
RMQ rmq;
int main()
{
    int n, q;

    vector<int> V;
    for(int i=0; i<10; i++)
        V.push_back(i);
    for(int i=0;i<10;i++)
        cout<<V[i]<<"  ";
    cout<<endl;

    rmq.init(V);

    int res = rmq.query(0,9);

    printf("%d\n",res);



    return 0;
}
