//��n/1+n/2+n/3+n/4+��n/n�ĺͣ�n/i������ȡ����
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
