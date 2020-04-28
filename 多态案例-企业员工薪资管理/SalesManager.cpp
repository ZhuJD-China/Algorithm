#include <iostream>
#include "SalesManager.h"


SalesManager::SalesManager()
{
	cout << "SalesManager() " << endl;

	m_fix_salary = 5000;
	m_rate = 0.05;
}


SalesManager::~SalesManager()
{
	cout << "~SalesManager()" << endl;
}


void SalesManager::Init()
{
	cout << "请输入销售经理姓名 " << endl;
	cin >> m_name;
}


void SalesManager::UpLevel(int level)
{
	if (level >= 0) {
		m_level = level;
		if (m_level == 1)
			m_rate = 0.04;
		if (m_level == 2)
			m_rate = 0.05;
		if (m_level == 3)
			m_rate = 0.06;
	}
}


void SalesManager::GetPay()
{
	cout << "请输入销售经理的销售额 ：" << endl;
	cin >> m_curent_amout;
	m_salary = m_curent_amout * m_rate + m_fix_salary;
}



