#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

const int MAX = 74567;
//const int MAX = 10;

//ѡ������ʵ��
void select_sort(int a[],int n)//nΪ����a��Ԫ�ظ���
{
    //����N-1��ѡ��
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        //�ҳ���iС�������ڵ�λ��
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        //����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý���
        if( i != min_index)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

//��������
void insertion_sort(int arr[],int len)
{
    for(int i=1; i<len; i++)
    {
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (key<arr[j]))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

//ϣ������(������������)
void Sell_sort(int arr[],int len)
{
    int increasement = len;
    int k;
    do
    {
        //ȷ�����������
        increasement = increasement / 3 + 1;
        for(int i=0; i<increasement; i++)
        {
            for(int j=i+increasement; j<len; j+=increasement)
            {
                if(arr[j] < arr[j-increasement]) //�����������
                {
                    int temp = arr[j];
                    for(k = j - increasement; k >= 0 && temp < arr[k]; k-=increasement)
                    {
                        arr[k+increasement] = arr[k];
                    }
                    arr[k+increasement] = temp;
                }
            }
        }
    }
    while(increasement > 1);
}

//��������
void QuickSort(int arr[], int start, int endd)
{
    int i = start;
    int j = endd;
    int base = arr[start];  //�Ե�һ��Ϊ��׼��
    if(i<j)
    {
        while(i<j)
        {
            //�ȴ��������ұȻ�׼��С����
            while(i<j && arr[j]>=base)
            {
                j--;
            }
            //�ҵ�->���
            if(i<j)
            {
                arr[i] = arr[j];
                i++;
            }

            //�ȴ��������ұȻ�׼������
            while(i<j && arr[i]<=base)
            {
                i++;
            }
            //�ҵ�->���
            if(i<j)
            {
                arr[j] = arr[i];
                j--;
            }
        }

        //��i j �غ�  ��base�ŵ��غϴ�����ʱbase�ұ߶���base����߶���baseС
        arr[i] = base;

        //����벿�ֵݹ����
        QuickSort(arr, start, i-1);
        //����벿�ֵݹ����
        QuickSort(arr, i+1, endd);
    }
}

/*--�鲢����---*/
//�ϲ��㷨
void Merge(int arr[], int start, int endd, int mid, int* temp)
{
    int i_start = start;
    int i_endd = mid;
    int j_start = mid+1;
    int j_endd = endd;

    int length = 0;

    //�ϲ�������������
    while(i_start <= i_endd && j_start <= j_endd)
    {
        if(arr[i_start] < arr[j_start])
        {
            temp[length] = arr[i_start];
            i_start++;
            length++;
        }
        else
        {
            temp[length] = arr[j_start];
            j_start++;
            length++;
        }
    }

    //i�������
    while(i_start <= i_endd)
    {
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }

    //j�������
    while(j_start <= j_endd)
    {
        temp[length] = arr[j_start];
        j_start++;
        length++;
    }

    //�����ռ串��ԭ���Ŀռ�
    for(int i=0; i<length; i++)
    {
        arr[start+i] = temp[i];
    }
}

//�鲢����
void MergeSort(int arr[], int start, int endd, int* temp)
{
    if(start==endd)
        return;
    int mid = (start+endd) / 2;
    //����
    //����
    MergeSort(arr, start, mid, temp);
    //�Ұ��
    MergeSort(arr, mid+1, endd, temp);
    //�ϲ�
    Merge(arr, start, endd, mid, temp);
}

/*-----*/



/*--������---*/

/*
    @param  arr[]   ������������
    @param  index   �������Ľ���±�
    @paraam len     ����ĳ���
*/
void HeapAdjust(int arr[],int index, int len)
{
    //�ȱ��浱ǰ�����±�
    int maxx = index;
    //�������Һ���������±�
    int lchild = index * 2 + 1;
    int rchild = index * 2 + 2;

    if(lchild < len && arr[lchild] > arr[maxx])
    {
        maxx = lchild;
    }

    if(rchild < len && arr[rchild] > arr[maxx])
    {
        maxx = rchild;
    }

    if(maxx != index)
    {
        swap(arr[maxx], arr[index]);
        HeapAdjust(arr, maxx, len);
    }

}

void HeapSort(int arr[], int len)
{
    //��ʼ����
    for(int i=len / 2 -1; i>=0; i--)
    {
        HeapAdjust(arr, i, len);
    }

    //�����Ѷ�Ԫ�غ�����Ԫ��
    for(int i = len-1; i>=0; i--)
    {
        swap(arr[i], arr[0]);
        HeapAdjust(arr, 0, i);
    }


}

/*-----*/


void select_sort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand();
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    select_sort(num, MAX);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "select_sort time : %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}


void insertion_sort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand();
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    insertion_sort(num, MAX);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "insertion_sort time: %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}

void Sell_sort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand();
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    Sell_sort(num, MAX);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "Sell_sort time: %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}

void QuickSort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand();
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    QuickSort(num, 0, MAX-1);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "QuickSort time: %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}

void MergeSort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand();
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    int *temp = (int*)malloc(sizeof(int)*MAX);
    MergeSort(num, 0, MAX-1, temp);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "MergeSort time: %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}

void HeapSort_test()
{
    srand((unsigned)time(NULL));
    int num[MAX];
    for(int i=0; i<MAX; i++)
    {
        num[i] = rand() % 100;
    }

    clock_t start_time, end_time;
    double  duration_time;


    start_time=clock();

    HeapSort(num, MAX);

    end_time = clock();


    duration_time = (double)(end_time-start_time) / CLOCKS_PER_SEC;
    printf( "HeapSort time: %lf seconds\n", duration_time );

//    for(int i=0; i<MAX; i++)
//        printf("%d  ", num[i]);
//    printf("\n");
}

int  main()
{

    select_sort_test();

    insertion_sort_test();

    Sell_sort_test();

    QuickSort_test();

    MergeSort_test();

    HeapSort_test();

    return 0;

}
