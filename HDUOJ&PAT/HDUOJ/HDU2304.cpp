/*
���뽫��һ����һ������1 <= N <= 20��ʼ����ʾҪ����Ĳ�������������
Ȼ�����N�У�ÿ������һ������������ÿ��������������һ������1 <= K <= 10��ʼ����ʾ���������е�Դ����������
Ȼ����ͬһ���ϣ�������K���������ÿո������O1 O2 ......��OK������2 <= Oi <= 10����ʾÿ����Դ���Ĳ���������

ÿ�������������һ�У����ɹ���ĵ���������

Sample Input
3
3 2 3 4
10 4 4 4 4 4 4 4 4 4 4
4 10 10 10 10

Sample Output
7
31
37
*/
#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{

    int N;
    cin>>N;
    while(N){
       int k;
       cin>>k;
       int O[k];
       memset(O, 0, sizeof(O));
       int sum = 0;
       for(int i=0;i<k;i++){
        cin>>O[i];
        sum += O[i];
       }
       sum -= (k-1);
       cout<<sum<<endl;

       N--;
    }

    return 0;
}
