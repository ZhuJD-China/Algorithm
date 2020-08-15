#include<iostream>
#include<string>
using namespace std;

class MyException//异常类
{
public:
    MyException(string& msg) :_msg(msg)
    {
        cout << "MyException()构造函数" << endl;
    }
    ~MyException()
    {
        cout << "~MyException()析构函数" << endl;
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
    throw MyException(s);//抛出异常，传递给上层，fun1()在此跳出
    cout << "Exit Fun1()---------" << endl;//此句不会被执行
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
        throw;//此处继续将该异常抛出，传递到更上层
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
