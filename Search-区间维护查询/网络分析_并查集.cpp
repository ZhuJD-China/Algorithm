/*
试题 J: 网络分析
时间限制: 1.0s 内存限制: 256.0MB 本题总分：25 分
【问题描述】
小明正在做一个网络实验。
他设置了 n 台电脑，称为节点，用于收发和存储数据。
初始时，所有节点都是独立的，不存在任何连接。
小明可以通过网线将两个节点连接起来，连接后两个节点就可以互相通信
了。两个节点如果存在网线连接，称为相邻。
小明有时会测试当时的网络，他会在某个节点发送一条信息，信息会发送
到每个相邻的节点，之后这些节点又会转发到自己相邻的节点，直到所有直接
或间接相邻的节点都收到了信息。所有发送和接收的节点都会将信息存储下来。
一条信息只存储一次。
给出小明连接和测试的过程，请计算出每个节点存储信息的大小。
【输入格式】
输入的第一行包含两个整数 n, m，分别表示节点数量和操作数量。节点从
1 至 n 编号。
接下来 m 行，每行三个整数，表示一个操作。
如果操作为 1 a b，表示将节点 a 和节点 b 通过网线连接起来。当 a = b
时，表示连接了一个自环，对网络没有实质影响。
如果操作为 2 p t，表示在节点 p 上发送一条大小为 t 的信息。
【输出格式】
输出一行，包含 n 个整数，相邻整数之间用一个空格分割，依次表示进行
完上述操作后节点 1 至节点 n 上存储信息的大小。

Input:
4 8
1 1 2
2 1 10
2 3 5
1 4 1
2 2 2
1 1 2
1 2 4
2 2 1
Output:
13 13 5 3
*/
#include<iostream>
#include<string.h>
using namespace std;

const int maxn = 100000 + 10;
int pa[maxn];

// 并查集的查找操作，带路径压缩
int findset(int x)
{
    return pa[x] != x ? pa[x] = findset(pa[x]) : x;
}

int main(void)
{
    int n,m;
    cin>>n>>m;
    int ans[n+1];
    memset(ans,0,sizeof(ans));

    for(int i = 0; i <= maxn; i++) pa[i] = i;

    for(int i=0; i<m; i++)
    {
        int operator_sig,num1,num2;
        cin>>operator_sig>>num1>>num2;

        if(operator_sig==1)
        {
            num1 = findset(num1);
            num2 = findset(num2);
            if(num1 == num2)
            {
                continue;
            }
            else pa[num1] = num2; // 否则合并
        }
        else
        {
            num1 = findset(num1);

            for(int e=1;e<=n;e++){
                if(findset(e)==num1){
                    ans[e]+=num2;
                }
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}
