//约瑟夫环
#include<iostream>
using namespace std;

//链表结点
typedef struct LinkNode {
	struct LinkNode * Next;
	int num;
} LinkNode;

//链表
typedef struct LinkList {
	LinkNode head;
	int size;
} LinkList;


//创建结点为n的循环链表
LinkList* CreateLinkList(int n)
{
	LinkList* Link = (LinkList*)malloc(sizeof(LinkList));
	Link->head.Next = &Link->head;
	Link->size = 0;

	//插入结点
	for(int i=n; i>=1; i--) {
		LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
		NewNode->num=i;
		NewNode->Next = Link->head.Next;
		Link->head.Next = NewNode;
		Link->size++;
	}
	return Link;
}

int main(void)
{
	int n,m;
	cin>>n>>m;


	LinkList* myLink = CreateLinkList(n);

	//打印循环链表结点的值
	LinkNode* pur = (LinkNode*)myLink->head.Next;
	for(int i=0; i<2*n; i++) {
		if(pur == &myLink->head) {
			pur = pur->Next;
		}
		cout<<pur->num<<" ";
		pur = pur->Next;
	}
	cout<<"size= "<<myLink->size<<endl;


	LinkNode* gamepur = &myLink->head;
	LinkNode* gamenow = myLink->head.Next;
	int index=0;

	while(myLink->size!=0) {
		index++;
		if( index ==m ) {
			cout<<"delete: "<<gamenow->num<<endl;
			gamepur->Next = gamenow->Next;
			LinkNode* temp = gamenow;
			gamenow = gamenow->Next;
			free(temp);
			myLink->size--;
			index=1;
		}

		gamepur = gamepur->Next;
		if(gamepur == &myLink->head) {
			gamepur = gamepur->Next;
		}
		gamenow = gamenow->Next;
		if(gamenow == &myLink->head) {
			gamenow = gamenow->Next;
		}
	}

	return 0;
}










