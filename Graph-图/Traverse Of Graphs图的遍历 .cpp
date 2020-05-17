#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXVEX = 10; 

//邻接表
typedef struct EdgeNode/*边表结点*/
{
	int adjvex;  //邻接点域，储存该顶点的下标
	int weight;  //储存权值
	EdgeNode* next;	 //用于指向下一个邻接顶点
}EdgeNode;

typedef struct VertexNode/*顶点表结点*/
{
	char data;
	EdgeNode* firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;     
	int  numVertexes, numEdges;  //图的顶点数和边数
}GraphAdjList;

//建立图的邻接表结构
void CreateGraphAdjList(GraphAdjList* G)
{
	cout<<"Enter numVertexes and numEdges"<<endl;
	cin>>G->numVertexes>>G->numEdges;
	
	cout<<"Enter Vertex data"<<endl;
	for(int i=0;i<G->numVertexes;i++)
	{									//初始化顶点表
		cin>>G->adjlist[i].data;
		G->adjlist[i].firstedge=NULL;
	}
	
	for(int i=0;i<G->numEdges;i++)
	{
		cout<<"Enter two vertices(Vi, Vj) of an edge"<<endl;
		int Vi, Vj;
		cin>>Vi>>Vj;
		
		EdgeNode* Ej = (EdgeNode*)malloc(sizeof(EdgeNode));
		Ej->adjvex = Vj;
		Ej->next = G->adjlist[Vi].firstedge;	//头插法
		G->adjlist[Vi].firstedge = Ej;
		
		EdgeNode* Ei = (EdgeNode*)malloc(sizeof(EdgeNode));
		Ei->adjvex = Vi;
		Ei->next = G->adjlist[Vj].firstedge;
		G->adjlist[Vj].firstedge = Ei;
	}
};


bool visited[MAXVEX];
/*邻接表的深度优先递归算法*/
void DFS_recursion(GraphAdjList* G, int i)
{
	EdgeNode* p = G->adjlist[i].firstedge;
	
	visited[i] = true;
	cout<<G->adjlist[i].data<<"-";
	
	while(p)
	{
		if(!visited[p->adjvex])
			DFS_recursion(G, p->adjvex);
		p = p->next;
	}
	
	
}
/*邻接表的深度遍历操作*/
void DFS_Depthtraversal(GraphAdjList* G)
{
	for(int i;i<MAXVEX;i++)	visited[i] = false;
	
	for(int i;i<G->numVertexes;i++)
	{
		if(!visited[i])
			DFS_recursion(G, i);
	}
}


queue<int> q;

/*邻接表的广度遍历算法**/
void BFSTraverse(GraphAdjList* G)
{
	for(int i;i<MAXVEX;i++)	visited[i] = false;
	
	q = queue<int>(); //清空队列
	EdgeNode* p;
	
	for(int i=0;i<G->numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			cout<<G->adjlist[i].data<<"-";
			q.push(i);
			while(!q.empty())
			{
				int temp = q.front();
				q.pop();
				
				p = G->adjlist[temp].firstedge;
				while(p)				//依次将此顶点的邻接顶点入队列
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						cout<<G->adjlist[p->adjvex].data<<"-";
						q.push(p->adjvex);
					}
					p = p->next;
				}
				
			}
		}
	}
	
}
/*
INPUT:
4 5
ABCD
0 1
0 2
0 3
1 2
2 3
*/
int main(void)
{
	GraphAdjList G;
	CreateGraphAdjList(&G);
	
	//打印邻接表
	for(int i=0;i<G.numVertexes;i++)
	{
		cout<<G.adjlist[i].data<<"——>";
		EdgeNode* p = G.adjlist[i].firstedge;
		while(p != NULL)
		{
			cout<<p->adjvex<<"-";
			p = p->next;
		}
		cout<<endl;
	}
	
	//遍历图
	/*初始化visited[]*/
	memset(visited, false, sizeof(visited));
//	for(int i=0;i<10;i++)	cout<<visited[i]<<" ";
//	cout<<endl;
	
	cout<<"深度优先递归:"<<endl;
	DFS_recursion(&G, 0);
	
	cout<<endl;
	
	cout<<"深度遍历:"<<endl;
	DFS_Depthtraversal(&G);
	
	cout<<endl;
	
	cout<<"广度遍历:"<<endl;
	BFSTraverse(&G);
	
	return 0;
}

