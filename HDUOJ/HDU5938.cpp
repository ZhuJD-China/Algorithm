/*
Input
��һ�а���һ������T����ʾ����������������

ÿ�����Զ�����һ���ַ�����ֻ��������'1'-'9'��

Limits
1��T��10^5
5��length of string��20

Output
����ÿ��������������Ӧ�����'Case #x: y'������x��ʾ�����ţ���1��ʼ������y�ǽ����

Sample Input
1
12345


Sample Output
Case #1: 1
*/
#include<iostream>
#include<string>

#define LL __int64

LL a[21];

using namespace std;

LL getnum(int start_num, int end_num)
{
    LL sum = 0;
    for(int i=start_num; i<=end_num; i++)
    {
        sum = sum * 10 + a[i];
    }
    return sum;
}



int main(void)
{
    int N;
    int Case =1;
    cin>>N;
    string str;
    while(N--)
    {

        cin>>str;

        for(int i=0; i<str.length(); i++)
        {
            a[i] = str[i]-'0';
        }

        // a + b - (c*d)/e
        // 1 + 2 - (3*4)/5   max = 1

        int len = str.length();


        LL ans=a[0]+getnum(1,len-4)-a[len-3]*a[len-2]/a[len-1];
        ans=max(ans,getnum(0,len-5)+a[len-4]-a[len-3]*a[len-2]/a[len-1]);
        if(len>5)
        {
            int d=a[len-2]*10+a[len-1];
            ans=max(ans,a[0]+getnum(1,len-5)-a[len-4]*a[len-3]/d);
            ans=max(ans,getnum(0,len-6)+a[len-5]-a[len-4]*a[len-3]/d);
        }
        cout<<"Case #"<<Case++<<": "<<ans<<endl;
    }

    return 0;
}
