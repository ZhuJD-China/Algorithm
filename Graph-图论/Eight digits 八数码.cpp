// 八数码
#include<cstdio>
#include<cstring>
#include<set>
#include<iostream>

using namespace std;

typedef int State[9];
const int MAXSTATE = 1000000;
State st[MAXSTATE], goal;
int dist[MAXSTATE];
int fa[MAXSTATE];


//判重方法一  STL 集合
//效率最低
set<int> vis;
void init_lookup_table1()
{
	vis.clear();
}

int try_to_insert1(int s)   //判断状态,使用将状态转换为9位数，
{
	int v = 0;               //用set判重
	for(int i = 0; i < 9; i++) v = v * 10 + st[s][i];
	if(vis.count(v)) return 0;
	vis.insert(v);
	return 1;
}


//判重方法二  hash
const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next[MAXSTATE];
void init_lookup_table2()
{
	memset(head, 0, sizeof(head));
}

int hash(State& s)
{
	int v = 0;
	for(int i = 0; i < 9; i++) v = v * 10 + s[i];
	return v % MAXHASHSIZE;
}

int try_to_insert2(int s)
{
	int h = hash(st[s]);
	int u = head[h];
	while(u) {
		if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = next[u];
	}
	next[s] = head[h]; //往头前插入。
	head[h] = s;   //头结点置为s
	return 1;
}


//判重方法三  编码解码
int vis3[362880], fact[9];

void init_lookup_table3()
{
	fact[0]=1;
	for(int i=1; i<9; i++) {
		fact[i]=fact[i-1]*i;
		//	printf("fact[i=%d]=%d = fact[i-1=%d]=%d * i=%d\n", i, fact[i], i-1, fact[i-1], i);
	}
}

int try_to_insert3(int s)
{
	int code=0;  //把st[s]映射到整数code
	for(int i=0; i<9; i++) {
		int cnt=0;
		for(int j=i+1; j<9; j++) {
			if(st[s][j] < st[s][i])
				cnt++;
		}
		code += fact[8-i] * cnt;
		//printf("code=%d += fact[8-i=%d]=%d * cnt=%d \n", code, fact[8-i], 8-i, cnt);
	}
	if(vis3[code]) return 0;
	return vis3[code] = 1;
}


const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs()
{

	//初始化查重表
	//init_lookup_table1();
	//init_lookup_table2();
	init_lookup_table3();


	int front = 1, rear = 2; // return 0被看做不存在,所以从1开始.
	fa[front] = -1;
	while(front < rear) {
		State& s = st[front];
		if(memcmp(goal, s, sizeof(s)) == 0) return front;
		int z;

		for(z = 0; z < 9; z++) if(!s[z]) break;//找到空格的位置

		int x = z/3, y = z%3; //确定空格的x,y坐标

		for(int d = 0; d < 4; d++) {

			int newx = x + dx[d];
			int newy = y + dy[d];
			int newz = newx * 3 + newy; //新空格的位置

			if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
				State& t = st[rear]; //使用引用操作st数组
				memcpy(&t, &s, sizeof(s)); //将s完全赋值给t
				t[newz] = s[z]; //将新空格的位置，赋值为空格
				t[z] = s[newz]; // 将旧空格的位置，复制为之前新空格位置的数。
				//也就实现了移动。

				dist[rear] = dist[front] + 1; // 记录步数.
				fa[rear] = front;

				//  if(try_to_insert1(rear)) rear++;
				//if(try_to_insert2(rear)) rear++;
				if(try_to_insert3(rear)) rear++;
			}
		}
		front++;
	}
	return 0;
}

int main()
{
	for(int i = 0; i < 9; i++)
		scanf("%d", &st[1][i]);
	for(int i = 0; i < 9; i++)
		scanf("%d", &goal[i]);

	int ans = bfs();

	if(ans > 0) printf("%d\n", dist[ans]);
	else printf("-1\n");


	//打印步骤
	int head = ans;
	while(head != -1) {
		for(int i = 0; i < 9; i++) {
			cout<<st[head][i]<<" ";
			if((i +1)% 3 == 0 ) puts("");
		}
		cout<<endl;
		head = fa[head];
	}
	return 0;
}


/*
2 6 4 1 3 7 0 5 8
8 1 5 7 3 6 4 0 2
31
*/
