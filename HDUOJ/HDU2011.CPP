/*
Problem Description
多项式的描述如下：
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
现在请你求出该多项式的前n项的和。


Input
输入数据由2行组成，首先是一个正整数m（m<100），表示测试实例的个数，第二行包含m个正整数，
对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。


Output
对于每个测试实例n，要求输出多项式前n项的和。每个测试实例的输出占一行，结果保留2位小数。


Sample Input
2
1 2


Sample Output
1.00
0.50
*/
#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int T;
    while(cin>>T && T)
    {
        // 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...

        for(int i=0; i<T; i++)
        {
            double n[T];
            cin>>n[i];
            double res =0;
            for(double j=1; j<=n[i]; j++)
            {
                // cout<<"j= "<<j<<"| "<<pow(-1, j+1) * (1/j)<<endl;

                res += pow(-1, j+1) * (1/j);
                //cout<<"res += "<<res<<endl;

            }
            printf("%.2f\n", res);
        }
    }


    return 0;
}
