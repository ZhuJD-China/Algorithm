#pragma once
#include "Manager.h"
#include "SaleMan.h"
class SalesManager :public Manager,SaleMan
{
	public:
		SalesManager();
		
		~SalesManager();

		virtual void Init();
		
		virtual void UpLevel(int level);
		
		virtual void GetPay();
};



