/*
Problem Description
数列的定义如下：
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

Input
输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。

Output
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。

Sample Input
81 4
2 2


Sample Output
94.73
3.41

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
//    double num;
//    cin>>num;
//    printf("%.2f\n", sqrt(num));
    double N, M;
    while(cin>>N>>M)
    {
        double res = N;
        for(int i=0;i<M-1;i++){
            double temp = sqrt(N);
           // cout<<temp<<" ";
            res += temp;
            N = temp;
        }
        //cout<<endl;
        //cout<<"res= "<<res<<endl;
        printf("%.2f\n", res);
    }


    return 0;
}
