#include<iostream>
using namespace std;

const int maxn = 100;
int fa[maxn];

void Ini_union_set(int size)
{
	for(int i=0;i<size;i++)
	{
		fa[i]=i;
	}
}

int find(int x)
{
/*
	if(fa[x]==x)
	{
		return fa[x];
	}
	else
	{
		return find(fa[x]);
	}
	*/
	//Â·¾¶Ñ¹Ëõ
	if(x!=fa[x]){
		fa[x]=find(fa[x]);
	}
	return fa[x];
}

void union_set(int x, int y)
{
	x=find(x);
	y=find(y);
	fa[x]=y;
}

int main()
{
	Ini_union_set(10);
	union_set(0, 6);
	union_set(0, 7);
	union_set(7, 8);
	union_set(1, 4);
	union_set(1, 9);
	union_set(2, 3);
	union_set(2, 5);

	for(int i=0;i<10;i++)
		cout<<i<<" ";
	cout<<endl;

	for(int i=0;i<10;i++)
		cout<<fa[i]<<" ";
	cout<<endl;
	
	cout<<"find(7)"<<endl;
	cout<<find(7)<<endl;

	cout<<"find(8)"<<endl;
	cout<<find(8)<<endl;

	cout<<"find(6)"<<endl;
	cout<<find(6)<<endl;

	cout<<"find(0)"<<endl;
	cout<<find(0)<<endl;

	return 0;
}
