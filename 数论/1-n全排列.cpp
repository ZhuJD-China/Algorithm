// UVa725 Division
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1000;
int A[maxn];
int n;
int P[maxn];

void print_permutation(int n, int* A, int cur)
{
	if(cur==n) {
		for(int i=0; i<=n; i++)	printf("%d ", A[i]);
		printf("\n");
	} else {
		for(int i=1; i<=n; i++) {
			int ok=1;
			for(int j=0; j<cur; j++) {
				if(A[j]==i)	ok=0;
			}
			if(ok) {
				A[cur]=i;
				print_permutation(n, A, cur+1);
			}
		}
	}
}

int main()
{
	while(scanf("%d", &n)&&n) {
		print_permutation(n, A, 0);
	}


	return 0;
}
