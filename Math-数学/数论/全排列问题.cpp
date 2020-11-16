/*���ֵ�������1~n��ȫ����*/
#include <iostream>
#include <vector>

#define N 5

using namespace std;

//��Ҫȫ���е����飬���밴����˳��
int a[N] = {-1,1,2,3,4};

//���һ������
void print(vector<int> vec)
{
    vector<int>::iterator it = vec.begin();
    for(it ; it != vec.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
//�ݹ�����ȫ����
void dfs(vector<int>& vec,bool flag[])
{
    if(vec.size() == N-1)
    {
        print(vec);
    }
    else
    {
        for(int i=1; i<N; i++)
        {
            //���û�з��ʣ������
            if(flag[i] == false)
            {
                //��Ԫ�ؼ���vector������
                vec.push_back(a[i]);
                //����ѷ���
                flag[i] = true;
                //�����ݹ�
                dfs(vec,flag);
                //����
                vec.pop_back();
                flag[i] = false;
            }
        }
    }
}


int main()
{
    bool flag[N] = {false};
    vector<int> vec;
    dfs(vec,flag);

    return 0;
}


/*
���ظ�ȫ����
֮ǰ�Ĵ���ֻ�ܱ�֤1-n��ȫ���У����Ǵ�����Ԫ�ز���1~n�������� 1 1 2 ������

�������£�

1 1 2

1 2 1

2 1 1


�����޸������ط���

����1.��ΪԪ�ؿ����ظ������Բ������á�A���Ƿ��Ѿ�����B���顱�������������Ƿ����B[i]Ԫ�ء�
ȡ����֮���ֱ��A��B����ɨ�裬ֻҪA�е�B[i]������B�е�B[i]���ɡ�

����2.����ĿҪ���ϣ��ظ�Ԫ��������ͬԪ��ʱ����1123��������1123��1123�ǵȼ۵ģ�ֻ����һ�֡�
��������ȶ�B�����Ÿ��������Ӷ���nlogn�����������ѭ���Ĵ���Ӱ�첢���Ǻܴ�)
Ȼ���������ѭ������һ����������(i==0||B[i]!=B[i-1]),Ϊ�ľ��Ƿ�ֹ�ظ���Ԫ����һ�����С�
*/
#include<iostream>
using namespace std;
void print_permutation(int n,int *A,int *B,int cur)
{
    if(cur==n)
    {
        for(int i=0; i<n; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    }
    else
        for(int i=0; i<n; i++)
        {
            if(!i||B[i]!=B[i-1])
            {
                int c1=0,c2=0;
                for(int j=0; j<cur; j++)//ɨ��A������B[i]�ĸ���
                    if(A[j]==B[i]) c1++;
                for(int j=0; j<n; j++)//ɨ��B������B[i]�ĸ���
                    if(B[j]==B[i]) c2++;
                if(c1<c2)
                {
                    A[cur]=B[i];
                    print_permutation(n,A,B,cur+1);
                }
            }
        }
}

int main()
{
    int a[]= {0};
    int b[]= {1,1,2,4};
    print_permutation(4,a,b,0);
    return 0;
}
