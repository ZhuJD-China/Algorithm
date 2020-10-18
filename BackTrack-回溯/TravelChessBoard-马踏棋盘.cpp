/*
国际象棋的棋盘为8*8的方格棋盘。
(如果将空格标成点，就是象棋中的马走“日”字)。

任意一个位置，“马”最多有8个方向可以跳动，所以每次都要依据这最多8个方向进行选择。
将马随机放在国际象棋的Board[0~7][0~7]的某个方格中，马按走棋规则进行移动。
走遍棋盘上全部64个方格。求出马的行走路线，并按求出的行走路线，将数字1，2，…，64依次填入一个8×8的方阵，输出之。
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int chessboard[12][12] = {0};

int cnt = 0;			//标记马已走的方格数
int sum = 0;			//标记马走完全程的具体方案数
int Move[8][2]= { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};	//初始马当前位置向其周围相邻八个日字的 x,y的偏移量

//输出马踏棋盘的解
void PrintChess();
//马踏棋盘递归过程
void Horse(int x,int y);

int main(void)
{
	int i,j;
	for(i=0; i<12; i++) {
		for(j=0; j<12; j++) {
			if(i==0 || i==1 || i==10 || i==11 || j==0 || j==1 || j==10 || j==11) {
				chessboard[i][j]=-1;//在 8 * 8 的外层再加上两层，确保 8 * 8 方格中的每一个格子都有 8 种不同的日字选择
			}
		}
	}
	//从起始位置开始求得所有解
	chessboard[2][2] = ++cnt;
	Horse(2,2);	//递归调用当前当前位置附近的 8 个日字，看看是否满足条件
	return 0;
}

void Horse(int x,int y) 		//马永远踏的是 x,y位置，而不是 a,b
{
	if(cnt >= 64) {		//临界值，马走日字全部踏完，成功求出问题解
		sum++;
		PrintChess();
		return;
	}
	for(int i=0; i<8; i++) {
		int a = x + Move[i][0];		//拿到当前马位置相邻的 8 个日字的 x 坐标
		int b = y + Move[i][1];		//拿到当前马位置相邻的 8 个日字的 y 坐标
		if(chessboard[a][b] == 0) {	//判断当前马位置相邻的日字是否已被访问
			cnt++;
			chessboard[a][b]=cnt;	//标志已被访问
			Horse(a,b);			 	//从当前马的位置继续往下访问
			cnt--;
			chessboard[a][b]=0; 	//回溯回来修改其相邻的日字的访问情况
		}
	}
}

//输出马踏棋盘的解
void PrintChess()
{
	cout<<endl<<"马踏棋盘第 "<<sum<<"组解为:"<<endl;
	int i,j;
	for(i=2; i<10; i++) {
		for(j=2; j<10; j++) {
			cout<<"  "<<chessboard[i][j];
		}
		cout<<endl;
	}
}
