#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXVEX = 10; 

//�ڽӱ�
typedef struct EdgeNode/*�߱���*/
{
	int adjvex;  //�ڽӵ��򣬴���ö�����±�
	int weight;  //����Ȩֵ
	EdgeNode* next;	 //����ָ����һ���ڽӶ���
}EdgeNode;

typedef struct VertexNode/*�������*/
{
	char data;
	EdgeNode* firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;     
	int  numVertexes, numEdges;  //ͼ�Ķ������ͱ���
}GraphAdjList;

//����ͼ���ڽӱ�ṹ
void CreateGraphAdjList(GraphAdjList* G)
{
	cout<<"Enter numVertexes and numEdges"<<endl;
	cin>>G->numVertexes>>G->numEdges;
	
	cout<<"Enter Vertex data"<<endl;
	for(int i=0;i<G->numVertexes;i++)
	{									//��ʼ�������
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
		Ej->next = G->adjlist[Vi].firstedge;	//ͷ�巨
		G->adjlist[Vi].firstedge = Ej;
		
		EdgeNode* Ei = (EdgeNode*)malloc(sizeof(EdgeNode));
		Ei->adjvex = Vi;
		Ei->next = G->adjlist[Vj].firstedge;
		G->adjlist[Vj].firstedge = Ei;
	}
};


bool visited[MAXVEX];
/*�ڽӱ��������ȵݹ��㷨*/
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
/*�ڽӱ����ȱ�������*/
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

/*�ڽӱ�Ĺ�ȱ����㷨**/
void BFSTraverse(GraphAdjList* G)
{
	for(int i;i<MAXVEX;i++)	visited[i] = false;
	
	q = queue<int>(); //��ն���
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
				while(p)				//���ν��˶�����ڽӶ��������
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
	
	//��ӡ�ڽӱ�
	for(int i=0;i<G.numVertexes;i++)
	{
		cout<<G.adjlist[i].data<<"����>";
		EdgeNode* p = G.adjlist[i].firstedge;
		while(p != NULL)
		{
			cout<<p->adjvex<<"-";
			p = p->next;
		}
		cout<<endl;
	}
	
	//����ͼ
	/*��ʼ��visited[]*/
	memset(visited, false, sizeof(visited));
//	for(int i=0;i<10;i++)	cout<<visited[i]<<" ";
//	cout<<endl;
	
	cout<<"������ȵݹ�:"<<endl;
	DFS_recursion(&G, 0);
	
	cout<<endl;
	
	cout<<"��ȱ���:"<<endl;
	DFS_Depthtraversal(&G);
	
	cout<<endl;
	
	cout<<"��ȱ���:"<<endl;
	BFSTraverse(&G);
	
	return 0;
}

