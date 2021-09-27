#include<iostream>
#include<algorithm>
using namespace std; 


bool IsSwap(char* pBegin, char* pEnd)
{
	char* p;
	for (p=pBegin; p<pEnd; p++)
	{
		if (*p == *pEnd)
			return false;
	}
	return true;
}

void Permutation(char *str, char *head)
{
	if(str==NULL)
		return; 
 
	if(*head=='\0')  //head指针扫到结尾了
		cout<<str<<endl; 
	else
	{
		for(char *p=head; *p!='\0'; p++)
		{
//			cout<<"*head="<<*head<<endl;
//			cout<<"*p="<<*p<<endl;
			if(IsSwap(head, p))
			{
				swap(*p, *head);  //交换头指针指向的字符
				Permutation(str, head+1); 
				swap(*p,*head);  //交换回来
			}
		}
	}
}

void Permutation(char *str)
{
	int len=strlen(str); 
	sort(str, str+len); 
	do
	{
		cout<<str<<endl; 
	}while(next_permutation(str, str+len)); 
}

int main()
{
	char str[10]; 
	cout<<"The original string is: "; 
	cin>>str; 
	cout<<endl; 
	cout<<"After permutation, the string is: "<<endl;
	Permutation(str, str); 
 
	return 0; 
}