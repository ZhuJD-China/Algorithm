/*
输入将以一个单一的整数1 <= N <= 20开始，表示要跟随的测试用例数量。
然后跟随N行，每行描述一个测试用例。每个测试用例都以一个整数1 <= K <= 10开始，表示测试用例中电源条的数量。
然后，在同一行上，接着是K个整数，用空格隔开，O1 O2 ......。OK，其中2 <= Oi <= 10，表示每个电源条的插座数量。

每个测试用例输出一行，最大可供电的电器数量。

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
