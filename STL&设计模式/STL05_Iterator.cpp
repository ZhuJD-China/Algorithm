#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int a[] = {0, 1, 2, 3};

int* Ptr = &a[(sizeof(a)/sizeof(int))];

int* Pend = &(a[3]);

void test01()
{
    if(Ptr == Pend)
        cout<<"Ptr == Pend"<<endl;
    cout<<"Ptr= "<<Ptr<<endl;
    cout<<"Pend= "<<Pend<<endl;

    for(int i=0; i<=4; i++)
    {
        cout<<&(a[i])<<endl;
    }

    vector<int> v;
    for(int i=10; i<20; i++)
        v.push_back(i);
    for(vector<int>::iterator Pbegin = v.begin(); Pbegin!=v.end(); Pbegin++)
    {
        cout<<*Pbegin<<endl;
    }
}

void test02()
{
    /*
    string_��ʼ��_ƴ��_��ֵ_����
    */

    string s1;           //Ĭ�ϳ�ʼ����s1��һ���մ�
    string s2(s1);       //s2��s1�ĸ���
    string s3("value");  //ֱ�ӳ�ʼ����s3������ֵ"value"�ĸ�������������ֵ�����Ǹ����ַ���
    string s4 = "value"; //������ʼ�����ȼ���s4("value"),s4������ֵ"value"�ĸ���
    string s5(10,'c');    //ֱ�ӳ�ʼ������s5��ʼ��Ϊ������n���ַ�'c'��ɵĴ�
    string s6 = string(5,'c');//������ʼ����s6��������ccccc

    cout<<s3+s4+s5<<endl;

    string  s7 = s3+s4+s5;

    int pos = s7.find("lue"); // ��ͷ����
    int rpos = s7.rfind("lue"); //��β��ǰ
    cout<<"pos lue "<<pos<<endl;
    cout<<"rpos lue "<<rpos<<endl;
}


void test03()
{
    /*
    string�滻_�Ƚ�_�Ӵ�_�����ɾ��
    */

    string s1("zjd");
    string s2 = "hzq";

    s1.replace(0, 1, s2);
    cout<<s1<<endl;

    string A ("aBcdef");
    string B ("AbcdEf");
    string C ("123456");
    string D ("123dfg");
    //�����Ǹ��ֱȽϷ���
    int m=A.compare (B); //������A��B�ıȽ�
    int n=A.compare(1,5,B,4,2); //"Bcdef"��"AbcdEf"�Ƚ�
    int p=A.compare(1,5,B,4,2); //"Bcdef"��"Ef"�Ƚ�
    int q=C.compare(0,3,D,0,3); //"123"��"123"�Ƚ�
    cout << "m = " << m << ", n = " << n <<", p = " << p << ", q = " << q << endl;

    const char* ss = "zjkhs";
    string sss(ss);
    cout<<sss<<endl;

    /*
     s.substr(pos, n)    ��ȡs�д�pos��ʼ������0����n���ַ����Ӵ���������

       s.substr(pos)        ��ȡs�дӴ�pos��ʼ������0����ĩβ�������ַ����Ӵ���������
    */
    string s4 = "hs";

    cout<<s4.substr(0, 1)<<endl;

    s4.insert(1, "zjdzjdzjd");  // ��pos��ǰ�����
    cout<<s4<<endl;

    string str = "hello c++! +++";
    // ��λ��pos=10����ʼɾ����ֱ����β
    // ���� " +++"
    str.erase(10);
    cout << '-' << str << '-' << endl;
    // ��λ��pos=6����ʼ��ɾ��4���ַ�
    // ��: "c++!"
    str.erase(6, 4);
    cout << '-' << str << '-' << endl;

}


int main(void)
{

    //test01();
    //test02();
    test03();
    return 0;
}
