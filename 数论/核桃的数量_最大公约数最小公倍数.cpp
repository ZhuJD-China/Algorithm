/*���ҵ�����
��ÿ���鷢һ������
1. ����ĺ�������������ͬ

2. �����ڱ�����ƽ�ֺ���

3. �����ṩ����1,2��������С����

�����ʽ
�����������������a, b, c����ʾÿ�������ڼӰ���������ÿո�ֿ���a,b,c<30��
�����ʽ
���һ������������ʾÿ�����ҵ�������
��������1
2 4 5
�������1
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
    lcmNum = a/gcdNum*b; //ע���ȳ��ٳ� ��ֹ���
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
