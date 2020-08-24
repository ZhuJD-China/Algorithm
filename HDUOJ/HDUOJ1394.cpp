#include<iostream>

using namespace std;

const int maxn=5005;
int a[maxn],b[maxn],tmp[maxn],tot;
void merge(int l,int r,int mid)
{
    int pos=0;
    int i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
        {
            tot+=mid+1-i;
            tmp[pos++]=a[j++];
        }
        else
        {
            tmp[pos++]=a[i++];
        }
    }
    while(i<=mid)tmp[pos++]=a[i++];
    while(j<=r)tmp[pos++]=a[j++];
    for(i=0; i<pos; i++)a[l+i]=tmp[i];
}

void merge_sort(int l, int r)
{
    if(l==r)return;
    int mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge(l,r,mid);
}

int main()
{
    int n,ans;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        tot=0;
        merge_sort(0,n-1);
        ans=tot;
        /*
        对于每个从数列首移到数列尾的移动，可以用tmp+=((n−1−a[i])−a[i])；表示。
        对于每一个后移的a[i]会减少a[i]个逆序对(数据从0开始)，
        同时增加n−a[i]−1个逆序对，因为比a[i]大的数字个数是n−a[i]−1个，过程取最小值即可

        the next line contains a permutation of the n integers from 0 to n-1.!!
        是0到n-1的连续的n个数 上面这个性质才成立!!
        */
        for(int i=0; i<n; i++)
        {
            tot+=n-1-2*b[i];
//            cout<<"b[i"<<"="<<i<<"]= "<<b[i]<<" n-1-2*b[i]= "<<(n-1-2*b[i])<<endl;
//            cout<<"tot= "<<tot<<endl;
            if(ans>tot)ans=tot;
        }
        printf("%d\n",ans);
    }
    return 0;
}
