#include<iostream>
using namespace std;

int count;

void movecircle(int n, char x, char y, char z)
{
	
	if(n==0)
	{
	//	printf("%c -> %c\n",x, z);
	return;
	}
	else{
		//��n-1��Բ�̴�x����z�ƶ���y
		movecircle(n-1, x, z, y);
		
		printf("%c --> %c\n", x, z);
		count++;
		//��n-1��Բ�̴�y����x�ƶ���z
 		movecircle(n-1, y, x, z); 
	}
 }

int main(void)
{
	int n;
	cin>>n;
	
	movecircle(n, 'x', 'y', 'z');
	cout<<count<<endl;
	return 0;
}
