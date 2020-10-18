/*

小Ho：韩信是为了计算的是士兵的人数，那么我们设这个人数为x。
三人成排，五人成排，七人成排，即x mod 3, x mod 5, x mod 7。
也就是说我们可以列出一组方程：

x mod 3 = 2
x mod 5 = 4
x mod 7 = 6
韩信就是根据这个方程组，解出了x的值。

提示：模线性方程组


提示：模线性方程组
小Hi：一开始就直接求解多个方程不是太容易，我们从n=2开始递推：

已知：

x mod m[1] = r[1]
x mod m[2] = r[2]
根据这两个式子，我们存在两个整数k[1],k[2]：

x = m[1] * k[1] + r[1]
x = m[2] * k[2] + r[2]
由于两个值相等，因此我们有：

	m[1] * k[1] + r[1] = m[2] * k[2] + r[2]
=>	m[1] * k[1] - m[2] * k[2] = r[2] - r[1]
由于m[1],m[2],r[1],r[2]都是常数，若令A=m[1],B=m[2],C=r[2]-r[1],x=k[1],y=k[2]，则上式变为：Ax + By = C。

是不是觉得特别眼熟。

小Ho：这不是扩展欧几里德么！

小Hi：没错，这就是我们之前讲过的扩展欧几里德。

我们可以先通过gcd(m[1], m[2])能否整除r[2]-r[1]来判定是否存在解。

假设存在解，则我们通过扩展欧几里德求解出k[1],k[2]。

再把k[1]代入x = m[1] * k[1] + r[1]，就可以求解出x。

同时我们将这个x作为特解，可以扩展出一个解系：

X = x + k*lcm(m[1], m[2]) k为整数
lcm(a,b)表示a和b的最小公倍数。其求解公式为lcm(a,b)=a*b/gcd(a,b)。

将其改变形式为：

X mod lcm(m[1], m[2]) = x。
令M = lcm(m[1], m[2]), R = x，则有新的模方程X mod M = R。

此时，可以发现我们将x mod m[1] = r[1]，x mod m[2] = r[2]合并为了一个式子X mod lcm(m[1], m[2]) = x。满足后者的X一定满足前两个式子。

小Ho：每两个式子都可以通过该方法化简为一个式子。那么我们只要重复进行这个操作，就可以将n个方程组化简为一个方程，并且求出一个最后的解了。

小Hi：没错，就是这样。将其写做伪代码为：

M = m[1], R = r[1]
For i = 2 .. N
	d = gcd(M, m[i])
	c = r[i] - R
	If (c mod d) Then	// 无解的情况
		Return -1
	End If
	(k1, k2) = extend_gcd(M / d, m[i] / d)	// 扩展欧几里德计算k1,k2
	k1 = (c / d * k1) mod (m[i] / d)	// 扩展解系
	R = R + k1 * M		// 计算x = m[1] * k[1] + r[1]
	M = M / d * m[i] 	// 求解lcm(M, m[i])
	R %= M 			// 求解合并后的新R，同时让R最小
End For
If (R < 0) Then
	R = R + M
End If
Return R
Close
输入
第1行：1个正整数, N，2≤N≤1,000。

第2..N+1行：2个正整数, 第i+1行表示第i组m,r，2≤m≤20,000,000，0≤r<m。

计算过程中尽量使用64位整型。

输出
第1行：1个整数，表示满足要求的最小X，若无解输出-1。答案范围在64位整型内。

Sample Input
3
3 2
5 3
7 2
Sample Output
23

*/
#include <iostream>
#include <cstdio>
#define N 1010
using namespace std;
long long m[N], r[N];
int n;
long long x, y;
long long gcd(long long a, long long b)
{
    if (!b) return a;
    return gcd(b, a%b);
}
pair<long long, long long > extend_gcd(long long a, long long b)
{
    pair<long long, long long> tmp;
    if (a%b == 0)
    {
        return pair<long long, long long>(0, 1);
    }
    tmp = extend_gcd(b, a%b);
    long long tmp_x = tmp.first, tmp_y = tmp.second;
    x = tmp_y;
    y = tmp_x-(a/b)*tmp_y;
    return pair<long long, long long>(x, y);
}
long long solve()
{
    long long M = m[0], R = r[0];
    for (int i = 1; i < n; i++)
    {
        long long d = gcd(M, m[i]);
        long long c = r[i] - R;
        if (c%d != 0)
        {
            return -1;  // 无解的情况
        }
        pair<long long, long long> t = extend_gcd(M/d, m[i]/d); // 扩展欧几里德计算

        //将这个x作为特解，可以扩展出一个解系：X = x + k*lcm(m[1], m[2]) k为整数
        //lcm(a,b)表示a和b的最小公倍数。其求解公式为lcm(a,b)=a*b/gcd(a,b)。

        t.first = (c/d*t.first)%(m[i]/d);// 扩展解系
        // x = ((r[1]-r[0])/gcd(m[0],m[1])*x)%(m[1]/gcd(m[0],m[1]))

        /*
        将其改变形式为：
        X mod lcm(m[1], m[2]) = x。
        令M = lcm(m[1], m[2]), R = x，则有新的模方程X mod M = R。
        */
        R = R+t.first*M;
        M = M/d*m[i];   // 求解lcm(M, m[i])
        R %= M;     // 求解合并后的新R，同时让R最小
    }
    if (R < 0)
    {
        R += M;
    }
    return R;
}
int main()
{

    int i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &m[i], &r[i]);
    }
    cout << solve();
    return 0;
}

