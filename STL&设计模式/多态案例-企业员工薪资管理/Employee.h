#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
	public:
		Employee();
		virtual ~Employee();

		virtual void Init() = 0 ;
		
		virtual void UpLevel(int level) = 0; //�ṩ�޸�Ա������ķ��� 
		
		virtual void GetPay()=0;
		
		void Display();


	protected:
		string m_name;
		int m_ID;
		int m_level;
		double m_salary;


		static int id_start;
};


