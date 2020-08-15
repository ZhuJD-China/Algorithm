/*
迪米特法则（Law of Demeter）又叫作最少知识原则（Least Knowledge Principle 简写LKP)
就是说一个对象应当对其他对象有尽可能少的了解,不和陌生人说话
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class AbstractBuilding
{
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;

};

class BuildingA :public AbstractBuilding
{
public:

    BuildingA()
    {
        mQulity = "高品质";
    }

    virtual void sale()
    {
        cout << "楼盘A" << mQulity << "被售卖!" << endl;
    }

    virtual string getQuality()
    {
        return mQulity;
    }

public:
    string mQulity;
};


class BuildingB :public AbstractBuilding
{
public:

    BuildingB()
    {
        mQulity = "低品质";
    }

    virtual void sale()
    {
        cout << "楼盘B" << mQulity << "被售卖!" << endl;
    }

    virtual string getQuality()
    {
        return mQulity;
    }

public:
    string mQulity;
};

// 中介类
class Mediator
{
public:
    Mediator()
    {
        AbstractBuilding* building = new BuildingA;
        vBuilding.push_back(building);
        building = new BuildingB;
        vBuilding.push_back(building);
    }

    // 对外提供接口
    AbstractBuilding* findMyBuilding(string quality)
    {
        for (vector<AbstractBuilding*>::iterator it = vBuilding.begin();
                it != vBuilding.end(); it++)
        {
            if ((*it)->getQuality() == quality)
            {
                return *it;
            }
        }

        return NULL;
    }

    ~Mediator()
    {
        for (vector<AbstractBuilding*>::iterator it = vBuilding.begin();
                it != vBuilding.end(); it++)
        {
            if (*it != NULL)
                delete *it;
        }
    }
public:
    vector<AbstractBuilding*> vBuilding;
};


void test01()
{
    Mediator* mediator = new Mediator;

    AbstractBuilding* building = mediator->findMyBuilding("低品质");

    if (building != NULL)
    {
        building->sale();

    }
    else
    {
        cout << "没有符号条件的楼盘" << endl;
    }

}

int main()
{
    test01();
    system("pause");
}
