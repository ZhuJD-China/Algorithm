#pragma once
#include "Employee.h"
class Tech : public Employee

{
	public:
		Tech();
		~Tech();

		virtual void Init();
		virtual void UpLevel(int level) ;
		virtual void GetPay() ;
	private:
		int m_work_hours;
		double m_perhoursmoney;
};


