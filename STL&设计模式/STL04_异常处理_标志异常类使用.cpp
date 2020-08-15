#include<iostream>
 #include<string>
 using namespace std;

 //ϵͳ�ṩ��׼�쳣
 #include<stdexcept>


 class Person
 {
 public:
 	Person(string name, int age)
 	{
 		this->m_Name = name;
 		//���������

 		if (age<0 || age>200)
 		{
 			//�׳�Խ���쳣
 			//throw out_of_range("����Խ����");

 			throw length_error("����Խ����");
 		}
 	}

 	string m_Name;
 	int m_Age;
 };

 void test01()
 {
 	try
 	{
 		Person p("����", 300);
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
