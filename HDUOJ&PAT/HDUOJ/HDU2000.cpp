/*
Problem Description
���������ַ��󣬰����ַ���ASCII���С�����˳������������ַ���

Input
���������ж��飬ÿ��ռһ�У��������ַ���ɣ�֮���޿ո�

Output
����ÿ���������ݣ����һ�У��ַ��м���һ���ո�ֿ���

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
