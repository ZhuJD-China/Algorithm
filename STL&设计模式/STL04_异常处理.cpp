#include <iostream>
using namespace std;

//1 �����쳣֮���ǿ纯����
//2 �����쳣֮�󣬿��Բ��������׳�
//3 catch�쳣ʱ���������ͽ���catch
//4 �쳣��׽�ϸ�������ƥ��

//�쳣�� ջ���� �������׳��쳣ʱ��������Ӧ������������

void divide(int x, int y)
{
	if (y == 0)
	{
		throw x;//�׳�int�����쳣
	}
	cout << "divide result: " << x / y << endl;
}

//�����쳣֮���ǿ纯����
void myDivide(int x, int y)
{
	try
	{
		divide(x, y);
	}
	catch (...)
	{
		cout << "�ҽ�����divide���쳣��������������" << endl;
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
	catch (...)   // ... ���������쳣
	{
		cout << "����δ֪�����쳣" << endl;
	}

	return 0;
}

