/*
Problem Description
�����������꣨X1,Y1��,��X2,Y2��,���㲢��������ľ��롣


Input
���������ж��飬ÿ��ռһ�У���4��ʵ����ɣ��ֱ��ʾx1,y1,x2,y2,����֮���ÿո������


Output
����ÿ���������ݣ����һ�У����������λС����


Sample Input
0 0 0 1
0 1 1 0


Sample Output
1.00
1.41

*/

#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
    double x1, x2, y1, y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        double res = sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));
        //cout<<res<<endl;
        printf("%.2f\n", res);
    }



    return 0;
}
