#include <cstdlib>
#include<iostream>
using namespace std;

typedef char ElemType;

// �����洢��־λ
// Link(0):��ʾָ�����Һ��ӵ�ָ��
// Thread(1):��ʾָ��ǰ����̵�����
typedef enum {Link, Thread} PointerTag;


typedef struct BiThrNode {
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag ltag;
	PointerTag rtag;
} BiThrNode,*BiThrTree;


// ����һ��ȫ�ֱ�����ʾ�ո��߹��Ľڵ�
BiThrTree pre;

// ����һ�ö�������Լ���û�����ǰ������ķ�ʽ��������
void CreateBiThrTree(BiThrTree *T)
{
	char c;
	scanf("%c",&c);

	if ( ' ' == c ) {
		*T = NULL;
	} else {
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = c;
		(*T)->ltag = Link;
		(*T)->rtag = Link;

		CreateBiThrTree(&(*T)->lchild);
		CreateBiThrTree(&(*T)->rchild);
	}
}


//���������������������
void InThreading(BiThrTree T)
{
	if(T) {
		InThreading(T->lchild);          //�ݹ�������������

		//------------------------------------------------------
		if(!T->lchild) {         //û������
			T->ltag = Thread;    //ǰ������
			T->lchild = pre; //����ָ��ָ��ǰ��
		}
		if(!pre->rchild) {   //û���Һ���
			pre->rtag = Thread;  //�������
			pre->rchild = T; //ǰ���Һ���ָ��ָ����(��ǰ���p)
		}
		pre = T;	//�������� pre ��Ϊ��ǰ��� �������µ���
		//--------------------------------------------------------

		InThreading(T->rchild);      //�ݹ�������������
	}
}

// ��ʼ��һ��ͷָ��
void InOrderThreading( BiThrTree *p, BiThrTree T)
{
	*p = (BiThrNode *)malloc(sizeof(BiThrNode));
	(*p)->ltag = Link;
	(*p)->rtag = Thread;
	(*p)->rchild = *p;

	if (!T) {
		(*p)->lchild = *p;
	} else {
		(*p)->lchild = T;
		pre = *p;

		InThreading(T);

		//��β //ͷָ�������ĩ��㻥ָ
		cout<<"pre: "<<pre->data<<endl;
		pre->rchild = *p;
		pre->rtag = Thread;
		(*p)->rchild = pre;
	}
}

void visit (char c)
{
	printf("%c",c);
}

// �������������������(�ǵݹ�)
//Tָ��ͷ��㣬ͷ�������lchildָ�����㣬ͷ�������rchildָ��������������һ����㡣
void InOrderTraverse( BiThrTree T )
{
	BiThrTree p;
	p = T->lchild;

	while( p!=T ) {
		while( p->ltag == Link ) {
			p = p->lchild;		//��ltag = 0ʱѭ�����������еĵ�һ�����
		}
		visit(p->data);
		
		while( p->rtag == Thread && p->rchild !=T ) {  //p->rchild !=T ��������������ĩ��㣨preָ��ģ��ĺ��Ϊͷָ��ͱ������ 
			p = p->rchild;	//Thread // ����p�ĺ�̽��	
			visit(p->data);
		}
		
		p = p->rchild;	// //p������������	
		cout<<" |p->rchild: "<<p->data<<" | ";
	}
}
//INPUT:
/*ABC  D  E F  */
//OUTPUT:
/*
pre: F
��������������Ľ��Ϊ��CBDAEF
*/ 
int main()
{
	BiThrTree P,T = NULL;

	CreateBiThrTree( &T );

	InOrderThreading( &P, T );

	printf("��������������Ľ��Ϊ��");

	InOrderTraverse( P ); //Pͷ��㴫�� 

	printf("\n");

	return 0;
}
