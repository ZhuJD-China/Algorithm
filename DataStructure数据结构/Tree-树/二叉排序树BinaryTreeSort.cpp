#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

/* �������Ķ���������ṹ����
typedef ΪStruct BiTNodeȡ����������,��BiTNode, * BiTree;
BiTree������ֿ����Ϊ�˽ṹ��ȼ۵�ָ���������ͣ�����BiTree�����ı���������һ��ָ�����;
BiTree *T; ���ʾT��һ��ָ��ָ���ָ��������Ƚ��ڣ� Struct BiTNode **T;
*/
typedef  struct BiTNode  	/* ���ṹ */
{
    int data;	/* ������� */
    struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
} BiTNode, *BiTree;

/* �ݹ���Ҷ���������T���Ƿ����key, */
/* ָ��fָ��T��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
/* ���Ҳ��ɹ���ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
bool SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T)  	/*  ���Ҳ��ɹ� */
    {
        *p = f;
        return false;
    }
    else if (key==T->data)     /*  ���ҳɹ� */
    {
        *p = T;
        return true;
    }
    else if (key<T->data)
        return SearchBST(T->lchild, key, T, p);  /*  ���������м������� */
    else
        return SearchBST(T->rchild, key, T, p);  /*  ���������м������� */
}

/*  ������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ�� */
/*  ����key������TRUE�����򷵻�FALSE */
bool InsertBST(BiTree *T, int key)
{
    BiTree p,s;
    //InsertBST: *T= 0x25221d0(�����main�����е�Tָ��ĵ�ַ)
//    cout<<"InsertBST: T= "<<T<<endl;
//    cout<<"InsertBST: *T= "<<*T<<endl;
//    cout<<"InsertBST: &T= "<<&T<<endl;
    if (!SearchBST(*T, key, NULL, &p))   /* ���Ҳ��ɹ� */
    {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
            *T = s;			/*  ����sΪ�µĸ���� */
        else if (key<p->data)
            p->lchild = s;	/*  ����sΪ���� */
        else
            p->rchild = s;  /*  ����sΪ�Һ��� */
        return true;
    }
    else
        return false;  /*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}

/* �Ӷ�����������ɾ�����p�����ؽ���������������� */
bool Delete(BiTree *p)
{
    BiTree q,s;
    if((*p)->rchild==NULL)   /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
    {
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild==NULL)     /* ֻ���ؽ����������� */
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else     /* �������������� */
    {
        q=*p;
        s=(*p)->lchild;
        while(s->rchild)   /* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ���� */
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data; /*  sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ�� */
        if(q!=*p)
            q->rchild=s->lchild; /*  �ؽ�q�������� */
        else
            q->lchild=s->lchild; /*  �ؽ�q�������� */
        free(s);
    }
    return true;
}
/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ��, */
/* ������TRUE�����򷵻�FALSE�� */
bool DeleteBST(BiTree *T,int key)
{
    if(!*T) /* �����ڹؼ��ֵ���key������Ԫ�� */
        return false;
    else
    {
        if (key==(*T)->data) /* �ҵ��ؼ��ֵ���key������Ԫ�� */
            return Delete(T);
        else if (key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
    }
}

void InorderTraversal(BiTree T)
{
    if(!T)
        return;
    InorderTraversal(T->lchild);
    printf("%d ", T->data);
    InorderTraversal(T->rchild);
}

int main(void)
{
    int a[10]= {62,88,58,47,35,73,51,99,37,93};
    BiTree T=NULL;

    for(int i=0; i<10; i++)
    {
//        cout<<"main: T= "<<T<<endl;
//        cout<<"main: &T= "<<&T<<endl;
        InsertBST(&T, a[i]);
    }

    InorderTraversal(T);
    cout<<endl;
    cout<<"Delete 93"<<endl;
    DeleteBST(&T,93);
    InorderTraversal(T);
    cout<<endl;
    cout<<"Delete 47"<<endl;
    DeleteBST(&T,47);

    /*��������ź���Ķ�����*/
    InorderTraversal(T);
    cout<<endl;


    return 0;
}
