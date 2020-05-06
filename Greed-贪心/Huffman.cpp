#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 999999 //һ������ֵ
#define NUM 10

using namespace std;

const int maxn =100;

/*----------------------------------------------------------------------*/
/*
priority_queue<Type, Container, Functional>
TypeΪ�������ͣ� ContainerΪ�������ݵ�������FunctionalΪԪ�رȽϷ�ʽ��
�����д��������������ô����Ĭ���õ���vector���ȽϷ�ʽĬ����operator<��Ҳ�������ȶ����Ǵ󶥶ѣ���ͷԪ�����
*/
//priority_queue<int, vector<int>, greater<int> > q;
typedef pair<int, int> P;
struct cmp {
	bool operator()(const P p1, const P p2) {
		return p1.first > p2.first; //first��Сֵ����
	}
};
priority_queue<P, vector<P>, cmp> q;
//priority_queue<P, vector<P>, cmp> q; //greater<p>û�ж��壬 ������cmp���ز�����
/*---------------------------------------------------------------------*/


//�洢��������ÿ�����
typedef struct Node {
	char ch;
	int weight; //Ȩֵ
	int parent;
	int lchild,rchild;
} HFNode;

//�洢ÿ���ַ��������������
typedef struct {
	char ch;
	char code[NUM];
} HFCharCode;

HFNode HT[28*2-1]; //���������ṹ��
HFCharCode HCD[28]; //����������ṹ��
int LeafNum; //Ҷ�ӽ����
int NodeNum; //���н����
char EnterStr[MAX]; //����Ĵ��������
char EnterCode[MAX]; //����Ĵ���������
char RealStr[MAX]; //���Ľ����ĵ���
int AllWeight[28]; //�洢����28���ַ���Ȩֵ
int Count;


//ͳ��ÿ���ַ�Ȩֵ
void Statistics()
{
	int len = strlen(EnterStr);
	for(int i = 0; i <= 28; i++)
		AllWeight[i] = 0;

	for(int j = 0; j <= len - 1; j++) {
		if(isalpha(EnterStr[j])) {
			EnterStr[j] = tolower(EnterStr[j]);
			AllWeight[EnterStr[j]-'a']++;
		} else if((int)EnterStr[j] == 44)
			AllWeight[26]++;
		else if((int)EnterStr[j] == 46)
			AllWeight[27]++;
		else if((int)EnterStr[j] == 32) {
			AllWeight[28]++;
		} else {
			printf("\n���벻����Ҫ��!\n\n");
			exit(-1);
		}
	}
	int i = 0, j = 0;
	for( ; i <= 25; i++) {
		if(AllWeight[i] != 0) {
			HT[j].weight  = AllWeight[i];
			HT[j].ch = i+'a';
			j++;
		}
	}
	if(AllWeight[i] != 0) {
		HT[j].weight = AllWeight[i];
		HT[j].ch = ',';
		j++;
		i++;
	} else {
		i++;
	}
	if(AllWeight[i] != 0) {
		HT[j].weight = AllWeight[i];
		HT[j].ch = '.';
		j++;
		i++;
	} else {
		i++;
	}
//	cout<<"i= "<<i<<endl;
//	cout<<"j= "<<j<<endl;
	if(AllWeight[i] != 0) {
		HT[j].weight = AllWeight[i];
		HT[j].ch = ' ';
	}
	printf("\n*** ��ӡÿ���ַ���Ȩֵ ***\n");
	int n = 0;
	for(int i = 0; i <= 28; i++) {
		if(AllWeight[i] != 0) {
			n++;
			if(i <= 25)
				putchar('a'+i);
			else if(i == 26)
				printf(",");
			else if(i == 27)
				printf(".");
			else if(i == 28)
				printf(" ");
			printf(": %d\n", AllWeight[i]);
		}
	}
	LeafNum = n;
	NodeNum = 2*LeafNum-1;
	cout<<"Ҷ�ӽ����: "<<LeafNum<<endl;
	Count = LeafNum-1;
	cout<<"���н����: "<<NodeNum<<endl;
}

//�ҵ�����Ȩֵ��С�Ķ����������
void SelectMin(int &min1, int &min2)
{
	int i = 0;
	int temp;
	int wetmin1, wetmin2;
	while(HT[i].parent != -1)
		i++;

	wetmin1 = HT[i].weight;
	min1 = i;
	i++;

	while(HT[i].parent != -1)
		i++;
	wetmin2 = HT[i].weight;
	min2 = i;
	i++;

	if(wetmin1 > wetmin2) {
		temp = wetmin2;
		wetmin2 = wetmin1;
		wetmin1 = temp;
		temp = min2;
		min2 = min1;
		min1 = temp;
	}
	for(; i <= NodeNum-1; i++) {
		if(HT[i].weight < wetmin1 && HT[i].parent == -1) {
			wetmin2 = wetmin1;
			wetmin1 = HT[i].weight;
			min2 = min1;
			min1 = i;
		} else if(HT[i].weight < wetmin2 && HT[i].parent == -1) {
			wetmin2 = HT[i].weight;
			min2 = i;
		}
	}
}

