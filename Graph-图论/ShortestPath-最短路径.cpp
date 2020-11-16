//Shortest Path
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 20;
const int INF = 65535;

typedef int Pathmatirx[maxn];     //用于储存最短路径下标的数组
typedef int ShortPathTable[maxn];  //用于储存到各点最短路径的权值和

/*邻接矩阵储存结构*/
typedef struct Graph {
	char vexs[maxn];
	int arc[maxn][maxn];
	int numVertexes, numEdges;
} Graph;


/*创建邻接矩阵*/
void CreateGraph(Graph* G)
{
	//初始化储存结构
	for(int i=0; i<maxn; i++)	G->vexs[i]=' ';
	for(int i=0; i<maxn; i++)
		for(int j=0; j<maxn; j++) {
			G->arc[i][j]=INF;
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
	}
}

/* Dijkstra算法，求有向网 G 的 v0 顶点到其余顶点 v 最短路径 P[v] 及带权长度 D[v],
*  P[v] 的值为前驱顶点下标,D[v] 表示 v0 到 v 的最短路径长度和 */
void ShortestPath_Dijkstra(Graph *G, int V0, Pathmatirx *P, ShortPathTable *D)
{
	int k, min;
	int final[maxn];		// final[w] = 1 表示已经求得顶点V0到Vw的最短路径

	for(int i=0; i<G->numVertexes; i++) {
		final[i] = 0;				// 全部顶点初始化为未找到最短路径
		(*D)[i] = G->arc[V0][i];	// 将与V0点有连线的顶点加上权值
		(*P)[i] = 0;				// 初始化路径数组P为0
	}

	(*D)[V0] = 0;		// V0至V0的路径为0
	final[V0] = 1;		// V0至V0不需要求路径

	// 开始主循环，每次求得V0到某个V顶点的最短路径
	for(int i=0; i<G->numVertexes; i++) {
		min = INF;
		for(int w=0; w < G->numVertexes; w++ ) {
			if( !final[w] && (*D)[w]<min ) {
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;	// 将目前找到的最近的顶点置1

		// 修正当前最短路径及距离
		for(int w=0; w < G->numVertexes; w++ ) {
			// 如果经过v顶点的路径比现在这条路径的长度短的话，更新！
			if( !final[w] && min+G->arc[k][w] < (*D)[w]) {
				(*D)[w] = min + G->arc[k][w];	// 修改当前路径长度
				(*P)[w] = k;					// 存放前驱顶点
			}
		}
	}

	//输出结果
	cout<<"Dijkstra:"<<endl;
	printf("从V0开始的最短路径-D[]:\n");
	for(int w=0; w < G->numVertexes; w++ ) {
		cout<<(*D)[w]<<"  ";
	}
	cout<<endl;
	printf("每个顶点的前驱-P[]:\n");
	for(int w=0; w < G->numVertexes; w++ ) {
		cout<<(*P)[w]<<"  ";
	}
//	cout<<endl;
//	printf("是否访问过-final[]:\n");
//	for(int w=0; w < G->numVertexes; w++ ) {
//		cout<<final[w]<<"  ";
//	}
	cout<<endl;
}


typedef int Pathmatirx_Floyd[maxn][maxn];
typedef int ShortPathTable_Floyd[maxn][maxn];


/* Floyd算法，求网图G中各顶点v到其余顶点w的最短路径P[v][w]及带权长度D[v][w]。 */
void ShortestPath_Floyd(Graph *G, Pathmatirx_Floyd *P, ShortPathTable_Floyd *D)
{
	int v,w,k;
	//k代表的就是中转顶点的下标。v代表起始顶点，W代表结束顶点

	for(v=0; v<G->numVertexes; ++v) { /* 初始化D与P */
		for(w=0; w<G->numVertexes; ++w) {
			(*D)[v][w]=G->arc[v][w];	/* D[v][w]值即为对应点间的权值 */
			(*P)[v][w]=w;				/* 初始化P */
		}
	}

	for(k=0; k<G->numVertexes; ++k) {
		for(v=0; v<G->numVertexes; ++v) {
			for(w=0; w<G->numVertexes; ++w) {
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w]) {
					/* 如果经过下标为k顶点路径比原两点间路径更短 */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* 将当前两点间权值设为更小的一个 */
					(*P)[v][w]=(*P)[v][k];/* 路径设置为经过下标为k的顶点 */
				}
			}
		}
	}
}

/*
INPUT:
9 16
012345678
0 1 1
0 2 5
1 2 3
1 3 7
1 4 5
2 4 1
2 5 7
3 4 2
3 6 3
4 5 3
4 6 6
4 7 9
5 7 5
6 7 2
6 8 7
7 8 4
*/
int main(void)
{
	//创建邻接矩阵
	Graph G;
	CreateGraph(&G);


	//Dijkstra算法
	Pathmatirx P;
	ShortPathTable  D;

	ShortestPath_Dijkstra(&G, 0, &P, &D);
	cout<<endl;


	//Floyd算法
	int v,w,k;
	Pathmatirx_Floyd P1;
	ShortPathTable_Floyd D1;
	ShortestPath_Floyd(&G, &P1, &D1);

	cout<<"Floyd:"<<endl;
	printf("各顶点间最短路径如下:\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=v+1; w<G.numVertexes; w++) {
			printf("v%d-v%d weight: %d ",v,w,D1[v][w]);
			k=P1[v][w];				/* 获得第一个路径顶点下标 */
			printf(" path: %d",v);	/* 打印源点 */
			while(k!=w) {			/* 如果路径顶点下标不是终点 */
				printf(" -> %d",k);	/* 打印路径顶点 */
				k=P1[k][w];			/* 获得下一个路径顶点下标 */
			}
			printf(" -> %d\n",w);	/* 打印终点 */
		}
		printf("\n");
	}

	printf("最短路径D\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=0; w<G.numVertexes; ++w) {
			if(w == v)	D1[v][w]=0;
			printf("%d\t",D1[v][w]);
		}
		printf("\n");
	}
	printf("最短路径P\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=0; w<G.numVertexes; ++w) {
			if(v == w)	P1[v][w] = v;
			printf("%d ",P1[v][w]);
		}
		printf("\n");
	}


	return 0;
}
