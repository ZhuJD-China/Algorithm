/*

СHo��������Ϊ�˼������ʿ������������ô�������������Ϊx��
���˳��ţ����˳��ţ����˳��ţ���x mod 3, x mod 5, x mod 7��
Ҳ����˵���ǿ����г�һ�鷽�̣�

x mod 3 = 2
x mod 5 = 4
x mod 7 = 6
���ž��Ǹ�����������飬�����x��ֵ��

��ʾ��ģ���Է�����


��ʾ��ģ���Է�����
СHi��һ��ʼ��ֱ����������̲���̫���ף����Ǵ�n=2��ʼ���ƣ�

��֪��

x mod m[1] = r[1]
x mod m[2] = r[2]
����������ʽ�ӣ����Ǵ�����������k[1],k[2]��

x = m[1] * k[1] + r[1]
x = m[2] * k[2] + r[2]
��������ֵ��ȣ���������У�

	m[1] * k[1] + r[1] = m[2] * k[2] + r[2]
=>	m[1] * k[1] - m[2] * k[2] = r[2] - r[1]
����m[1],m[2],r[1],r[2]���ǳ���������A=m[1],B=m[2],C=r[2]-r[1],x=k[1],y=k[2]������ʽ��Ϊ��Ax + By = C��

�ǲ��Ǿ����ر����졣

СHo���ⲻ����չŷ�����ô��

СHi��û�����������֮ǰ��������չŷ����¡�

���ǿ�����ͨ��gcd(m[1], m[2])�ܷ�����r[2]-r[1]���ж��Ƿ���ڽ⡣

������ڽ⣬������ͨ����չŷ���������k[1],k[2]��

�ٰ�k[1]����x = m[1] * k[1] + r[1]���Ϳ�������x��

ͬʱ���ǽ����x��Ϊ�ؽ⣬������չ��һ����ϵ��

X = x + k*lcm(m[1], m[2]) kΪ����
lcm(a,b)��ʾa��b����С������������⹫ʽΪlcm(a,b)=a*b/gcd(a,b)��

����ı���ʽΪ��

X mod lcm(m[1], m[2]) = x��
��M = lcm(m[1], m[2]), R = x�������µ�ģ����X mod M = R��

��ʱ�����Է������ǽ�x mod m[1] = r[1]��x mod m[2] = r[2]�ϲ�Ϊ��һ��ʽ��X mod lcm(m[1], m[2]) = x��������ߵ�Xһ������ǰ����ʽ�ӡ�

СHo��ÿ����ʽ�Ӷ�����ͨ���÷�������Ϊһ��ʽ�ӡ���ô����ֻҪ�ظ���������������Ϳ��Խ�n�������黯��Ϊһ�����̣��������һ�����Ľ��ˡ�

СHi��û����������������д��α����Ϊ��

M = m[1], R = r[1]
For i = 2 .. N
	d = gcd(M, m[i])
	c = r[i] - R
	If (c mod d) Then	// �޽�����
		Return -1
	End If
	(k1, k2) = extend_gcd(M / d, m[i] / d)	// ��չŷ����¼���k1,k2
	k1 = (c / d * k1) mod (m[i] / d)	// ��չ��ϵ
	R = R + k1 * M		// ����x = m[1] * k[1] + r[1]
	M = M / d * m[i] 	// ���lcm(M, m[i])
	R %= M 			// ���ϲ������R��ͬʱ��R��С
End For
If (R < 0) Then
	R = R + M
End If
Return R
Close
����
��1�У�1��������, N��2��N��1,000��

��2..N+1�У�2��������, ��i+1�б�ʾ��i��m,r��2��m��20,000,000��0��r<m��

��������о���ʹ��64λ���͡�

���
��1�У�1����������ʾ����Ҫ�����СX�����޽����-1���𰸷�Χ��64λ�����ڡ�

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
            return -1;  // �޽�����
        }
        pair<long long, long long> t = extend_gcd(M/d, m[i]/d); // ��չŷ����¼���

        //�����x��Ϊ�ؽ⣬������չ��һ����ϵ��X = x + k*lcm(m[1], m[2]) kΪ����
        //lcm(a,b)��ʾa��b����С������������⹫ʽΪlcm(a,b)=a*b/gcd(a,b)��

        t.first = (c/d*t.first)%(m[i]/d);// ��չ��ϵ
        // x = ((r[1]-r[0])/gcd(m[0],m[1])*x)%(m[1]/gcd(m[0],m[1]))

        /*
        ����ı���ʽΪ��
        X mod lcm(m[1], m[2]) = x��
        ��M = lcm(m[1], m[2]), R = x�������µ�ģ����X mod M = R��
        */
        R = R+t.first*M;
        M = M/d*m[i];   // ���lcm(M, m[i])
        R %= M;     // ���ϲ������R��ͬʱ��R��С
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

