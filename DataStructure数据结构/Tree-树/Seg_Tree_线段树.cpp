//线段树的每个节点都是原数组的一段区间和，而叶子节点就是原数组对应 的值
#include<iostream>
#include<cstring>
using namespace std;

const int maxn = 100;

void build_tree(int arr[], int tree[],int node,int start,int endd)
{
    if(start == endd)
    {
        tree[node] = arr[start];
    }
    else
    {
        int mid = (endd + start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        build_tree(arr,tree,left_node,start,mid);
        build_tree(arr,tree,right_node,mid+1,endd);
        tree[node] = tree[left_node] + tree[right_node];
    }
}

void update_val(int arr[], int tree[], int node, int start, int endd,int idx,int val)
{
    if(idx == start)
    {
        tree[node] = val;
        arr[node]= val;
    }
    else
    {
        int mid = (start+endd) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if(idx >= start && idx <= mid)
        {
            update_val(arr,tree,left_node,start,mid,idx,val);
        }
        else
        {
            update_val(arr,tree,right_node,mid+1,endd,idx,val);
        }
        tree[node]=  tree[left_node] +tree[right_node];
    }
}

int query_LR(int arr[], int tree[], int node, int start, int endd, int L, int R)
{

    if(R < start || L > endd)
    {
        return 0;
    }
    else if (L<=start && endd <= R) //已经获取L,R的和就不用继续递归下去了
    {
        return tree[node];
    }
    else if (start == endd)
    {
        return tree[node];
    }
    else
    {
        int mid = (start+endd) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        int sum_left = query_LR(arr,tree,left_node,start,mid,L,R);
        int sum_right = query_LR(arr,tree,right_node,mid+1,endd,L,R);
        return sum_left+sum_right;
    }
}

int main(void)
{
    int arr[]= {1,3,5,7,9,11};
    int tree[maxn];
    int sizeof_arr = 6;
    memset(tree,0,sizeof(tree));

    build_tree(arr,tree,0,0,sizeof_arr-1);

    for(int i=0; i<15; i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<"update-----------"<<endl;

    update_val(arr,tree,0,0,sizeof_arr-1,4,6);


    for(int i=0; i<15; i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    int res = query_LR(arr,tree,0,0,sizeof_arr-1,2,5);

    cout<<"query(2,5)= "<<res<<endl;

    return 0;
}
