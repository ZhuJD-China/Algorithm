/*
�����ط���Law of Demeter���ֽ�������֪ʶԭ��Least Knowledge Principle ��дLKP)
����˵һ������Ӧ�������������о������ٵ��˽�,����İ����˵��
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
        mQulity = "��Ʒ��";
    }

    virtual void sale()
    {
        cout << "¥��A" << mQulity << "������!" << endl;
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
        mQulity = "��Ʒ��";
    }

    virtual void sale()
    {
        cout << "¥��B" << mQulity << "������!" << endl;
    }

    virtual string getQuality()
    {
        return mQulity;
    }

public:
    string mQulity;
};

// �н���
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

    // �����ṩ�ӿ�
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

    AbstractBuilding* building = mediator->findMyBuilding("��Ʒ��");

    if (building != NULL)
    {
        building->sale();

    }
    else
    {
        cout << "û�з���������¥��" << endl;
    }

}

int main()
{
    test01();
    system("pause");
}
