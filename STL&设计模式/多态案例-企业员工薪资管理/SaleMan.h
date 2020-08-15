#pragma once
#include "Employee.h"


class SaleMan : virtual public Employee
{
	public:
		SaleMan();
		virtual ~SaleMan();

		virtual void Init();
		
		virtual void UpLevel(int level) ;
		
		virtual void GetPay() ;


	protected:
		int m_curent_amout;
		double  m_rate;
};




