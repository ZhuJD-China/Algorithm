#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>

#include <algorithm> //不好使
#include <numeric> //好使
#include <iterator>

using namespace std;
/*
accumulate算法 计算容器元素累计总和
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value累加值
*/
void test01()
{
    vector<int>v;
    for (int i = 0; i <= 100; i++)
    {
        v.push_back(i);
    }


    //0~100累积和  5050
    //第三个参数  起始累加值
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "总和为：" << sum << endl;
    cout << endl;

}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
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
set_intersection算法 求两个set集合的交集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
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
set_union算法 求两个set集合的并集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
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
set_difference算法 求两个set集合的差集
注意:两个集合必须是有序序列
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
@return 目标容器的最后一个元素的迭代器地址
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

    //v1差v2
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
    cout << endl;

    //v2 差 v1
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


