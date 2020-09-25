#include<iostream>
#include <queue>

using namespace std;
/*
���壺priority_queue<Type, Container, Functional>
Type �����������ͣ�Container �����������ͣ�Container������������ʵ�ֵ�������
����vector,deque�ȵȣ��������� list��STL����Ĭ���õ���vector����
Functional ���ǱȽϵķ�ʽ������Ҫ���Զ������������ʱ����Ҫ����������������
ʹ�û�����������ʱ��ֻ��Ҫ�����������ͣ�Ĭ���Ǵ󶥶ѡ�

//�������
priority_queue <int,vector<int>,greater<int> > q;
//�������
priority_queue <int,vector<int>,less<int> >q;

//greater��less��stdʵ�ֵ������º���������ʹһ�����ʹ�ÿ���ȥ��һ��������
��ʵ�־�������ʵ��һ��operator()���������������ƺ�������Ϊ������һ���º������ˣ�


top ���ʶ�ͷԪ��
empty �����Ƿ�Ϊ��
size ���ض�����Ԫ�ظ���
push ����Ԫ�ص���β (������)
emplace ԭ�ع���һ��Ԫ�ز��������
pop ������ͷԪ��
swap ��������
*/

int test_01()
{
    //���ڻ������� Ĭ���Ǵ󶥶�
    priority_queue<int> a;
    //��ͬ�� priority_queue<int, vector<int>, less<int> > a;

    //             ����һ��Ҫ�пո񣬲�Ȼ���������������
    priority_queue<int, vector<int>, greater<int> > c;  //��������С����
    priority_queue<string> b;

    for (int i = 0; i < 5; i++)
    {
        a.push(i);
        c.push(i);
    }
    while (!a.empty())
    {
        cout << a.top() << ' ';
        a.pop();
    }
    cout << endl;

    while (!c.empty())
    {
        cout << c.top() << ' ';
        c.pop();
    }
    cout << endl;

    b.push("abc");
    b.push("abcd");
    b.push("cbd");
    while (!b.empty())
    {
        cout << b.top() << ' ';
        b.pop();
    }
    cout << endl;
    return 0;
}

int test_pair()
{
    priority_queue<pair<int, int> > a;
    pair<int, int> b(1, 2);
    pair<int, int> c(1, 3);
    pair<int, int> d(2, 5);
    a.push(d);
    a.push(c);
    a.push(b);
    while (!a.empty())
    {
        cout << a.top().first << ' ' << a.top().second << '\n';
        a.pop();
    }
}

//����1
struct tmp1 //���������<
{
    int x;
    tmp1(int a)
    {
        x = a;
    }
    bool operator<(const tmp1& a) const
    {
        return x < a.x; //�󶥶�
    }
};

//����2
struct tmp2 //��д�º���
{
    bool operator() (tmp1 a, tmp1 b)
    {
        return a.x < b.x; //�󶥶�
    }
};

int test_mydefine()
{
    tmp1 a(1);
    tmp1 b(2);
    tmp1 c(3);
    priority_queue<tmp1> d;
    d.push(b);
    d.push(c);
    d.push(a);
    while (!d.empty())
    {
        cout << d.top().x << '\n';
        d.pop();
    }
    cout << endl;

    priority_queue<tmp1, vector<tmp1>, tmp2> f;
    f.push(c);
    f.push(b);
    f.push(a);
    while (!f.empty())
    {
        cout << f.top().x << '\n';
        f.pop();
    }
}


int main(void)
{
    test_01();

    test_pair();

    test_mydefine();


    return 0;
}
