/*拓扑排序*/
#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

const int maxn = 30;

typedef struct EdgeNode {	//边表结点
	int adjvex;    /* 邻接点域，存储该顶点对应的下标 */
	int weight;		/* 用于存储权值，对于非网图可以不需要 */
	struct EdgeNode *next; /* 链域，指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode {	//顶点表结点
	int in;					/* 顶点入度 */
	int data; 				/* 顶点域，存储顶点信息 */
	struct EdgeNode *firstEdge;	/* 边表头指针 */
} VertexNode,  AdjList[maxn];

typedef struct {	//邻接表结构
	AdjList adjList;
	int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

void CreateMGraph(GraphAdjList GL)/* 构建图 (邻接表)*/
{
	cout<<"Enter numVertexes and numEdges"<<endl;
	cin>>GL->numVertexes>>GL->numEdges;

	for(int i= 0; i < GL->numVertexes; i++) { /* 初始化*/
		GL->adjList[i].in = 0;
		GL->adjList[i].data = i;
		GL->adjList[i].firstEdge = NULL; 	/* 将边表置为空表 */
	}


	for(int i=0; i< GL->numEdges; i++) {
		cout<<"Enter Vi, Vj, weight"<<endl;
		int Vi, Vj, weight;
		cin>>Vi>>Vj>>weight;

		//建立邻接表
		EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = Vj;
		e->weight = weight;

		e->adjvex=Vj;							/* 邻接序号为j  */
		e->next = GL->adjList[Vi].firstEdge;  /* 将当前顶点上的指向的结点指针赋值给e */
		GL->adjList[Vi].firstEdge = e;		/* 将当前顶点的指针指向e  */
		GL->adjList[Vj].in++;
	}
}

stack<int>  s;

/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0。 */
int TopologicalSort(GraphAdjList GL)
{
	int count;
	for(int i=0; i<GL->numVertexes; i++) {
		if(GL->adjList[i].in==0)
			s.push(i);
	}

	while(!s.empty()) {
		int gettop = s.top();
		s.pop();
		printf("%d -> ",GL->adjList[gettop].data);
		count++;        /* 输出i号顶点，并计数 */

		for(EdgeNode *e=GL->adjList[gettop].firstEdge; e ; e = e->next) {
			int k = e->adjvex;
			if( !(--GL->adjList[k].in) )
				/* 将i号顶点的邻接点的入度减1，如果减1后为0，则入栈 */
				s.push(k);
		}
	}
	printf("\n");
	if(count < GL->numVertexes)
		return false;
	else
		return true;
}

/*
INPUT:
14 20
0 4 1
0 5 1
0 11 1
1 2 1
1 4 1
1 8 1
2 5 1
2 6 1
2 9 1
3 2 1
3 13 1
4 7 1
5 8 1
5 12 1
6 5 1
8 7 1
9 10 1
9 11 1
10 13 1
12 9 1
*/
int main(void)
{

	graphAdjList GL;
	CreateMGraph(&GL);

	cout<<"Sort:"<<endl;
	int res = TopologicalSort(&GL);

	cout<<"res= "<<res<<endl;

	return 0;
}