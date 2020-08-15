#include<iostream>
#include<vector>
#include<string>
#include<iterator>
using namespace std;
/*
�ϳɸ���ԭ��
�̳к��������ʹ����ϣ�����̳д������鷳
�˿���ͬ�ĳ���������ȥ�̳г��࣬��ʹ����ϣ�
�ѳ���Ͻ���������е���
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

