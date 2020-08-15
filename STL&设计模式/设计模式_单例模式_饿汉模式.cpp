/*
单例类定义的时候就进行实例化

这又是什么意思呢？像一个饿汉一样，不管需不需要用到实例都要去创建实例，
即在类产生的时候就创建好实例，这是一种空间换时间的做法。
作为一个饿汉而言，体现了它的本质——“我全都要”

在饿汉模式中，实例对象储存在全局数据区，所以要用static来修饰，所以对于饿汉模式来说，
是线程安全的，因为在线程创建之前实例就已经创建好了。

*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class singleton
{
private:
	static singleton* instance; //这是我们的单例对象，它是一个类对象的指针
	singleton()
	{
		cout << "创建一个单例对象" << endl;
	}
	~singleton()
	{
		cout << "析构掉一个单例对象" << endl;
	}
public:
	static singleton* getinstance();
};

//下面这个静态成员变量在类加载的时候就已经初始化好了
singleton* singleton::instance = new singleton();

singleton* singleton::getinstance()
{
	return instance;  //直接返回inatance
}
int main()
{
	cout << "we get the instance" << endl;
	singleton* a1 = singleton::getinstance();
	singleton* a2 = singleton::getinstance();
	singleton* a3 = singleton::getinstance();
	cout << "we destroy the instance" << endl;
	system("pause");
	return 0;
}
