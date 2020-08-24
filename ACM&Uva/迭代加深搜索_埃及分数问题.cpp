// 埃及分数问题
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int maxd;

typedef long long LL;

LL gcd(LL a, LL b) {		//找到a、b的最小公倍数
	return b == 0 ? a : gcd(b, a%b);
}

// 返回满足1/c <= a/b的最小c
inline int get_first(LL a, LL b) {	//找到最大的1/c，使得1/c<a/b
	if (b%a == 0)	//该if可省去，因为b如果可以整除a，那么之前已经return了
		return b / a;
	else
		return b / a + 1;
}

const int maxn = 100 + 5;
LL v[maxn], ans[maxn];

// 如果当前解v比目前最优解ans更优，更新ans
bool better(int d) {
	for (int i = d; i >= 0; i--) if (v[i] != ans[i]) {
		//ans[i] == -1，说明前面深度较小的过程都没有得到正确解
		//v[i]<ans[i]  在那些个数相同的解中，找到最小分数最大的解
		return ans[i] == -1 || v[i] < ans[i];
	}
	return false;
}

// 当前深度为d，分母不能小于from，分数之和恰好为aa/bb
bool dfs(int d, int from, LL aa, LL bb) {
	if (d == maxd-1) {
		if (bb % aa) return false; // aa/bb必须是埃及分数，aa为1
		if (bb == v[d-1]) return false;	//之前哪个数使用过，即最后两个数相同
		v[d] = bb / aa;
		if (better(d)) memcpy(ans, v, sizeof(LL) * (d + 1));
		return true;
	}
	bool ok = false;
	from = max(from, get_first(aa, bb)); // 枚举的起点
	for (int i = from; ; i++) {
		// 剪枝：如果剩下的maxd+1-d个分数全部都是1/i，加起来仍然不超过aa/bb，则无解
		if (bb * (maxd - d) < i * aa) break;
		v[d] = i;
		// 计算aa/bb - 1/i，设结果为a2/b2
		LL b2 = bb * i;
		LL a2 = aa * i - bb;
		LL g = gcd(a2, b2); // 以便约分
		if (dfs(d + 1, i + 1, a2 / g, b2 / g)) ok = true;
	}
	return ok;
}

int main() {
	int a, b;
	cin >> a >> b;
	int ok = 0;
	for (maxd = 1; maxd <= 100; maxd++) {		//从1层逐渐迭代到100层,直到找到解
		memset(ans, -1, sizeof(ans));
		if (dfs(0, get_first(a, b), a, b)) {
			cout << a << "/" << b << "=";
			for (int i = 0; i < maxd - 1; i++) cout << "1/" << ans[i] << "+";
			cout << "1/" << ans[maxd - 1] << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
	return 0;
}

