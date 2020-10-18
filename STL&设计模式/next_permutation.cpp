#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n, p[10];
	cin>>n;
	for(int i=0;i<n;i++)	cin>>p[i];
	sort(p, p+n);
	do{
		for(int i=0;i<n;i++){
			cout<<p[i]<<" ";
		}
		cout<<endl;
	}while(next_permutation(p,p+n));
	
	return 0;
}
