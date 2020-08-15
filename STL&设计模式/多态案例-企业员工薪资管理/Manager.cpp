#include <iostream>
#include "Manager.h"


Manager::Manager()
{
	cout << "Manager()" << endl;

}

Manager::~Manager()
{
	cout << "~Manager()" << endl;
}


void Manager::Init()
{
	cout << "请输入经理姓名： " << endl;
	cin >> m_name;
	this->m_fix_salary = 8000;
}

	

void Manager::UpLevel(int level)
{
	if (level >= 0) {
		m_level = level;
		if (m_level == 1) {
			m_salary = 8000;
		}
		if (m_level == 2) {
			m_salary = 10000;
		}
		if (m_level == 3) {
			m_salary = 12000;
		}
	}
}



void Manager::GetPay()
{
	m_salary = m_fix_salary;
}



