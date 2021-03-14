#include<iostream>
#include<cmath>

using namespace std;

double equation_fx(double x)
{
	return (pow(x,3)-3*pow(x,2)+6*x-1);
}

void secant(double x_0_new, double x_1_new)
{
	if(x_0_new==x_1_new)
	{
		cout<<"x_0_new="<<x_0_new<<" x_1_new="<<x_1_new<<endl;
	}
	double x_2;
	x_2=x_1_new-((x_1_new-x_0_new)/(equation_fx(x_1_new)-equation_fx(x_0_new)))*equation_fx(x_1_new);
	x_2=abs(x_2);
	secant(x_1_new, x_2);
}

void dichotomy(double a_new, double b_new)
{
	double mid = (a_new+b_new)/2;
	if(abs(a_new-b_new)<=0.01)
	{
		cout<<"a="<<a_new<<" b="<<b_new<<endl;
	}
	if(equation_fx(a_new)*equation_fx(mid)>0)
	{
		dichotomy(mid, b_new);	
	}
	else if(equation_fx(b_new)*equation_fx(mid)>0)
	{
		dichotomy(a_new, mid);
	}
}

int main(void)
{
	//方程: x^3-3x^2+6x-1=0
	double a = 0, b = 1;	//隔离区间[0, 1]
	
	cout<<"dichotomy:"<<endl;
	//dichotomy
	dichotomy(a, b);

	cout<<"secant:"<<endl;
	//secant
	double x_0=1, x_1=0.8;
	secant(x_0, x_1);

	return 0;
}
