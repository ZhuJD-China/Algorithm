#include<iostream>
#include<string>
using namespace std;

class MyException//�쳣��
{
public:
    MyException(string& msg) :_msg(msg)
    {
        cout << "MyException()���캯��" << endl;
    }
    ~MyException()
    {
        cout << "~MyException()��������" << endl;
    }
    string& getmsg()
    {
        return _msg;
    }
private:
    string _msg;
};

class demo
{
public:
    demo()
    {
        cout << "demo()" << endl;
    }
    ~demo()
    {
        cout << "~demo()" << endl;
    }
};

void fun1()
{
    cout << "Enter fun1()---------" << endl;
    demo d;
    cout << "Throw a MyException in fun1" << endl;
    string s("A MyException throw by fun1");
    throw MyException(s);//�׳��쳣�����ݸ��ϲ㣬fun1()�ڴ�����
    cout << "Exit Fun1()---------" << endl;//�˾䲻�ᱻִ��
}

void fun2()
{
    cout << "Enter fun2()---------" << endl;
    try
    {
        fun1();
    }
    catch (MyException& e)
    {
        cout << e.getmsg() << " deal with fun2()" << endl;
        throw;//�˴����������쳣�׳������ݵ����ϲ�
    }
    cout << "Exit fun2()----------" << endl;
}
int main()
{
    try
    {
        fun2();
    }
    catch (MyException& e)
    {
        cout << e.getmsg() << "deal with main()" << endl;
    }
    cout << "Exit main()" << endl;

    return 0;
}
