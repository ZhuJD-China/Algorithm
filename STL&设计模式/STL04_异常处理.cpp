#include <iostream>
using namespace std;

//1 发生异常之后，是跨函数的
//2 接收异常之后，可以不处理，再抛出
//3 catch异常时，按照类型进行catch
//4 异常捕捉严格按照类型匹配

//异常的 栈解旋 就是在抛出异常时，调用相应的析构函数。

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;//抛出int类型异常
	}
	cout << "divide result: " << x / y << endl;
}

//发生异常之后，是跨函数的
void myDivide(int x, int y)
{
	try
	{
		divide(x, y);
	}
	catch (...)
	{
		cout << "我接收了divide的异常，不处理往上抛" << endl;
		throw;
	}
}

int main()
{
	try
	{
		divide(10, 2);
		//divide(100, 0);

		myDivide(20, 0);
	}
	catch (const int e)
	{
		cout << e << " is divided by 0!" << endl;
	}
	catch (...)   // ... 捕获所以异常
	{
		cout << "其他未知类型异常" << endl;
	}

	return 0;
}

