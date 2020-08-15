#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;
/*
合成复用原则：
继承和组合优先使用组合，避免继承带来的麻烦
人开不同的车，不必人去继承车类，而使用组合，
把车组合进人里面进行调用
*/
class AbstractCar
{
public:
    virtual void run()=0;
};

class BMW : public AbstractCar
{
public:
    virtual void run()
    {
        cout << "BMW is run."<<endl;
    }
};

class Fort : public AbstractCar
{
public:
    virtual void run()
    {
        cout << "Fort is run."<<endl;
    }
};

class People
{
public:
    void setCar(AbstractCar* car)
    {
        this->car=car;
    }
    void Drive()
    {
        car->run();
        delete car;
    }
private:
    AbstractCar * car;
};

void test()
{
    People* p=new People();
    p->setCar(new BMW());
    p->Drive();
    p->setCar(new Fort());
    p->Drive();
}
int main()
{
    test();
    return 0;
}

