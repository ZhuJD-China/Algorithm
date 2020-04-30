#include<iostream>
#include<queue>
#include<vector>
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

//层次遍历

queue<BiTNode*> q;
vector<char> ans;
bool Hierarchy(BiTree T, int level)
{
	ans.clear();
	q.push(T);
	while(!q.empty()) {
		BiTNode *u = q.front();
		q.pop();
		if(u->data == ' ')	return false;
		ans.push_back(u->data);
		
		if(u->lchild != NULL)
			q.push(u->lchild);
		if(u->rchild != NULL)
			q.push(u->rchild);
		
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
层级遍历
A B E C D F
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

	cout<<"层级遍历"<<endl;
	Hierarchy(T, level);
	for(auto i:ans){
		cout<<i<<" ";
	}cout<<endl;


	return 0;
}





