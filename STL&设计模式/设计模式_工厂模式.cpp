//工厂方法模式
//我们让F1工厂去生产苹果、F2生产香蕉
/*
工厂方法模式
  一个工厂只能生产一种产品。
  适用于规模不固定、产品有变化的。
*/
#include<iostream>

class Fruit
{
public:
    Fruit(std::string nm)
        :mname(nm) {}
    virtual void operation() = 0;
protected:
    std::string mname;
};

class Apple :public Fruit
{
public:
    Apple(std::string name)
        : Fruit(name) {}
    void operation()
    {
        std::cout << "this is an Apple!" << std::endl;
    }
};

class Banana :public Fruit
{
public:
    Banana(std::string name)
        :Fruit(name) {}
    void operation()
    {
        std::cout << "this is a Banana!" << std::endl;
    }
};

class Factory
{
public:
    Factory(std::string name)
        :mname(name) {}
    virtual Fruit* createFruit() = 0;
protected:
    std::string mname;
};

class F1 :public Factory
{
public:
    F1(std::string name)
        :Factory(name) {}
    Fruit* createFruit()
    {
        return new Apple("apple");
    }
};

class F2 :public Factory
{
public:
    F2(std::string name)
        :Factory(name) {}
    Fruit* createFruit()
    {
        return new Banana("banana");
    }
};

int main()
{
    Factory* pfa = new F1("f1");
    Fruit* pf = pfa->createFruit();
    pf->operation();

    std::cout<<"---------------"<<std::endl;

    Factory* pfa2 = new F2("f2");
    Fruit* pf2 = pfa2->createFruit();
    pf2->operation();
    return 0;
}
