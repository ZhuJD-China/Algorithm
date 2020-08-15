#include<iostream>
 #include<string>
 using namespace std;

 //系统提供标准异常
 #include<stdexcept>


 class Person
 {
 public:
 	Person(string name, int age)
 	{
 		this->m_Name = name;
 		//年龄做检测

 		if (age<0 || age>200)
 		{
 			//抛出越界异常
 			//throw out_of_range("年龄越界了");

 			throw length_error("长度越界了");
 		}
 	}

 	string m_Name;
 	int m_Age;
 };

 void test01()
 {
 	try
 	{
 		Person p("张三", 300);
 	}
 	catch (out_of_range &e)
 	{
 		cout << e.what()<<endl;
 	}
 	catch (length_error &e)
 	{
 		cout << e.what() << endl;
 	}
 }


 int main()
 {
 	test01();

 	return 0;
 }