//�ҵ�����Ȩֵ��С�Ķ����������(���ȶ���)
void SelectMinBYpriority_queue(int &min1, int &min2)
{
	P wetmin1, wetmin2;
	if(q.size()==1) {
		wetmin1 = q.top();
		min1 = wetmin1.second;
		return;
	}
	wetmin1 = q.top();
	min1 = wetmin1.second;  //xΪweight	yΪi���
//	printf("(%d, %d)\n",wetmin1.first,wetmin1.second);
	q.pop();

	wetmin2 = q.top();
	min2 = wetmin2.second;
//	printf("(%d, %d)\n",wetmin2.first,wetmin2.second);
	q.pop();

	q.push(P(wetmin1.first+wetmin2.first, ++Count));
//	cout<<"q.push(LeafNumNode(wetmin1.x+wetmin2.x, Count))"<<"--> ("<<wetmin1.first+wetmin2.first<<","<<Count<<")"<<endl;
}

void Initpriority_queue()
{
	for(int i=0; i<LeafNum; i++) {
		q.push(P(HT[i].weight, i));
//		cout<<"q.push(LeafNumNode(HT[i].weight, i)) ---> "<<"("<<HT[i].weight<<", "<<i<<")"<<endl;
	}
}

//�����������
void CreateHFTree()
{
	int i;
	for(i = 0; i <= LeafNum-1; i++) {
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		//HT[i].weight = HT[i].weight;  // ͳ��ÿ���ַ�Ȩֵ���Ѿ���ֵ
	}
	for(; i <= NodeNum-1; i++) {
		HT[i].parent = -1;
		HT[i].lchild = -1;
		HT[i].rchild = -1;
		HT[i].weight = MAX;
	}

	int min1, min2;
	Initpriority_queue();
	for(i = LeafNum; i <= NodeNum-1; i++) {

		//SelectMin(min1, min2);//ģ��ѡȡ 

		SelectMinBYpriority_queue(min1, min2);  //���ȶ��� 

		HT[min1].parent = i;
		HT[min2].parent = i;
		HT[i].lchild = min1;
		HT[i].rchild = min2;
		HT[i].weight = HT[min1].weight + HT[min2].weight;
	}
	printf("\n*** ��ӡ�������� ***\n");
	for(int i = 0; i <= NodeNum-1; i++) {
		printf("���:%d �ַ�:%c  Ȩֵ:%d ˫��:%d ��:%d �Һ�:%d\n",
		       i, HT[i].ch, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
}

//��һ���ַ�����ת
void ReverseStr(char *str)
{
	int i, j;
	char c;
	for(i = 0, j = strlen(str)-1; i < j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

//���й���������
void CreateHFCode()
{
	int i, j, len;
	for(i = 0; i <= LeafNum-1; i++) {
		len = 0;
		j = i;
		HCD[i].ch = HT[j].ch;
		while(HT[j].parent != -1) {  //���Ǹ��ڵ�
			if(HT[HT[j].parent].lchild == j) {  //��˫�׽�������
				HCD[i].code[len++] = '0'+0;  //�����ַ�0
			} else  //���Һ���
				HCD[i].code[len++] = '0'+1;  //�����ַ�1
			j = HT[j].parent;  //���ϱ���
		}
		HCD[i].code[len] = '\0'; //�ַ���ĩβ

		ReverseStr(HCD[i].code);
	}

	printf("\n*** ��ӡÿ���ַ��ı��� ***\n");
	for(int i = 0; i <= LeafNum-1; i++)
		printf("%c: %s\n", HT[i].ch, HCD[i].code);
}


//����������
void EncodeStr()
{
	int len = strlen(EnterStr);
	printf("\n*** ������ ***\n");
	for(int i = 0; i <= len-1; i++) {
		for(int j = 0; j <= LeafNum-1; j++) {
			if(EnterStr[i] == HCD[j].ch)
				printf("%s", HCD[j].code);
		}
	}
	printf("\n");
}

//����������
void DecodeHFCode()
{
	int k = NodeNum-1; //��������, ��ʼʱһ�������һ��
	int len = 0, i = 0;

	while(EnterCode[i]) {
		if(EnterCode[i] == '0'+0)
			k = HT[k].lchild;
		else if(EnterCode[i] == '0'+1)
			k = HT[k].rchild;
		else {
			printf("\n����! �����н��ܺ���1��0!\n\n");
			exit(-1);
		}
		if(HT[k].lchild == -1 && HT[k].rchild == -1) {
			RealStr[len++] = HT[k].ch;
			k = NodeNum-1;
		}
		i++;
	}

	RealStr[len] = '\0';
	if(k == NodeNum-1) {
		printf("\n*** ������ ***\n%s\n\n", RealStr);
		exit(0);
	}
	printf("\n����! ���������޷�����!\n\n");
	exit(-1);
}

int main(void)
{
	printf("****** ��������������� ******\n\n");
	printf("*** ����һ���ַ��� ***\n");

	gets(EnterStr); //�����������ģ��ɼ� �ո�space , .�������ַ�

	Statistics();//ͳ��ÿ���ַ�Ȩֵ

	CreateHFTree();
	CreateHFCode();
	EncodeStr();


	printf("\n*** �������������� ***\n");
	scanf("%s", EnterCode);
	getchar();


	DecodeHFCode();
	return 0;

	return 0;
}





