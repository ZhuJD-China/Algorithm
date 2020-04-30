#include<iostream>
using namespace std;

typedef char ElemType;

//树结点
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//创建一棵二叉树
void CreateBiTree(BiTree* T)
{
	char c;
	scanf("%c", &c);

	if(c == ' ') {
		*T=NULL;
	} else {
		*T = (BiTNode*)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}

//访问二叉树结点的具体操作
void visit(char data, int level)
{
	cout<<data<<" 位于第"<<level<<"层"<<endl;
}


//前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
	if(T) {
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//中序遍历二叉树
void MidOrderTraverse(BiTree T, int level)
{
	if(T) {
		MidOrderTraverse(T->lchild, level+1);
		visit(T->data, level);
		MidOrderTraverse(T->rchild, level+1);
	}
}

//后序遍历二叉树
void FloOrderTraverse(BiTree T, int level)
{
	if(T) {
		FloOrderTraverse(T->lchild, level+1);
		FloOrderTraverse(T->rchild, level+1);
		visit(T->data, level);
	}
}
//INPUT:
/*ABC  D  E F  */
//OUTPUT
/*
前序遍历
A 位于第1层
B 位于第2层
C 位于第3层
D 位于第3层
E 位于第2层
F 位于第3层
中序遍历
C 位于第3层
B 位于第2层
D 位于第3层
A 位于第1层
E 位于第2层
F 位于第3层
后序遍历
C 位于第3层
D 位于第3层
B 位于第2层
F 位于第3层
E 位于第2层
A 位于第1层
*/
int main(void)
{
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);

	cout<<"前序遍历"<<endl;
	PreOrderTraverse(T, level);

	cout<<"中序遍历"<<endl;
	MidOrderTraverse(T, level);

	cout<<"后序遍历"<<endl;
	FloOrderTraverse(T, level);

	return 0;
}





