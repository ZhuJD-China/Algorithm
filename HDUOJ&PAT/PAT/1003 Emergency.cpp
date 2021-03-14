/*PAT 1003 Emergency*/
/*
Output Specification:
For each test case, print in one line two numbers:
the number of different shortest paths between C1 and C2,
and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space,
and there is no extra space allowed at the end of a line.

Sample Input:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output:
2 4
*/
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
using namespace std;

const int maxn = 505;
const int MAXINF = 9999;
int vis[maxn];
int d[maxn]; //distances from 0 to 1-(N-1) 
int fa[maxn];//father vertex
int Weight[100][100];
int RescueTeam[100];

int MAXR[maxn];
int MINP[maxn];

int main(void)
{
	int N, M, C_start, C_end;// N (cities≤500)
	while (cin >> N >> M >> C_start >> C_end) {
		//int* RescueTeam = (int*)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) {
			cin >> RescueTeam[i];
		}
		//Establish Map
		//int** Weight = (int**)malloc(sizeof(int*) * N * N);
		//memset(Weight, 0, sizeof(Weight));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				Weight[i][j] = MAXINF;
		for (int i = 0; i < M; i++) {
			int c1, c2, w;
			cin >> c1 >> c2 >> w;
			Weight[c1][c2] = w;
			Weight[c2][c1] = Weight[c1][c2]; //无向图，矩阵对称
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << Weight[i][j] << " ";
			}cout << endl;
		}
		//Found shortest path
		/*Init*/
		for (int i = 0; i < N; i++)	vis[i] = 0;
		for (int i = 0; i < N; i++) {
			d[i] = MAXINF; fa[i] = -1;
		}
		fill(MAXR, MAXR + maxn, MAXINF);
		fill(MINP, MINP + maxn, MAXINF);


		//vis[0] = 1;//从0出发
		MAXR[C_start] = RescueTeam[C_start];
		MINP[C_start] = 1;
		d[C_start]=0;
		//for (int i = 0; i < N; i++)	d[i] = Weight[0][i];


		for (int v = 0; v < N; v++) {
			int nextnode=-1;
			int minn = MAXINF;
			for (int i = 0; i < N; i++) {
				if (!vis[i] && d[i] <= minn) {
					minn = d[i];
					nextnode = i;
				}
			}
			vis[nextnode] = 1;
			for (int y = 0; y < N; y++) {
				if (!vis[y] && minn + Weight[nextnode][y] < d[y] && Weight[nextnode][y]!=MAXINF	) {
					d[y] = minn + Weight[nextnode][y];
					fa[y] = nextnode;
					//cout << "nextnode=" << nextnode <<endl;
					//找到更短的路径，最大救援数更新-MAXR， 最短路径不变-MINP
					MINP[y] = MINP[nextnode];
					MAXR[y] = MAXR[nextnode] + RescueTeam[y];

				}
				else if (!vis[y] && (minn + Weight[nextnode][y] == d[y])) {
					//找到相同长的路径，最大救援数量判断更新， 最短路径增加
					MAXR[y] = max(MAXR[y], MAXR[nextnode] + RescueTeam[y]);
					MINP[y] += MINP[nextnode];
				}
			}
		}

		/*print*/
		cout << "d[]:" << endl;
		for (int i = 0; i < N; i++) {
			cout << d[i] << " ";
		}cout << endl;
		cout << "fa[]:" << endl;
		for (int i = 0; i < N; i++) {
			cout << fa[i] << " ";
		}cout << endl;

		cout << MINP[C_end] << " " << MAXR[C_end] << endl;
	}

	return 0;
}