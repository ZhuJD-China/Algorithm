#pragma once
#include "Employee.h"

class Manager : virtual public Employee
{
	public:
		Manager();
		virtual ~Manager();

		virtual void UpLevel(int level) ;
		
		virtual void GetPay() ;
		
		virtual void Init();
		
	protected:
		int m_fix_salary;
};




