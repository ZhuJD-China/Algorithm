#include<iostream>
using namespace std;

//函数模板
template<typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}


//类模板
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


//类模板外部实现
template <typename T>
class Person
{
public:
    T age;
public:
    /* C++中的explicit关键字只能用于修饰只有一个参数的类构造函数,
    它的作用是表明该构造函数是显示的, 而非隐式的, 跟它相对应的另一个关键字是implicit,
     意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).*/
    explicit Person(T newAge);
    void show();
};

//类模版函数在外部定义时，必须加上template标识
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


    Person<int> p(20);  //必须注明类实例化的类型
    p.show();

    return 0;
}
