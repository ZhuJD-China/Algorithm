#include <iostream>
using namespace std;

int getWeek(int y,int m,int d)   //���û�ķ����ɭ���㹫ʽ��������ڼ�
{
    if(m==1 || m==2)
    {
        m += 12;
        y--;
    }
    return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7+1;
}

int main()
{

    int y,m,d;
    cin >> y >> m >> d;
    cout << getWeek(y,m,d) << endl;
    return 0;
}

