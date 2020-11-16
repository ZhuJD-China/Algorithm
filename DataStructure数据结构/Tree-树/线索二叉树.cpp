#include <cstdlib>
#include<iostream>
using namespace std;

typedef char ElemType;

// 线索存储标志位
// Link(0):表示指向左右孩子的指针
// Thread(1):表示指向前驱后继的线索
typedef enum {Link, Thread} PointerTag;


typedef struct BiThrNode {
	char data;
	struct BiThrNode *lchild,*rchild;
	PointerTag ltag;
	PointerTag rtag;
} BiThrNode,*BiThrTree;


// 定义一个全局变量表示刚刚走过的节点
BiThrTree pre;

// 创建一棵二叉树，约定用户遵照前序遍历的方式输入数据
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


//中序遍历进行中序线索化
void InThreading(BiThrTree T)
{
	if(T) {
		InThreading(T->lchild);          //递归左子树线索化

		//------------------------------------------------------
		if(!T->lchild) {         //没有左孩子
			T->ltag = Thread;    //前驱线索
			T->lchild = pre; //左孩子指针指向前驱
		}
		if(!pre->rchild) {   //没有右孩子
			pre->rtag = Thread;  //后继线索
			pre->rchild = T; //前驱右孩子指针指向后继(当前结点p)
		}
		pre = T;	//线索化后 pre 就为当前结点 继续往下调用
		//--------------------------------------------------------

		InThreading(T->rchild);      //递归右子树线索化
	}
}

// 初始化一个头指针
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

		//收尾 //头指针和中序末结点互指
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

// 中序遍历二叉树，迭代(非递归)
//T指向头结点，头结点左链lchild指向根结点，头结点右链rchild指向中序遍历的最后一个结点。
void InOrderTraverse( BiThrTree T )
{
	BiThrTree p;
	p = T->lchild;

	while( p!=T ) {
		while( p->ltag == Link ) {
			p = p->lchild;		//当ltag = 0时循环到中序序列的第一个结点
		}
		visit(p->data);
		
		while( p->rtag == Thread && p->rchild !=T ) {  //p->rchild !=T 当最后中序遍历的末结点（pre指向的）的后继为头指针就遍历完毕 
			p = p->rchild;	//Thread // 访问p的后继结点	
			visit(p->data);
		}
		
		p = p->rchild;	// //p进入其右子树	
		cout<<" |p->rchild: "<<p->data<<" | ";
	}
}
//INPUT:
/*ABC  D  E F  */
//OUTPUT:
/*
pre: F
中序遍历二叉树的结果为：CBDAEF
*/ 
int main()
{
	BiThrTree P,T = NULL;

	CreateBiThrTree( &T );

	InOrderThreading( &P, T );

	printf("中序遍历二叉树的结果为：");

	InOrderTraverse( P ); //P头结点传入 

	printf("\n");

	return 0;
}
