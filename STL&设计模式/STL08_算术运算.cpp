#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

#include <algorithm> //����ʹ
#include <numeric> //��ʹ
#include <iterator>

using namespace std;
/*
accumulate�㷨 ��������Ԫ���ۼ��ܺ�
@param beg ������ʼ������
@param end ��������������
@param value�ۼ�ֵ
*/
void test01()
{
    vector<int>v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }


    //0~100�ۻ���  5050
    //����������  ��ʼ�ۼ�ֵ
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "�ܺ�Ϊ��" << sum << endl;
    cout << endl;

}

/*
fill�㷨 �����������Ԫ��
@param beg ������ʼ������
@param end ��������������
@param value t���Ԫ��
*/

void test02()
{
    vector<int>v;

    v.resize(10);

    fill(v.begin(), v.end(), 1000);

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

    cout << endl;

}



/*
set_intersection�㷨 ������set���ϵĽ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
void test03()
{
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    vTarget.resize( min(v1.size(),v2.size()));

    vector<int>::iterator itEnd= set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));

    cout << endl;

}

/*
set_union�㷨 ������set���ϵĲ���
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
void test04()
{
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    vTarget.resize(v1.size()+v2.size());

    vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));

    cout << endl;

}


/*
set_difference�㷨 ������set���ϵĲ
ע��:�������ϱ�������������
@param beg1 ����1��ʼ������
@param end1 ����1����������
@param beg2 ����2��ʼ������
@param end2 ����2����������
@param dest  Ŀ��������ʼ������
@return Ŀ�����������һ��Ԫ�صĵ�������ַ
*/
void test05()
{
    vector<int>v1;
    vector<int>v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 5);
    }

    vector<int> vTarget;
    vTarget.resize( max(v1.size(),v2.size() ));

    //v1��v2
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    //v2 �� v1
    itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));

    cout << endl;

}


int main(void)
{
    test01();
    test02();
    test03();
    test04();
    test05();

    return 0;
}


