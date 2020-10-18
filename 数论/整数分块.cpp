//求n/1+n/2+n/3+n/4+…n/n的和，n/i都向下取整。
#include<iostream>
using namespace std;
int main(void)
{
    ans = 0;
    for(int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += n / l * (r - l + 1);
    }

    cout << ans;

    return 0;
}
