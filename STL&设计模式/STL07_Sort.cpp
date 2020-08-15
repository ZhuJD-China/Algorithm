#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<ctime>
#include<list>

using namespace std;

//���������㷨 sort
void myPrint(int val)
{
    cout << val << " ";
}

//������Ϊ����
struct MyCompare
{
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};


void test01()
{
    cout<<"sort()"<<endl;
    vector<int>v;

    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    //����sort��������
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    //�ı�Ϊ ����
//   sort(v.begin(), v.end(), greater<int>());
    sort(v.begin(), v.end(), MyCompare());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

void test02()
{
    cout<<"random_shuffle()"<<endl;
    srand((unsigned int)time(NULL));

    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    //����ϴ�� �㷨 ����˳��
    random_shuffle(v.begin(), v.end());

    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

void test03()
{
    cout<<"merge()"<<endl;

    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }

    //Ŀ������
    vector<int>vTarget;

    //��ǰ��Ŀ����������ռ�
    vTarget.resize(v1.size() + v2.size());

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout << endl;

}


void test04()
{

    cout<<"reverse()"<<endl;

    vector<int>v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "��תǰ��" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

    cout << "��ת�� " << endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;

}


void test05()
{
    cout<<"merge() v1 ,l2"<<endl;

    vector<int>v1;
    list<int>l2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        l2.push_back(i+1);
    }

    //Ŀ������
    vector<int>vTarget;

    //��ǰ��Ŀ����������ռ�
    vTarget.resize(v1.size() + l2.size());

    merge(v1.begin(), v1.end(), l2.begin(), l2.end(), vTarget.begin());

    for_each(vTarget.begin(), vTarget.end(), myPrint);
    cout << endl;

}

void test06()
{
    cout<<"copy()"<<endl;

    srand((unsigned int)time(NULL));

    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(rand() % 10);
    }
    v2.resize(v1.size());
    cout<<"v1: ";
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;

    copy(v1.begin(), v1.end(), v2.begin());

    cout<<"v2: ";
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl;

}


void test07()
{
    cout<<"swap()"<<endl;

    vector<int> v1;
    vector<int> v2;
    for(int i=0; i<10; i++)
    {
        v1.push_back(rand() % 10);
        v2.push_back(rand() % 100);
    }

    cout<<"Before swap"<<endl;
    cout<<"v1: ";
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;

    cout<<"v2: ";
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl;

    swap(v1, v2);

    cout<<"After swap"<<endl;
    cout<<"v1: ";
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;

    cout<<"v2: ";
    for_each(v2.begin(), v2.end(), myPrint);
    cout<<endl;
}

struct replace_compare
{
    bool operator()(int val)
    {
        return val < 5;
    }
};

void test08()
{
    cout<<"replace()"<<endl;

    vector<int> v1;

    for(int i=0; i<10; i++)
    {
        v1.push_back(rand() % 10);
    }

    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;
    replace(v1.begin(), v1.end(), 7, 99999);
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;


    cout<<"replace_if()"<<endl;
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;
    replace_if(v1.begin(), v1.end(), replace_compare(), -1000);
    for_each(v1.begin(), v1.end(), myPrint);
    cout<<endl;


}

int main()
{

    test01();
    test02();
    test03();
    test04();
    test05();

    test06();

    test07();

    test08();
    return 0;
}
