/*
Problem Description
��������İ뾶ֵ��������������


Input
���������ж��飬ÿ��ռһ�У�ÿ�а���һ��ʵ������ʾ��İ뾶��


Output
�����Ӧ��������������ÿ���������ݣ����һ�У�������������λС����


Sample Input
1
1.5


Sample Output
4.189
14.137

Hint

#define PI 3.1415927
*/

#include<iostream>
#include<cmath>

#define PI 3.1415927

using namespace std;

int main(void)
{
    double r;
    while(cin>>r)
    {
        /*V=4��r3/3*/
        double v = (4*PI*pow(r, 3))/3;
        printf("%.3f\n", v);
    }

    return 0;
}
