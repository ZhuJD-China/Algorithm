/*
单例模式是一种常见的软件设计模式。它的核心结构只包含一个被称为单例的特殊类。
它的目的是保证一个类仅有一个实例，并提供一个访问它的全局访问点，该实例被所有程序模块共享。

有很多地方都需要这样的功能模块，如系统的日志输出，操作系统只能有一个窗口管理器，一台PC连接一个键盘等。

单例模式是通过类本身来管理其唯一实例，这种特性提供了解决问题的办法。
唯一的实例是类的一个普通对象，但涉及这个类的时候，让它只能创建一个实例并提供对此实例的全局访问。
创建实例的操作我们通常把这个成员函数叫做instance(),他的返回值是唯一实例的指针，
另外，我们可以提供一个public静态方法来帮助我们获得这个类的唯一的一个实例化对象
*/


/*
 单例模式的懒汉模式
咱先记住第一句话：第一次用到类的实例的时候才回去实例化

什么意思呢？像一个懒汉一样，需要用到创建实例了的程序再去创建实例，不需要创建实例程序就不去创建实例，
这是一个时间换空间的做法，同时体现了懒汉本性。

实现方法：定义一个单例类，使用类的私有静态指针变量指向类的唯一实例，并用一个公有的静态方法获取该实例。
*/
#include <iostream>
#include <stdlib.h>
using namespace std;

class singleton  //实现单例模式的类
{
private:
    singleton() //私有的构造函数,这样就不能再其他地方创建该实例
    {

    }
    static singleton* instance;  //定义一个唯一指向实例的指针，并且是私有的
    static int b;
public:
    static singleton* GetInstance()  //定义一个公有函数，可以获取这个唯一实例
    {
        if (instance == NULL)  //判断是不是第一次使用
            instance = new singleton;
        return instance;
    }
    static void show()
    {
        cout << b << endl;
    }
};
int singleton::b = 10; //静态成员变量在类外进行初始化，它是整个类的一部分并不属于某个类
singleton* singleton::instance = NULL;
int main()
{
    singleton* a1 = singleton::GetInstance();
    cout << a1 << endl;
    a1->show();

    singleton* a2 = singleton::GetInstance();
    cout << a2 << endl;
    a2->show();
    system("pause");
    return 0;
}
