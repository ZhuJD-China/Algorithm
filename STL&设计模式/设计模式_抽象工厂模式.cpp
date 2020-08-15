/*
抽象工厂模式其实是用来创建一组相互依赖的对象。
  假设我们要生产13.5的笔记本和15.6的笔记本，
那么需要生产对应的13.5和15.6的屏幕以及13.5和15.6的外壳。
也就是现在需要生产A（13.5的笔记本）、B（15.6的笔记本）两种的产品，
A产品需要生产A1（13.5的屏幕）、B1（13.5的外壳）；
B产品需要生产A2（15.6的屏幕）、B2（15.6的外壳）。
*/
#include<iostream>
//抽象工厂模式
class A
{
public:
    A(std::string nm)
        :mname(nm) {}
    virtual void operation() = 0;
protected:
    std::string mname;
};

class A1 :public A
{
public:
    A1(std::string nm)
        :A(nm)
    {}
    virtual void operation()
    {
        std::cout << "a1" << std::endl;
    }
};

class A2 :public A
{
public:
    A2(std::string nm)
        :A(nm)
    {}
    virtual void operation()
    {
        std::cout << "a2" << std::endl;
    }
};

class B
{
public:
    B(std::string nm)
        :mname(nm) {}
    virtual void operation() = 0;
protected:
    std::string mname;
};

class B1 :public B
{
public:
    B1(std::string nm)
        :B(nm)
    {}
    virtual void operation()
    {
        std::cout << "b1" << std::endl;
    }
};

class B2 :public B
{
public:
    B2(std::string nm)
        :B(nm)
    {}
    virtual void operation()
    {
        std::cout << "b2" << std::endl;
    }
};

class AbstactFactory
{
public:
    AbstactFactory(std::string nm)
        :mname(nm)
    {}
    virtual A*createA() = 0;
    virtual B*createB() = 0;
protected:
    std::string mname;
};

//一号工厂产A产品  需要A1 B1
class Factory1 :public AbstactFactory
{
public:
    Factory1(std::string name)
        :AbstactFactory(name)
    {}
    virtual A* createA()
    {
        return new A1("a1");
    }
    virtual B* createB()
    {
        return new B1("b1");
    }
};

//二号工厂产B产品  需要A2 B2
class Factory2 :public AbstactFactory
{
public:
    Factory2(std::string name)
        :AbstactFactory(name)
    {}
    virtual A* createA()
    {
        return new A2("a2");
    }
    virtual B* createB()
    {
        return new B2("b2");
    }
};

int main()
{
    //建工厂去生产A产品，需要a1 b1
    AbstactFactory* paf = new Factory1("f1");
    A* pa = paf->createA();
    B* pb = paf->createB();

    pa->operation();
    pb->operation();

    return 0;
}
