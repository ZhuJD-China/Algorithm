/*
依赖倒置原则的原始定义：高层模块不应该依赖于低层模块，二者都应该依赖于抽象；
抽象不应该依赖于细节，细节应该依赖于抽象

核心思想
依赖倒置原则的核心思想：要面向接口编程，不要面向实现编程。


*/

#include <iostream>

using namespace std;

//高层抽象
class Business
{
public:
    virtual void GeneralService() = 0;
};

class TransferAccounts :public Business//办理转账业务
{
public :
    void GeneralService()
    {
        cout << "办理转账业务" << endl;
    }
};


class SaveMoney :public Business//办理存钱业务
{
public:
    void GeneralService()
    {
        cout << "办理存钱业务" << endl;
    }
};

class DrawMoney :public Business//办理取钱业务
{
public:
    void GeneralService()
    {
        cout << "办理取钱业务" << endl;
    }
};

//中层逻辑
void test(Business*my)
{
    my->GeneralService();
    delete my;
}


//业务逻辑
void test01()
{
    test(new TransferAccounts);
    test(new SaveMoney);
    test(new DrawMoney);
}

int main(void)
{
    test01();

    return 0;
}
