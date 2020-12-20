/*
Problem Description
����ʽ���������£�
1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
������������ö���ʽ��ǰn��ĺ͡�


Input
����������2����ɣ�������һ��������m��m<100������ʾ����ʵ���ĸ������ڶ��а���m����������
����ÿһ������(������Ϊn,n<1000������ö���ʽ��ǰn��ĺ͡�


Output
����ÿ������ʵ��n��Ҫ���������ʽǰn��ĺ͡�ÿ������ʵ�������ռһ�У��������2λС����


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