//�˻ʺ�����
#include<iostream>
using namespace std;

const int maxn =100;
int n;
int vis[maxn][maxn];
int tot;
int C[maxn];

void search(int cur) //cur �� 
{
	if(cur==n)	tot++;
	else {
		for(int i=0; i<n; i++) {  //i �� 
			
			if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
				C[cur] = i;

				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;  //�޸�ȫ�ֱ��� 
				
				search(cur+1);

				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;  //�мǣ�һ��Ҫ�Ļ��� 
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
