#include<iostream>
using namespace std;

//����ģ��
template<typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


//��ģ��
template<class T>
class Person1
{
public:
    Person1(T age, T id)
    {
        this->Myage = age;
        this->Myid = id;
    }
    void showinfo()
    {
        cout<<"age= "<<this->Myage<<" id= "<<this->Myid<<endl;
    }
private:
    T Myage;
    T Myid;
};


//��ģ���ⲿʵ��
template <typename T>
class Person
{
public:
    T age;
public:
    /* C++�е�explicit�ؼ���ֻ����������ֻ��һ���������๹�캯��,
    ���������Ǳ����ù��캯������ʾ��, ������ʽ��, �������Ӧ����һ���ؼ�����implicit,
     ��˼�����ص�,�๹�캯��Ĭ������¼�����Ϊimplicit(��ʽ).*/
    explicit Person(T newAge);
    void show();
};

//��ģ�溯�����ⲿ����ʱ���������template��ʶ
template <typename T>
Person<T>::Person(T newAge)
{
    this->age = newAge;
}

template <typename T>
void Person<T>::show()
{
    cout<<age<<endl;
}



int main(void)
{
    int a, b;
    cout<<"a= "<<a<<" b= "<<b<<endl;

    Swap(a, b);

    cout<<"a= "<<a<<" b= "<<b<<endl;

    cout<<"----------------------------------"<<endl;

    Person1<int> zjd(21, 01);

    zjd.showinfo();
    cout<<"----------------------------------"<<endl;


    Person<int> p(20);  //����ע����ʵ����������
    p.show();

    return 0;
}
