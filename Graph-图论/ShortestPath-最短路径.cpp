//Shortest Path
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn = 20;
const int INF = 65535;

typedef int Pathmatirx[maxn];     //���ڴ������·���±������
typedef int ShortPathTable[maxn];  //���ڴ��浽�������·����Ȩֵ��

/*�ڽӾ��󴢴�ṹ*/
typedef struct Graph {
	char vexs[maxn];
	int arc[maxn][maxn];
	int numVertexes, numEdges;
} Graph;


/*�����ڽӾ���*/
void CreateGraph(Graph* G)
{
	//��ʼ������ṹ
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

		/*�����ڽӾ���*/
		G->arc[Vi][Vj] = weight;
		G->arc[Vj][Vi] = G->arc[Vi][Vj]; //��Ϊ������ͼ������Գ�
	}
}

/* Dijkstra�㷨���������� G �� v0 ���㵽���ඥ�� v ���·�� P[v] ����Ȩ���� D[v],
*  P[v] ��ֵΪǰ�������±�,D[v] ��ʾ v0 �� v �����·�����Ⱥ� */
void ShortestPath_Dijkstra(Graph *G, int V0, Pathmatirx *P, ShortPathTable *D)
{
	int k, min;
	int final[maxn];		// final[w] = 1 ��ʾ�Ѿ���ö���V0��Vw�����·��

	for(int i=0; i<G->numVertexes; i++) {
		final[i] = 0;				// ȫ�������ʼ��Ϊδ�ҵ����·��
		(*D)[i] = G->arc[V0][i];	// ����V0�������ߵĶ������Ȩֵ
		(*P)[i] = 0;				// ��ʼ��·������PΪ0
	}

	(*D)[V0] = 0;		// V0��V0��·��Ϊ0
	final[V0] = 1;		// V0��V0����Ҫ��·��

	// ��ʼ��ѭ����ÿ�����V0��ĳ��V��������·��
	for(int i=0; i<G->numVertexes; i++) {
		min = INF;
		for(int w=0; w < G->numVertexes; w++ ) {
			if( !final[w] && (*D)[w]<min ) {
				k = w;
				min = (*D)[w];
			}
		}
		final[k] = 1;	// ��Ŀǰ�ҵ�������Ķ�����1

		// ������ǰ���·��������
		for(int w=0; w < G->numVertexes; w++ ) {
			// �������v�����·������������·���ĳ��ȶ̵Ļ������£�
			if( !final[w] && min+G->arc[k][w] < (*D)[w]) {
				(*D)[w] = min + G->arc[k][w];	// �޸ĵ�ǰ·������
				(*P)[w] = k;					// ���ǰ������
			}
		}
	}

	//������
	cout<<"Dijkstra:"<<endl;
	printf("��V0��ʼ�����·��-D[]:\n");
	for(int w=0; w < G->numVertexes; w++ ) {
		cout<<(*D)[w]<<"  ";
	}
	cout<<endl;
	printf("ÿ�������ǰ��-P[]:\n");
	for(int w=0; w < G->numVertexes; w++ ) {
		cout<<(*P)[w]<<"  ";
	}
//	cout<<endl;
//	printf("�Ƿ���ʹ�-final[]:\n");
//	for(int w=0; w < G->numVertexes; w++ ) {
//		cout<<final[w]<<"  ";
//	}
	cout<<endl;
}


typedef int Pathmatirx_Floyd[maxn][maxn];
typedef int ShortPathTable_Floyd[maxn][maxn];


/* Floyd�㷨������ͼG�и�����v�����ඥ��w�����·��P[v][w]����Ȩ����D[v][w]�� */
void ShortestPath_Floyd(Graph *G, Pathmatirx_Floyd *P, ShortPathTable_Floyd *D)
{
	int v,w,k;
	//k����ľ�����ת������±ꡣv������ʼ���㣬W�����������

	for(v=0; v<G->numVertexes; ++v) { /* ��ʼ��D��P */
		for(w=0; w<G->numVertexes; ++w) {
			(*D)[v][w]=G->arc[v][w];	/* D[v][w]ֵ��Ϊ��Ӧ����Ȩֵ */
			(*P)[v][w]=w;				/* ��ʼ��P */
		}
	}

	for(k=0; k<G->numVertexes; ++k) {
		for(v=0; v<G->numVertexes; ++v) {
			for(w=0; w<G->numVertexes; ++w) {
				if ((*D)[v][w]>(*D)[v][k]+(*D)[k][w]) {
					/* ��������±�Ϊk����·����ԭ�����·������ */
					(*D)[v][w]=(*D)[v][k]+(*D)[k][w];/* ����ǰ�����Ȩֵ��Ϊ��С��һ�� */
					(*P)[v][w]=(*P)[v][k];/* ·������Ϊ�����±�Ϊk�Ķ��� */
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
	//�����ڽӾ���
	Graph G;
	CreateGraph(&G);


	//Dijkstra�㷨
	Pathmatirx P;
	ShortPathTable  D;

	ShortestPath_Dijkstra(&G, 0, &P, &D);
	cout<<endl;


	//Floyd�㷨
	int v,w,k;
	Pathmatirx_Floyd P1;
	ShortPathTable_Floyd D1;
	ShortestPath_Floyd(&G, &P1, &D1);

	cout<<"Floyd:"<<endl;
	printf("����������·������:\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=v+1; w<G.numVertexes; w++) {
			printf("v%d-v%d weight: %d ",v,w,D1[v][w]);
			k=P1[v][w];				/* ��õ�һ��·�������±� */
			printf(" path: %d",v);	/* ��ӡԴ�� */
			while(k!=w) {			/* ���·�������±겻���յ� */
				printf(" -> %d",k);	/* ��ӡ·������ */
				k=P1[k][w];			/* �����һ��·�������±� */
			}
			printf(" -> %d\n",w);	/* ��ӡ�յ� */
		}
		printf("\n");
	}

	printf("���·��D\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=0; w<G.numVertexes; ++w) {
			if(w == v)	D1[v][w]=0;
			printf("%d\t",D1[v][w]);
		}
		printf("\n");
	}
	printf("���·��P\n");
	for(v=0; v<G.numVertexes; ++v) {
		for(w=0; w<G.numVertexes; ++w) {
			if(v == w)	P1[v][w] = v;
			printf("%d ",P1[v][w]);
		}
		printf("\n");
	}


	return 0;
}
