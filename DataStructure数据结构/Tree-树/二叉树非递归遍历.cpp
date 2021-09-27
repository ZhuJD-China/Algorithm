#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

typedef char ElemType;


typedef struct BiTNode {
	ElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


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


void visit(char data, int level)
{
	cout<<data<<" ";
}



void PreOrderTraverse(BiTree T, int level)
{
	if(T) {
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level+1);
		PreOrderTraverse(T->rchild, level+1);
	}
}


void MidOrderTraverse(BiTree T, int level)
{
	if(T) {
		MidOrderTraverse(T->lchild, level+1);
		visit(T->data, level);
		MidOrderTraverse(T->rchild, level+1);
	}
}

void FloOrderTraverse(BiTree T, int level)
{
	if(T) {
		FloOrderTraverse(T->lchild, level+1);
		FloOrderTraverse(T->rchild, level+1);
		visit(T->data, level);
	}
}


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


void non_recursion_MidOrderTraverse(BiTNode* T)
{

	/**
	*1.push(root->child)
	2.pop(top) if top->right != null push(top->righlt) else pop(top)
	**/
	stack<BiTNode*> ss;
	BiTNode* p = T; //p is a Traversing pointer
	while(p || !ss.empty())
	{
		if(p){
			ss.push(p);
			p=p->lchild;
		}
		else{			
			BiTNode* temp_node = ss.top();
			ss.pop();
			
			cout<<temp_node->data<<" ";
			p=temp_node->rchild;
		}
		
	}
}

void non_recursion_PreOrderTraverse(BiTNode* T)
{

	/**
	vist before push stack
	**/
	stack<BiTNode*> ss;
	BiTNode* p = T; //p is a Traversing pointer
	while(p || !ss.empty())
	{
		if(p){
			cout<<p->data<<" ";
			ss.push(p);
			p=p->lchild;
		}
		else{			
			BiTNode* temp_node = ss.top();
			ss.pop();
			p=temp_node->rchild;
		}
		
	}
}


void non_recursion_FloOrderTraverse(BiTNode* T)
{
	/*
	1.while root->lchild !=null  push(lchild) 
	2.top  if top.rchild  !=null !vist push(rchild)  else  visit(top) pop()
	*/
	BiTree p = T;
	BiTree r = NULL;
	stack<BiTNode*> ss;
	
	while(p || !ss.empty())
	{
		if(p){
			ss.push(p);
			p=p->lchild;
		}
		else{
			p= ss.top();
			
			if(p->rchild && p->rchild != r)
			{
				p=p->rchild;
				ss.push(p);
				p=p->lchild;
			}
			else
			{
				p = ss.top();
				cout<<p->data<<" ";
				ss.pop();
				
				r=p;
				p=NULL;
			}
			
		}
		
	}
	
}

//INPUT:
/*ABC  D  E F  */

int main(void)
{
	int level = 1;
	BiTree T = NULL;

	CreateBiTree(&T);

	cout<<"PreOrderTraverse"<<endl;
	PreOrderTraverse(T, level);
	cout<<endl;
	
	cout<<"MidOrderTraverse"<<endl;
	MidOrderTraverse(T, level);
	cout<<endl;

	cout<<"FloOrderTraverse"<<endl;
	FloOrderTraverse(T, level);
	cout<<endl;
	
	cout<<"Hierarchy"<<endl;
	Hierarchy(T, level);
	for(auto i:ans){
		cout<<i<<" ";
	}cout<<endl;

	cout<<"non_recursion_PreOrderTraverse"<<endl;
	non_recursion_PreOrderTraverse(T);
	cout<<endl;

	cout<<"non_recursion_MidOrderTraverse"<<endl;
	non_recursion_MidOrderTraverse(T);
	cout<<endl;
	
	cout<<"non_recursion_FloOrderTraverse"<<endl;
	non_recursion_FloOrderTraverse(T);
	cout<<endl;
	
	
	return 0;
}