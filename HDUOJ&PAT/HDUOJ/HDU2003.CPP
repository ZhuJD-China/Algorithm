/*
Problem Description
��ʵ���ľ���ֵ��


Input
���������ж��飬ÿ��ռһ�У�ÿ�а���һ��ʵ����


Output
����ÿ���������ݣ�������ľ���ֵ��Ҫ��ÿ���������һ�У����������λС����


Sample Input
123
-234.00123
-234.00


Sample Output
123.00
234.00

*/
#include<iostream>
#include<cmath>

#define PI 3.1415927

using namespace std;

int main(void)
{
    double num;
    while(cin>>num)
    {

        if(num>0){
            printf("%.2f\n", num);
        }else{
            num *= -1;
             printf("%.2f\n", num);
        }


    }

    return 0;
}