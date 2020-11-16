//阶乘之和 的末6位 
#include<stdio.h>
#include<time.h>
int main(void)
{
	const int MOD = 1000000; 
	int n,i,j,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		int factorial=1;
		for(j=1;j<=i;j++){
			factorial =(factorial*j % MOD);
		}
		sum=(sum+factorial) % MOD;
	}
	printf("%d\n",sum);
	printf("Time used = %.2f s\n",(double)clock() / CLOCKS_PER_SEC);
	return 0;
}
