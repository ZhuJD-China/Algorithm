#include <iostream>
using namespace std;

class Test3
{
public:
	Test3(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
		cout << "���캯��" << endl;
	}
	~Test3()
	{
		cout << "��������" << endl;
	}

private:
	int a;
	int b;
};

//��д���׳����������쳣
void myDivide()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide���������쳣" << endl;
	throw 1;//�׳��쳣ʱ��������t1��t2�������ջ�������������Է�ֹ�������
}

//�׳���д���͵��쳣
void myDivide2() throw(int, char, char*)
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide2���������쳣" << endl;
	throw 1;
}

//���׳��κ����͵��쳣
void myDivide3() throw()
{
	Test3 t1(1, 2), t2(3, 4);
	cout << "myDide3���������쳣" << endl;
	throw 1;
}


//�쳣�Ľӿ�������Ŀ����Ϊ����ǿ����Ŀɶ���

//ָ���׳��쳣�����ͣ��ں�������֮�����throw(A,B,C,D).�����׳�ABCD�����ࣨ��̬��
void my_func(int a) throw(int, double)
{
	cout << "�˺���ֻ���׳�int��double���͵��쳣" << endl;
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

// ָ���ú������׳��쳣���ں����������throw()
void func2(int a) throw()
{
	cout << "�˺��������׳��쳣" << endl;
	if (a>1)
	{
		// warning C4297: ��func2��: �ٶ������������쳣����ȷʵ������
		throw a;
	}
}

int main()
{
	try
	{
        //myDivide();//�׳��쳣ʱ���������
		myDivide2();

		//myDivide3();

	}
	catch (int a)
	{
		cout << "int ���쳣" << endl;
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







