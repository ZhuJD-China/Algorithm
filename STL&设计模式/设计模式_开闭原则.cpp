/*
ʹ�ÿ���ԭ��Ϳ�����ʵ�ʿ��������У��ÿ�����Ա��Ȼ��Ȼ�Ĳ����뵽ֱ���޸Ĵ��룬����ͨ����չ������ʵ������

�ȷ�˵�������������������������Ĺ��ܣ�
�����������ֻ��һ���������࣬����������мӡ������ˡ������ַ�����
��ô�������������������Ȼ��Ȼ���뵽�ڼ���������������ķ������������޸������ǵ�Դ���롣
��ʹ���˿���ԭ�򣬸����еĴ��麯������һ����ֵ�Ľӿ�getompute��
������Ա�ͻ�����һ���µ����࣬��������Ĳ����������Ͳ���ֱ���޸�Դ���롣
*/

#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;

//��������
class Calculator
{
public:
    //����ӿ��࣬����ʵ��
    virtual double getompute() = 0;
    virtual void getParam(double a, double b) = 0;
};

//��
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
//��
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
//��
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
//��
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

//������ƽ��ֵ
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
