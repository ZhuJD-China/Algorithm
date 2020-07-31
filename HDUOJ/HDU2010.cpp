/*
Problem Description
�������ʻ��ļ��ڣ�ˮ�ɻ��������������˵Ĵ�����ѧ���и�ˮ�ɻ�����������������ģ�
��ˮ�ɻ�������ָһ����λ�������ĸ�λ���ֵ������͵����䱾�����磺153=1^3+5^3+3^3��
����Ҫ�����������m��n��Χ�ڵ�ˮ�ɻ�����


Input
���������ж��飬ÿ��ռһ�У�������������m��n��100<=m<=n<=999����


Output
����ÿ������ʵ����Ҫ����������ڸ�����Χ�ڵ�ˮ�ɻ���������˵�������ˮ�ɻ���������ڵ���m,����С�ڵ���n������ж������Ҫ���С����������һ���������֮����һ���ո����;
��������ķ�Χ�ڲ�����ˮ�ɻ����������no;
ÿ������ʵ�������ռһ�С�


Sample Input
100 120
300 380


Sample Output
no
370 371

*/
#include<iostream>
#include<math.h>
using namespace std;

int main(void)
{
    int m, n;
    while(cin>>m>>n && m && n)
    {
        bool flag = false;
        for(int i=m; i<=n; i++)
        {

            int a, b, c;
            a = i / 100;
            b = i / 10 % 10;
            c = i % 10;
            //cout<<"abc "<<a<<b<<c<<endl;
            if(i == pow(a, 3)+pow(b, 3)+ pow(c, 3))
            {
                if(flag == false)
                {
                    cout<<i;
                    flag = true;
                }
                else
                {
                    cout<<" "<<i;
                }
            }

        }

        if(!flag)
        {
            cout<<"no";
        }
        cout<<endl;
    }


    return 0;
}
