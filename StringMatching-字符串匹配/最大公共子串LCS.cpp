//
//���⣺��󹫹��Ӵ�
//
//��󹫹��Ӵ�����������ǣ�
//���������������Ӵ����ܹ�ƥ���ϵ���󳤶��Ƕ��١�
//
//���磺"abcdkkk" �� "baabcdadabc"��
//�����ҵ�����Ĺ����Ӵ���"abcd",������󹫹��Ӵ�����Ϊ4��


#include <stdio.h>
#include <string.h>

#define N 256
int f(const char* s1, const char* s2)
{
    //"abcdkkk", "baabcdadabc"
    //"abcd"
    int a[N][N];
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int i,j;

    memset(a,0,sizeof(int)*N*N);
    int maxx = 0;
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                a[i][j] = a[i-1][j-1]+1 ;  //���
                if(a[i][j] > maxx) maxx = a[i][j];
            }
        }
    }

    return maxx;
}

int main()
{
    printf("%d\n", f("akbcdkkk", "baabcdadabc"));
    return 0;
}



