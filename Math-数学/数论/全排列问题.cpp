/*按字典序生成1~n的全排列*/
#include <iostream>
#include <vector>

#define N 5

using namespace std;

//需要全排列的数组，必须按递增顺序
int a[N] = {-1,1,2,3,4};

//输出一个排列
void print(vector<int> vec)
{
    vector<int>::iterator it = vec.begin();
    for(it ; it != vec.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//递归生成全排列
void dfs(vector<int>& vec,bool flag[])
{
    if(vec.size() == N-1)
    {
        print(vec);
    }
    else
    {
        for(int i=1; i<N; i++)
        {
            //如果没有访问，则访问
            if(flag[i] == false)
            {
                //将元素加入vector容器中
                vec.push_back(a[i]);
                //标记已访问
                flag[i] = true;
                //继续递归
                dfs(vec,flag);
                //回溯
                vec.pop_back();
                flag[i] = false;
            }
        }
    }
}


int main()
{
    bool flag[N] = {false};
    vector<int> vec;
    dfs(vec,flag);

    return 0;
}


/*
可重复全排列
之前的代码只能保证1-n的全排列，但是待排列元素不是1~n，比如是 1 1 2 的排列

排列如下：

1 1 2

1 2 1

2 1 1


　　修改两个地方：

　　1.因为元素可以重复，所以不能再用“A中是否已经存在B数组”的条件来决定是否添加B[i]元素。
取而代之，分别对A，B数组扫描，只要A中的B[i]不超过B中的B[i]即可。

　　2.在题目要求上，重复元素属于相同元素时，如1123的排列中1123和1123是等价的，只能算一种。
我们最好先对B数组排个序（排序复杂度是nlogn，相较于两层循环的代，影响并不是很大)
然后在最外层循环添上一个控制条件(i==0||B[i]!=B[i-1]),为的就是防止重复的元素又一次排列。
*/
#include<iostream>
using namespace std;
void print_permutation(int n,int *A,int *B,int cur)
{
    if(cur==n)
    {
        for(int i=0; i<n; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    else
        for(int i=0; i<n; i++)
        {
            if(!i||B[i]!=B[i-1])
            {
                int c1=0,c2=0;
                for(int j=0; j<cur; j++)//扫描A中已有B[i]的个数
                    if(A[j]==B[i]) c1++;
                for(int j=0; j<n; j++)//扫描B中所有B[i]的个数
                    if(B[j]==B[i]) c2++;
                if(c1<c2)
                {
                    A[cur]=B[i];
                    print_permutation(n,A,B,cur+1);
                }
            }
        }
}

int main()
{
    int a[]= {0};
    int b[]= {1,1,2,4};
    print_permutation(4,a,b,0);
    return 0;
}
