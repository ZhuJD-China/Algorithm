#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

const int MAX = 74567;
//const int MAX = 10;

//选择排序实现
void select_sort(int a[],int n)//n为数组a的元素个数
{
    //进行N-1轮选择
    for(int i=0; i<n-1; i++)
    {
        int min_index = i;
        //找出第i小的数所在的位置
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        //将第i小的数，放在第i个位置；如果刚好，就不用交换
        if( i != min_index)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

//插入排序
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

//希尔排序(减少增量排序)
void Sell_sort(int arr[],int len)
{
    int increasement = len;
    int k;
    do
    {
        //确定分组的增量
        increasement = increasement / 3 + 1;
        for(int i=0; i<increasement; i++)
        {
            for(int j=i+increasement; j<len; j+=increasement)
            {
                if(arr[j] < arr[j-increasement]) //分组插入排序
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

//快速排序
void QuickSort(int arr[], int start, int endd)
{
    int i = start;
    int j = endd;
    int base = arr[start];  //以第一个为基准点
    if(i<j)
    {
        while(i<j)
        {
            //先从右往左找比基准点小的数
            while(i<j && arr[j]>=base)
            {
                j--;
            }
            //找到->填坑
            if(i<j)
            {
                arr[i] = arr[j];
                i++;
            }

            //先从左往右找比基准点大的数
            while(i<j && arr[i]<=base)
            {
                i++;
            }
            //找到->填坑
            if(i<j)
            {
                arr[j] = arr[i];
                j--;
            }
        }

        //当i j 重合  把base放到重合处。此时base右边都比base大，左边都比base小
        arr[i] = base;

        //对左半部分递归分治
        QuickSort(arr, start, i-1);
        //对左半部分递归分治
        QuickSort(arr, i+1, endd);
    }
}

/*--归并排序---*/
//合并算法
void Merge(int arr[], int start, int endd, int mid, int* temp)
{
    int i_start = start;
    int i_endd = mid;
    int j_start = mid+1;
    int j_endd = endd;

    int length = 0;

    //合并两个有序序列
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

    //i这个序列
    while(i_start <= i_endd)
    {
        temp[length] = arr[i_start];
        i_start++;
        length++;
    }

    //j这个序列
    while(j_start <= j_endd)
    {
        temp[length] = arr[j_start];
        j_start++;
        length++;
    }

    //辅助空间覆盖原来的空间
    for(int i=0; i<length; i++)
    {
        arr[start+i] = temp[i];
    }
}

//归并排序
void MergeSort(int arr[], int start, int endd, int* temp)
{
    if(start==endd)
        return;
    int mid = (start+endd) / 2;
    //分组
    //左半边
    MergeSort(arr, start, mid, temp);
    //右半边
    MergeSort(arr, mid+1, endd, temp);
    //合并
    Merge(arr, start, endd, mid, temp);
}

/*-----*/



/*--堆排序---*/

/*
    @param  arr[]   待调整的数组
    @param  index   待调整的结点下标
    @paraam len     数组的长度
*/
void HeapAdjust(int arr[],int index, int len)
{
    //先保存当前结点的下标
    int maxx = index;
    //保存左右孩子数组的下标
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
    //初始化堆
    for(int i=len / 2 -1; i>=0; i--)
    {
        HeapAdjust(arr, i, len);
    }

    //交换堆顶元素和最后的元素
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
