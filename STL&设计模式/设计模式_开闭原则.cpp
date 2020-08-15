/*
使用开闭原则就可以在实际开发过程中，让开发人员自然而然的不会想到直接修改代码，而是通过扩展功能来实现需求。

比方说，在这个基础上我想增加求根的功能：
如果咱们现在只有一个计算器类，这个类里面有加、减、乘、除四种方法，
那么想增加求根功能我们自然而然会想到在计算器中增加求根的方法，这样就修改了我们的源代码。
而使用了开闭原则，父类中的纯虚函数就有一个求值的接口getompute，
开发人员就会增加一个新的子类，进行求根的操作，这样就不会直接修改源代码。
*/

#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

//计算器类
class Calculator
{
public:
    //抽象接口类，子类实现
    virtual double getompute() = 0;
    virtual void getParam(double a, double b) = 0;
};

//除
class Division : public Calculator
{
public:
    virtual double getompute()
    {
        return mA / mB;
    }

    virtual void getParam(double a, double b)
    {
        mA = a;
        mB = b;
    }
private:
    double mA;
    double mB;
};
//乘
class Multiplication : public Calculator
{
public:
    virtual double getompute()
    {
        return mA * mB;
    }
    virtual void getParam(double a, double b)
    {
        mA = a;
        mB = b;
    }
private:
    double mA;
    double mB;
};
//减
class Subtraction : public Calculator
{
public:
    virtual double getompute()
    {
        return mA - mB;
    }
    virtual void getParam(double a, double b)
    {
        mA = a;
        mB = b;
    }
private:
    double mA;
    double mB;
};
//加
class Addition : public Calculator
{
public:
    virtual double getompute()
    {
        return mA + mB;
    }
    virtual void getParam(double a, double b)
    {
        mA = a;
        mB = b;
    }
private:
    double mA;
    double mB;
};

//求算术平均值
class Sqrtion : public Calculator
{
public:
    virtual double getompute()
    {
        return sqrt(pow(mA, 2) + pow(mB, 2));
    }
    virtual void getParam(double a, double b)
    {
        mA = a;
        mB = b;
    }
private:
    double mA;
    double mB;
};

int main()
{
    Calculator* Add = new Addition;
    Add->getParam(1,2);
    double c = Add->getompute();

    cout << c << endl;

    Calculator* mySqrt = new Sqrtion;
    mySqrt->getParam(3.2, 4.2);
    double res = mySqrt->getompute();
    cout<<"res= "<<res<<endl;

    return 0;
}
