#include<iostream>

using namespace std;

/*
设a,b,c为任意整数，若方程ax+by=c的一组整数解为(xo,yo),则它的任意整数解都可以写成(xo+kb',yo-ka')
其中a'=a/gcd(a,b),b'=b/gcd(a,b),k去任意整数

对于方程a * x + b * y = c 来说
设a,b,c为任意整数，g=gcd(a,b),方程ax+by=g的一组解是(xo,yo),则当c是g的倍数时ax+bx=c的一组解是(xo*c/g，yo*c/g)。
当c不是g的倍数时无整数解
*/

/*
//最大公约数
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
//最小公倍数
int lcm(int a, int b, int gcdNum)
{
    int lcmNum;
    lcmNum = a/gcdNum*b; //注意先除再乘 防止溢出
    return lcmNum;
}

gcdNum = gcd(a, b);
cout<<gcdNum <<endl;
cout<<"最小公倍数为："<<endl;
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

    //k任意整数 (xo+kb',yo-ka')   a'=a/gcd(a,b),b'=b/gcd(a,b)
    cout<<"Answer(x,y):"<<endl;
    for(int k=0;k<10;k++){
        cout<<"("<<(x+k*(b/gcd_ab))<<","<<(y-k*(a/gcd_ab))<<")"<<" ax_k+by_k="<<a*(x+k*(b/gcd_ab))+b*(y-k*(a/gcd_ab))<<endl;
    }


    //对于方程a * x + b * y = c
    //当c是g的倍数时ax+bx=c的一组解是(xo*c/g，yo*c/g)。当c不是g的倍数时无整数解
    int c;
    cin>>c;

    if(c%gcd_ab==0){
        cout<<"(x,y)="<<"("<<x*c/gcd_ab<<","<<y*c/gcd_ab<<")"<<" ax+by="<<(a*(x*c/gcd_ab)+b*(y*c/gcd_ab))<<endl;
    }else{
        cout<<"无解"<<endl;
    }




}
