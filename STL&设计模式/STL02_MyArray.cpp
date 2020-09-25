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
        //�����ڴ�
        this->pAddr = new T[this->mCapacity];//����һ��capacity��Ŀռ�
    }
    ~MyArray()
    {
        if (this->pAddr != NULL)
        {
            delete[]pAddr;
        }
    }
    MyArray(const MyArray& arr)//�������캯����ʹ��const����ֹ��������ı�
    {
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        //�����ڴ�ռ�
        this->pAddr = new T[this->mCapacity];
        //���ݿ���
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
        //����У��ͷſռ�
        if (this->pAddr!=NULL)
        {
            delete[] this->pAddr;
        }
        this->mSize = arr.mSize;
        this->mCapacity = arr.mCapacity;
        //�����ڴ�ռ�
        this->pAddr = new T[this->mCapacity];
        //���ݿ���
        for (int i = 0; i < this.mSize; i++)
        {
            this->pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }

    void PushBack(T& data)
    {
        //�ж��������Ƿ���λ��
        if (this->mSize >= this->mCapacity)
        {
            return;
        }
        //���ÿ���������� =�Ų���������
        //1.����Ԫ�ر����ܹ�������
        //2.��������ֵԢ�⣬��������Ԣ�⣬�������з���Ԫ�أ����Ƿ����Ԫ�صĿ����ݣ����Ǳ���
        //3.���Ԫ�صĳ�Ա��ָ�룬ע�������ǳ���������⣻
        //��� ����ָ�� ��ָ��ָ����ڴ�ռ�
        //ǳ���� �⿽��ָ��
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
    //T&&����ֵ����ȡ���ã�c++11���±�׼
    void PushBack(T&& data)
    {
        //�ж��������Ƿ���λ��
        if (this->mSize >= this->mCapacity)
        {
            return;
        }
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }

public:
    //һ���������¶��ٸ�Ԫ��
    int mCapacity;
    //��ǰ�����ж���Ԫ��
    int mSize;
    //�������ݵ��׵�ַ
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

    //���ܶ���ֵȡ����
    //��ֵ �����ڶ���ʹ��
    //��ֵ ��ʱ���� ֻ���ڵ�ǰ��ʹ��
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
