/*
Problem Description
���еĶ������£�
���еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�

Input
���������ж��飬ÿ��ռһ�У�����������n��n<10000����m(m<1000)��ɣ�n��m�ĺ�����ǰ������

Output
����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����

Sample Input
81 4
2 2


Sample Output
94.73
3.41

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
//    double num;
//    cin>>num;
//    printf("%.2f\n", sqrt(num));
    double N, M;
    while(cin>>N>>M)
    {
        double res = N;
        for(int i=0;i<M-1;i++){
            double temp = sqrt(N);
           // cout<<temp<<" ";
            res += temp;
            N = temp;
        }
        //cout<<endl;
        //cout<<"res= "<<res<<endl;
        printf("%.2f\n", res);
    }


    return 0;
}
