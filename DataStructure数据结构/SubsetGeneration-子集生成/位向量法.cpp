#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define INF 300

int B[100];
int n;
void print_subset(int n,int *B,int cur)
{
	//printf("B[]: ");
	//for(int i=0; i<n; i++)	printf("%d ", B[i]);
	//printf("\n");

	if(cur==n) {
		for(int i=0; i<cur; i++)
			if(B[i])printf("%d ",i);
		printf("\n");
		return ;
	}

	B[cur]=1;

	print_subset(n,B,cur+1);//ัก

	B[cur]=0;

	print_subset(n,B,cur+1);//ฒปัก

}

int main()

{
	scanf("%d",&n);

	print_subset(n,B,0);

}

