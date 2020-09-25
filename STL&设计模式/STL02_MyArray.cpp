#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    MyArray(int capacity)
    {
        this->mCapacity = capacity;
        this->mSize = 0;
        //申请内存
        this->pAddr = new T[this->mCapacity];//初试一个capacity大的空间
    }
    ~MyArray()
    {
        if (this->pAddr != NULL)
        {
            delete[]pAddr;
        }
    }
    MyArray(const MyArray& arr)//拷贝构造函数，使用const，防止传入参数改变
    {
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        //申请内存空间
        this->pAddr = new T[this->mCapacity];
        //数据拷贝
        for (int i = 0; i < this.mSize; i++)
        {
            this->pAddr[i] = arr.pAddr[i];
        }
    }

    T& operator[](int index)
    {
        return this->pAddr[index];
    }

    MyArray<T> operator=(const MyArray<T>& arr)
    {
        //如果有，释放空间
        if (this->pAddr!=NULL)
        {
            delete[] this->pAddr;
        }
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        //申请内存空间
        this->pAddr = new T[this->mCapacity];
        //数据拷贝
        for (int i = 0; i < this.mSize; i++)
        {
            this->pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }

    void PushBack(T& data)
    {
        //判断容器中是否有位置
        if (this->mSize >= this->mCapacity)
        {
            return;
        }
        //调用拷贝构造后者 =号操作符重载
        //1.对象元素必须能够被拷贝
        //2.容器都是值寓意，而非引用寓意，向容器中放入元素，都是放入的元素的拷贝份，而非本身
        //3.如果元素的成员有指针，注意深拷贝和浅拷贝的问题；
        //深拷贝 拷贝指针 和指针指向的内存空间
        //浅拷贝 光拷贝指针
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    //T&&对右值进行取引用，c++11的新标准
    void PushBack(T&& data)
    {
        //判断容器中是否有位置
        if (this->mSize >= this->mCapacity)
        {
            return;
        }
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }

public:
    //一共可以容下多少个元素
    int mCapacity;
    //当前数组有多少元素
    int mSize;
    //保存数据的首地址
    T* pAddr;
};



void test01()
{
    MyArray<int>marray(20);
    int a = 10, b = 20, c = 30, d = 40;
    marray.PushBack(a);
    marray.PushBack(b);
    marray.PushBack(c);
    marray.PushBack(d);

    //不能对右值取引用
    //左值 可以在多行使用
    //右值 临时变量 只能在当前行使用
    marray.PushBack(100);
    marray.PushBack(200);
    marray.PushBack(300);

    for (int i = 0; i < marray.mSize; i++)
    {
        cout << marray[i] << " ";
    }
    cout << endl;
}

class Person {};


void test02()
{
    Person p1, p2;
    MyArray<Person>arr(10);
    arr.PushBack(p1);
    arr.PushBack(p2);

}
int main()
{
    cout<<"hello world"<<endl;
    test01();
    test02();
    return 0;
}
