#include <iostream>
#include <vector>
#include<cstring>

using namespace std;

/*
如果我们没有提供拷贝构造函数,没有重载=操作符，vector 对我们的 mc 对象进行的简单的浅拷贝
将拷贝的对象插入到容器中
导致我们的 mc 对象的 data 指针和容器中mc 对象的拷贝对象中的 data 指针都指向了我们在堆区分配的内存
当函数结束，两个对象都调用了析构函数，先调用析构函数的对象成功释放了堆区内存
后调用析构函数的对象一释放，程序挂掉了。
原因在于两个指针指向了同一块堆区内存，这样会导致不可预知的结果
函数结束其中一个调用析构函数，销毁了 data 指向的内存空间
而另一个对象析构的时候就会挂掉
问题的解决办法就是，给我们的对象提供一个拷贝构造函数
并且重载=操作符,两个指针分别指向自己的那一块内存，互不影响。
*/
class Person
{
public:
    Person(const char* name, int age)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy_s(this->pName, strlen(name) + 1, name);
        this->mAge = age;
    }
    // 增加拷贝构造函数
    Person(const Person& p)
    {
        this->pName = new char[strlen(p.pName) + 1];
        strcpy_s(this->pName, strlen(p.pName) + 1, p.pName);
        this->mAge = p.mAge;
    }
    // 重载 operator=操作符
    Person& operator=(Person& p)
    {
        if (this->pName == NULL)
        {
            delete[] this->pName;
        }
        this->pName = new char[strlen(p.pName) + 1];
        strcpy_s(this->pName, strlen(p.pName) + 1, p.pName);
        this->mAge = p.mAge;
        return *this;
    }
    ~Person()
    {
        if (this->pName == NULL)
        {
            delete[] this->pName;
        }
    }
public:
    char* pName; // 指针容易浅拷贝的问题
    int mAge;
};

void test01()
{
    Person a("aaa", 20);
    vector<Person> vPerson;
    vPerson.push_back(a);
}

int main()
{
    test01();

    return 0;
}
