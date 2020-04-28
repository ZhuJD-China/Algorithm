#include <iostream>
#include "SaleMan.h"


SaleMan::SaleMan()
{
	cout << "SaleMan()" << endl;
	m_rate = 0.04;
}


SaleMan::~SaleMan()
{
	cout << "~SaleMan() " << endl;
}

void SaleMan::Init()
{
	cout << "请输入销售人员的姓名: " << endl;
	cin >> m_name;
}

void SaleMan::UpLevel(int level)
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


void SaleMan::GetPay()
{
	cout << "请输入销售人员的销售额：" << endl;
	cin >> m_curent_amout;
	m_salary = m_curent_amout * m_rate;
}


