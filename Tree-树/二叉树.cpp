#include<iostream>
#include<queue>
#include<vector>
using namespace std;

typedef char ElemType;

//�����
typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

//����һ�ö�����
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

//���ʶ��������ľ������
void visit(char data, int level)
{
	cout<<data<<" λ�ڵ�"<<level<<"��"<<endl;
}


//ǰ�����������
void PreOrderTraverse(BiTree T, int level)
{
	if(T) {
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}

//�������������
void MidOrderTraverse(BiTree T, int level)
{
	if(T) {
		MidOrderTraverse(T->lchild, level+1);
		visit(T->data, level);
		MidOrderTraverse(T->rchild, level+1);
	}
}

//�������������
void FloOrderTraverse(BiTree T, int level)
{
	if(T) {
		FloOrderTraverse(T->lchild, level+1);
		FloOrderTraverse(T->rchild, level+1);
		visit(T->data, level);
	}
}

//��α���

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
ǰ�����
A λ�ڵ�1��
B λ�ڵ�2��
C λ�ڵ�3��
D λ�ڵ�3��
E λ�ڵ�2��
F λ�ڵ�3��
�������
C λ�ڵ�3��
B λ�ڵ�2��
D λ�ڵ�3��
A λ�ڵ�1��
E λ�ڵ�2��
F λ�ڵ�3��
�������
C λ�ڵ�3��
D λ�ڵ�3��
B λ�ڵ�2��
F λ�ڵ�3��
E λ�ڵ�2��
A λ�ڵ�1��
�㼶����
A B E C D F
*/
int main(void)
{
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);

	cout<<"ǰ�����"<<endl;
	PreOrderTraverse(T, level);

	cout<<"�������"<<endl;
	MidOrderTraverse(T, level);

	cout<<"�������"<<endl;
	FloOrderTraverse(T, level);

	cout<<"�㼶����"<<endl;
	Hierarchy(T, level);
	for(auto i:ans){
		cout<<i<<" ";
	}cout<<endl;


	return 0;
}





