/*��������*/
#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

const int maxn = 30;

typedef struct EdgeNode {	//�߱���
	int adjvex;    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
	int weight;		/* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VertexNode {	//�������
	int in;					/* ������� */
	int data; 				/* �����򣬴洢������Ϣ */
	struct EdgeNode *firstEdge;	/* �߱�ͷָ�� */
} VertexNode,  AdjList[maxn];

typedef struct {	//�ڽӱ�ṹ
	AdjList adjList;
	int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

void CreateMGraph(GraphAdjList GL)/* ����ͼ (�ڽӱ�)*/
{
	cout<<"Enter numVertexes and numEdges"<<endl;
	cin>>GL->numVertexes>>GL->numEdges;

	for(int i= 0; i < GL->numVertexes; i++) { /* ��ʼ��*/
		GL->adjList[i].in = 0;
		GL->adjList[i].data = i;
		GL->adjList[i].firstEdge = NULL; 	/* ���߱���Ϊ�ձ� */
	}


	for(int i=0; i< GL->numEdges; i++) {
		cout<<"Enter Vi, Vj, weight"<<endl;
		int Vi, Vj, weight;
		cin>>Vi>>Vj>>weight;

		//�����ڽӱ�
		EdgeNode *e = (EdgeNode*)malloc(sizeof(EdgeNode));
		e->adjvex = Vj;
		e->weight = weight;

		e->adjvex=Vj;							/* �ڽ����Ϊj  */
		e->next = GL->adjList[Vi].firstEdge;  /* ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e */
		GL->adjList[Vi].firstEdge = e;		/* ����ǰ�����ָ��ָ��e  */
		GL->adjList[Vj].in++;
	}
}

stack<int>  s;

/* ����������GL�޻�·������������������в�����1�����л�·����0�� */
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
		count++;        /* ���i�Ŷ��㣬������ */

		for(EdgeNode *e=GL->adjList[gettop].firstEdge; e ; e = e->next) {
			int k = e->adjvex;
			if( !(--GL->adjList[k].in) )
				/* ��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ */
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