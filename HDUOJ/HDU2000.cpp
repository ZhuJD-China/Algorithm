/*
Problem Description
输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。

Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。

Output
对于每组输入数据，输出一行，字符中间用一个空格分开。

Sample Input
qwe
asd
zxc

Sample Output
e q w
a d s
c x z
*/

#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main(void)
{
        char res[3];
        memset(res, 0, sizeof(res));
    while(cin>>res[0]>>res[1]>>res[2])
    {
/*
        for(int i=0;i<3;i++){
            //scanf("%c", &res[i]);
            cin>>res[i];
        }
*/
        sort(res, res+3);
/*
        for(int i=0;i<3;i++){
            printf("%c", res[i]);
            if(i!=2){cout<<" ";}
        }
        cout<<endl;
*/

        printf("%c %c %c\n", res[0], res[1], res[2]);

    }


    return 0 ;
}
