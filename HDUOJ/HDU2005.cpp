/*
Problem Description
����һ�����ڣ������������Ǹ���ĵڼ��졣


Input
���������ж��飬ÿ��ռһ�У����ݸ�ʽΪYYYY/MM/DD��ɣ�����μ�sample input ,���⣬��������ȷ�����е����������ǺϷ��ġ�


Output
����ÿ���������ݣ����һ�У���ʾ�������Ǹ���ĵڼ��졣


Sample Input
1985/1/20
2006/3/12
2003/2/3
2004/12/12
2003/12/1

0123456789



Sample Output
20
71
*/
#include<iostream>
#include<cmath>

using namespace std;


int main(void)
{
    int monthArray[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string date;
    while(cin>>date)
    {
        int month = int(date[5]-48);
        //����·�Ϊ��λ
        if(date[6]>='0' && date[6]<='9')
           {
               month = month*10 + int(date[6]-48);

                int day = int(date[8]-48);
                if(date[9]>='0' && date[9] <= '9')
                {
                    day = day*10 +int(date[9]-48);
                }
                // �������Ǹ���ĵڼ���
                //���ж��ǲ�������
                int year=0;
                for(int i=0;i<4;i++){
                        year*=10;
                    int temp = int(date[i]-48);
                    year += temp;
                }
         int res=0 ;
                if( (year % 400 == 0) ||  (year %100!=0 && year%4==0) ){
                  //  cout<<"������"<<endl;
                  if(month>=3){
                    res+=1;
                  }

                }


                for(int i=0;i<month-1;i++){

                    res += monthArray[i];
                }
                cout<<res+day<<endl;

           }
           else{
                //����·�Ϊһλ

               int day = int(date[7]-48);
                if(date[8]>='0' && date[8] <= '9')
                {
                    day = day*10 +int(date[8]-48);
                }

                   // �������Ǹ���ĵڼ���
                //���ж��ǲ�������
                int year=0;
                for(int i=0;i<4;i++){
                        year*=10;
                    int temp = int(date[i]-48);
                    year += temp;
                }
          int res=0;
                if( (year % 400 == 0) ||  (year %100!=0 && year%4==0) ){
                   // cout<<"������"<<endl;
                       if(month>=3){
                    res+=1;
                  }

                }


              for(int i=0;i<month-1;i++){

                    res += monthArray[i];
                }
                cout<<res+day<<endl;

           }

    }

    return 0;
}
