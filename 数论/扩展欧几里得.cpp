#include<iostream>

using namespace std;

/*
��a,b,cΪ����������������ax+by=c��һ��������Ϊ(xo,yo),���������������ⶼ����д��(xo+kb',yo-ka')
����a'=a/gcd(a,b),b'=b/gcd(a,b),kȥ��������

���ڷ���a * x + b * y = c ��˵
��a,b,cΪ����������g=gcd(a,b),����ax+by=g��һ�����(xo,yo),��c��g�ı���ʱax+bx=c��һ�����(xo*c/g��yo*c/g)��
��c����g�ı���ʱ��������
*/

/*
//���Լ��
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
//��С������
int lcm(int a, int b, int gcdNum)
{
    int lcmNum;
    lcmNum = a/gcdNum*b; //ע���ȳ��ٳ� ��ֹ���
    return lcmNum;
}

gcdNum = gcd(a, b);
cout<<gcdNum <<endl;
cout<<"��С������Ϊ��"<<endl;
cout<<lcm(a, b, gcdNum)<<endl;

*/

void exgcd(int a, int b, int &gcd, int &x, int &y)
{
    if(!b){
        gcd = a;
        x=1;
        y=0;
    }
    else{
        exgcd(b, a%b, gcd, y, x);
        y-=x*(a/b);
    }
}

int main(void)
{
    int a,b,x,y;
    int gcd_ab;
    cin>>a>>b;
    exgcd(a,b,gcd_ab,x,y);

    cout<<"gcd(a,b)="<<gcd_ab<<endl;

    cout<<"(xo,yo)="<<"("<<x<<","<<y<<")"<<" axo+byo="<<(a*x+b*y)<<endl;

    //k�������� (xo+kb',yo-ka')   a'=a/gcd(a,b),b'=b/gcd(a,b)
    cout<<"Answer(x,y):"<<endl;
    for(int k=0;k<10;k++){
        cout<<"("<<(x+k*(b/gcd_ab))<<","<<(y-k*(a/gcd_ab))<<")"<<" ax_k+by_k="<<a*(x+k*(b/gcd_ab))+b*(y-k*(a/gcd_ab))<<endl;
    }


    //���ڷ���a * x + b * y = c
    //��c��g�ı���ʱax+bx=c��һ�����(xo*c/g��yo*c/g)����c����g�ı���ʱ��������
    int c;
    cin>>c;

    if(c%gcd_ab==0){
        cout<<"(x,y)="<<"("<<x*c/gcd_ab<<","<<y*c/gcd_ab<<")"<<" ax+by="<<(a*(x*c/gcd_ab)+b*(y*c/gcd_ab))<<endl;
    }else{
        cout<<"�޽�"<<endl;
    }




}
