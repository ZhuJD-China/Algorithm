#include <iostream>
#include "Employee.h"
#include "Tech.h"
#include "Manager.h"
#include "SaleMan.h"
#include "SalesManager.h"

int main()
{
#if 0
	Employee* p1 = new Tech;
	p1->Init();
	p1->UpLevel(3);
	p1->GetPay();
	p1->Display();

	delete p1;

	Employee* p2 = new Manager;
	p2->Init();
	p2->UpLevel(3);
	p2->GetPay();
	p2->Display();
	delete p2;


	Employee* p3 = new SaleMan;
	p3->Init();
	p3->UpLevel(2);
	p3->GetPay();
	p3->Display();
	delete p3;


	Employee* p4 = new SalesManager;
	p4->Init();
	p4->UpLevel(2);
	p4->GetPay();
	p4->Display();
	delete p4;
#endif

	Employee* p[] = { new Tech, new SaleMan, new Manager, new SalesManager };
	for (int i = 0; i < sizeof(p)/sizeof(p[0]);  i++) {
		p[i]->Init();
		p[i]->UpLevel(i+1);
		p[i]->GetPay();
		p[i]->Display();
	}

	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
		delete p[i];
	}

	return 0;
}




