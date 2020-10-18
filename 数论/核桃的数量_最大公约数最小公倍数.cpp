/*核桃的数量
给每个组发一袋核桃
1. 各组的核桃数量必须相同

2. 各组内必须能平分核桃

3. 尽量提供满足1,2条件的最小数量

输入格式
输入包含三个正整数a, b, c，表示每个组正在加班的人数，用空格分开（a,b,c<30）
输出格式
输出一个正整数，表示每袋核桃的数量。
样例输入1
2 4 5
样例输出1
20
*/

#include<iostream>
#include<math.h>

using namespace std;

int gcd(int a, int b)
{
    int gcdNum;
    if(b == 0)
    {
        gcdNum = a;
    }
    else
    {
        gcdNum = gcd(b, a%b);
    }
    return gcdNum;
}

int lcm(int a, int b, int gcdNum)
{
    int lcmNum;
    lcmNum = a/gcdNum*b; //注意先除再乘 防止溢出
    return lcmNum;
}

int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;

    int d = lcm(a,b,gcd(a,b));

    cout<<lcm(c,d,gcd(c,d))<<endl;;


    return 0;
}
