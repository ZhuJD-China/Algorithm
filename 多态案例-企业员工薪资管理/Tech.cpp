#include <iostream>
#include "Tech.h"

Tech::Tech()
{
	cout << "Tech()" << endl;
	m_perhoursmoney = 100;
}

Tech::~Tech()
{
	cout << "~Tech()" << endl;
}

void Tech::Init()
{
	cout << "请输入员工姓名" << endl;
	cin >> m_name;
}

void Tech::UpLevel(int level)
{
	if (level >= 0) {
		m_level = level;
		if (m_level == 1)
			m_perhoursmoney = 100;
		if (m_level == 2)
			m_perhoursmoney = 200;
		if (m_level == 3)
			m_perhoursmoney = 300;
		if (m_level >= 4)
			m_perhoursmoney = 400;
	}
}

void Tech::GetPay()
{
	cout << "请输入" << m_name << " 工作时长: " << endl;
	cin >> m_work_hours;
	m_salary = m_work_hours * m_perhoursmoney;

}


