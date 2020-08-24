// ������������
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int maxd;

typedef long long LL;

LL gcd(LL a, LL b) {		//�ҵ�a��b����С������
	return b == 0 ? a : gcd(b, a%b);
}

// ��������1/c <= a/b����Сc
inline int get_first(LL a, LL b) {	//�ҵ�����1/c��ʹ��1/c<a/b
	if (b%a == 0)	//��if��ʡȥ����Ϊb�����������a����ô֮ǰ�Ѿ�return��
		return b / a;
	else
		return b / a + 1;
}

const int maxn = 100 + 5;
LL v[maxn], ans[maxn];

// �����ǰ��v��Ŀǰ���Ž�ans���ţ�����ans
bool better(int d) {
	for (int i = d; i >= 0; i--) if (v[i] != ans[i]) {
		//ans[i] == -1��˵��ǰ����Ƚ�С�Ĺ��̶�û�еõ���ȷ��
		//v[i]<ans[i]  ����Щ������ͬ�Ľ��У��ҵ���С�������Ľ�
		return ans[i] == -1 || v[i] < ans[i];
	}
	return false;
}

// ��ǰ���Ϊd����ĸ����С��from������֮��ǡ��Ϊaa/bb
bool dfs(int d, int from, LL aa, LL bb) {
	if (d == maxd-1) {
		if (bb % aa) return false; // aa/bb�����ǰ���������aaΪ1
		if (bb == v[d-1]) return false;	//֮ǰ�ĸ���ʹ�ù����������������ͬ
		v[d] = bb / aa;
		if (better(d)) memcpy(ans, v, sizeof(LL) * (d + 1));
		return true;
	}
	bool ok = false;
	from = max(from, get_first(aa, bb)); // ö�ٵ����
	for (int i = from; ; i++) {
		// ��֦�����ʣ�µ�maxd+1-d������ȫ������1/i����������Ȼ������aa/bb�����޽�
		if (bb * (maxd - d) < i * aa) break;
		v[d] = i;
		// ����aa/bb - 1/i������Ϊa2/b2
		LL b2 = bb * i;
		LL a2 = aa * i - bb;
		LL g = gcd(a2, b2); // �Ա�Լ��
		if (dfs(d + 1, i + 1, a2 / g, b2 / g)) ok = true;
	}
	return ok;
}

int main() {
	int a, b;
	cin >> a >> b;
	int ok = 0;
	for (maxd = 1; maxd <= 100; maxd++) {		//��1���𽥵�����100��,ֱ���ҵ���
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

