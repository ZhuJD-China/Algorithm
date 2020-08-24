#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int mylower_bound(int *A, int x, int y, int v)
{
    int m;
    while(x<y){
        m = x+(y-x)/2;
        if(A[m]>=v) y=m;
        else x=m+1;
    }
    return x;
}

int myupper_bound(int *A, int x, int y, int v)
{
    int m;
    while(x<y){
        m = x+(y-x)/2;
        if(A[m]<=v) x=m+1;
        else y=m;
    }
    return x;
}

int main(void)
{
    int a[10]={3, 4, 4, 4, 2, 12, 43, 33, 66, 88};

    sort(a,a+10);

    for(int i=0;i<10;i++)   cout<<a[i]<<" ";
    cout<<endl;

    int L_res = mylower_bound(a, 0, 10, 4);

    int R_res = myupper_bound(a, 0, 10, 4);

    cout<<"["<<L_res<<", "<<R_res<<")"<<endl;



    return 0;
}
