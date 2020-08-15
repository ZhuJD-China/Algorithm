#include <iostream>
using namespace std;

class Test3
{
public:
	Test3(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
		cout << "构造函数" << endl;
	}
	~Test3()
	{
		cout << "析构函数" << endl;
	}

private:
	int a;
	int b;
};

//不写，抛出所有类型异常
void myDivide()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide即将发生异常" << endl;
	throw 1;//抛出异常时，会析构t1，t2，这就是栈解旋，这样可以防止程序崩溃
}

//抛出已写类型的异常
void myDivide2() throw(int, char, char*)
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide2即将发生异常" << endl;
	throw 1;
}

//不抛出任何类型的异常
void myDivide3() throw()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide3即将发生异常" << endl;
	throw 1;
}


//异常的接口声明：目的是为了增强程序的可读性

//指定抛出异常的类型：在函数声明之后加上throw(A,B,C,D).还可抛出ABCD的子类（多态）
void my_func(int a) throw(int, double)
{
	cout << "此函数只能抛出int和double类型的异常" << endl;
	if (a>1)
	{
		throw a;
	}
	if (a < -1)
	{
		throw 0.001;
	}
	if (a == 0)
	{
		throw 'a';
	}
	cout << "a" << endl;
}

// 指定该函数不抛出异常，在函数声明后加throw()
void func2(int a) throw()
{
	cout << "此函数不能抛出异常" << endl;
	if (a>1)
	{
		// warning C4297: “func2”: 假定函数不引发异常，但确实发生了
		throw a;
	}
}

int main()
{
	try
	{
        //myDivide();//抛出异常时，程序结束
		myDivide2();

		//myDivide3();

	}
	catch (int a)
	{
		cout << "int 型异常" << endl;
	}


	try
	{
		//my_func(2);
		//my_func(-2);
		my_func(0);
		//my_func('a');
		//func2(2);
	}
	catch (int a)
	{
		cout << "catch a int:" << a << endl;
	}
	catch (double a)
	{
		cout << "catch a double:" << a << endl;
	}
	catch (char a)
	{
		cout << "catch a char:" << a << endl;
	}
	catch (...)
	{
		cout << "Unknow Error" << endl;
	}

	return 0;
}







