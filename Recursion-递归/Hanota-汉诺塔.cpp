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
		//将n-1个圆盘从x借助z移动到y
		movecircle(n-1, x, z, y);
		
		printf("%c --> %c\n", x, z);
		count++;
		//将n-1个圆盘从y借助x移动到z
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
