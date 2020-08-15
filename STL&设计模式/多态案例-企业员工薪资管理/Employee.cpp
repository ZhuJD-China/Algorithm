#include <iostream>
#include "Employee.h"

int Employee::id_start=1000;

Employee::Employee()
{
	cout << "Employee()" << endl;
	m_ID = id_start++;
	m_salary = 0;
	m_level = 1;
}



Employee::~Employee()
{
	cout << "~Employee()" << endl;
}




void Employee::Display()
{
	cout << "name :" << m_name << endl;
	cout << " ID:" << m_ID << endl;
	cout << "level :" <<  m_level << endl;
	cout << "salary :" << m_salary << endl;
}


