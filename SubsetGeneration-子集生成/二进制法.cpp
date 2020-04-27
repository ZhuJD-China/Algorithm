#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 300

int B[100];

void print_subset(int n,int s)
{
	for(int i=0; i<n; i++) {
//		cout<<"s= "<<s<<" (1<<i)="<<(1<<i)<<endl;
//		cout<<"s&(1<<i)= "<<(s&(1<<i))<<endl;
		if(s&(1<<i)) {
			printf("%d ",i);
		}
//		cout<<endl;
	}
	cout<<endl;
}

int main()

{

	int n;
	scanf("%d",&n);
//	cout<<"(1<<n)= "<<(1<<n)<<endl;
	for(int i=0; i<(1<<n); i++) {
		//	cout<<"i= "<<i<<endl;
		print_subset(n,i);
	}

}

