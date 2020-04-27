//八皇后问题
#include<iostream>
using namespace std;

const int maxn =100;
int n;
int vis[maxn][maxn];
int tot;
int C[maxn];

void search(int cur) //cur 行 
{
	if(cur==n)	tot++;
	else {
		for(int i=0; i<n; i++) {  //i 列 
			
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
				C[cur] = i;

				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;  //修改全局变量 
				
				search(cur+1);

				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;  //切记！一定要改回来 
			}
		}
	}
}

int main(void)
{
	cin>>n;
	search(0);
	cout<<tot<<endl;

	return 0;
}
