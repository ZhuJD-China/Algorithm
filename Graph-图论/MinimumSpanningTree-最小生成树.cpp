//minimum spanning tree
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 20;
const int INF = 65535;
int minimum_prim;
int minimum_Kruskal;

/*邻接矩阵储存结构*/
typedef struct Graph {
	char vexs[maxn];
	int arc[maxn][maxn];
	int numVertexes, numEdges;
} Graph;

/*边集数组储存结构*/
typedef struct Edge {
	int begin;
	int end;
	int weight;
} Edge;

Edge edges[maxn];   //定义边集数组

bool cmp(Edge x, Edge y)
{
	return x.weight < y.weight;//从小到大排
}

/*创建邻接矩阵+创建边集数组*/
void CreateGraph(Graph* G)
{
	//初始化储存结构
	for(int i=0; i<maxn; i++)	G->vexs[i]=' ';
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++) {
			G->arc[i][j]=INF;
			edges[i].begin = INF;
			edges[i].end = INF;
			edges[i].weight = INF;
		}


	cout<<"Enter numVertexes and numEdges"<<endl;
	cin>>G->numVertexes>>G->numEdges;

	cout<<"Enter vexs"<<endl;
	for(int i=0; i<G->numVertexes; i++)	cin>>G->vexs[i];

	for(int i=0; i<G->numEdges; i++) {
		cout<<"Enter Vi, Vj, weight to Create Edges"<<endl;
		int Vi, Vj, weight;
		cin>>Vi>>Vj>>weight;

		/*创建邻接矩阵*/
		G->arc[Vi][Vj] = weight;
		G->arc[Vj][Vi] = G->arc[Vi][Vj]; //因为是无向图，矩阵对称

		/*创建边集数组*/
		edges[i].begin = Vi;
		edges[i].end = Vj;
		edges[i].weight = weight;

		/*排序(按weight从小到大排序)*/
		sort(edges, edges+G->numEdges, cmp);

		//打印
//		for(int i=0;i<G->numEdges;i++)
//		{
//			printf("edges[%d] begin=%d  end=%d  weight=%d \n", i,
//					edges[i].begin, edges[i].end, edges[i].weight);
//		}
	}
}

/*prim最小生成树算法*/  // O(n^2)
void  MiniSpanTree_Prim(Graph* G)
{
	int min, j, k;

	int adjvex[maxn];   //保存相关顶点的下标
	int lowcost[maxn];  //保存相关顶点间边的权值

	adjvex[0]=0;
	lowcost[0]=0;

	for(int i=1; i<G->numVertexes; i++) {
		lowcost[i] = G->arc[0][i];  //初始化第0行邻接权值
		adjvex[i] = 0;
	}

	for(int i=0; i<G->numVertexes; i++) {
		min = INF;

		j=1, k=0;

		while(j<G->numVertexes) {
			if(lowcost[j]!=0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
			j++;
		}

		if(lowcost[k]!=0)
			cout<<"("<<adjvex[k]<<", "<<k<<") weight="<<lowcost[k]<<endl;   //打印当前顶点边中最小的边

		minimum_prim+=lowcost[k];

		lowcost[k] = 0;

		for(int j=1; j<G->numVertexes; j++) {
			if(lowcost[j]!=0 && G->arc[k][j] < lowcost[j]) {
				/*若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值*/
				lowcost[j] = G->arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}

/*寻找当前结点连通图的根节点*/   // 并查集
int Find(int *parent, int f)
{
	while(parent[f]>0)
		f = parent[f];

	return f;
}

/*Kruskal算法生成最小树*/  // O(eloge) e为边数
void MiniSpanTree_Kruskal(Graph* G)
{
	int  parent[maxn];  // 定义parent数组用来判断边与边是否形成环路
	int rank[maxn];    //定义连通树（快）的高度

	for(int i=0; i<G->numVertexes; i++) {
		parent[i] = 0; //初始化数组为0
		rank[i] = 0;
	}

	for(int i=0; i<G->numEdges; i++) {	//循环每一条边
		int n = Find(parent, edges[i].begin); // 4 2 0 1 5 3 8 6 6 6 7
		int m = Find(parent, edges[i].end);   // 7 8 1 5 8 7 6 6 6 7 7

		if( n != m ) {	// 如果n==m，则形成环路，不满足！

			if(rank[n] > rank[m]) //连通树（快）的高度来判断谁是谁的父节点，以此压缩路径
				parent[m] = n;	// 将此边的结尾顶点放入下标为起点的parent数组中，表示此顶点已经在生成树集合中
			else if(rank[n] < rank[m])
				parent[n] = m;
			else
				parent[n] = m;
			rank[m]++;

			printf("(%d, %d) weight=%d \n", edges[i].begin, edges[i].end, edges[i].weight);
			minimum_Kruskal+=edges[i].weight;
		}
	}
}

/*
INPUT:
9 15
012345678
0 1 10
0 5 11
1 2 18
1 6 16
1 8 12
2 3 22
2 8 8
3 4 20
3 6 24
3 7 16
3 8 21
4 5 26
4 7 7
5 6 17
6 7 19
------------------------
edges[]:
edges[0] begin=4  end=7  weight=7
edges[1] begin=2  end=8  weight=8
edges[2] begin=0  end=1  weight=10
edges[3] begin=0  end=5  weight=11
edges[4] begin=1  end=8  weight=12
edges[5] begin=1  end=6  weight=16
edges[6] begin=3  end=7  weight=16
edges[7] begin=5  end=6  weight=17
edges[8] begin=1  end=2  weight=18
edges[9] begin=6  end=7  weight=19
edges[10] begin=3  end=4  weight=20
edges[11] begin=3  end=8  weight=21
edges[12] begin=2  end=3  weight=22
edges[13] begin=3  end=6  weight=24
edges[14] begin=4  end=5  weight=26
*/
int main(void)
{
	Graph G;
	CreateGraph(&G);

	cout<<endl;

	MiniSpanTree_Prim(&G); //prim
	cout<<"minimum_prim= "<<minimum_prim<<endl<<endl;

	MiniSpanTree_Kruskal(&G); //Kruskal
	cout<<"minimum_Kruskal= "<<minimum_Kruskal<<endl;

	return 0;
}