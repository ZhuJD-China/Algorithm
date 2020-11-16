// UVa548 Tree
// Rujia Liu
// ���⣺��һ�õ��Ȩ��Ȩ������ͬ��������������������������ͺ����������һ��Ҷ��ʹ����������·���ϵ�Ȩ����С������ж�⣬��Ҷ�ӱ����ȨӦ����С
// �㷨���ݹ齨����Ȼ��DFS��ע�⣬ֱ�ӵݹ�����Ҳ���ԣ������Ƚ����ķ�������ֱ�ۣ����Ҹ��õ���
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

// ��Ϊ��������Ȩֵ������ͬ�Ҷ�����������ֱ����Ȩֵ��Ϊ�����
const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int* a) {
  string line;
  if(!getline(cin, line)) return false;
  stringstream ss(line);
  n = 0;
  int x;
  while(ss >> x) a[n++] = x;
  return n > 0;
}

// ��in_order[L1..R1]��pre_order[L3..R3]����һ�ö���������������
int build(int L1, int R1, int L3, int R3) {
  if(L1 > R1) return 0; // ����
  int root = post_order[L3];
  int p = L1;
  while(in_order[p] != root) p++;
  int cnt = p-L1; // �������Ľ�����
  lch[root] = build(L1, p-1, L3+1, L3+cnt);
  rch[root] = build(p+1, R1, L3+cnt+1, R3);
  return root;
}

int best, best_sum; // ĿǰΪֹ�����Ž�Ͷ�Ӧ��Ȩ��

void dfs(int u, int sum) {
  sum += u;
  if(!lch[u] && !rch[u]) { // Ҷ��
    if(sum < best_sum || (sum == best_sum && u < best)) { best = u; best_sum = sum; }
  }
  if(lch[u]) dfs(lch[u], sum);
  if(rch[u]) dfs(rch[u], sum);
}

void print()
{
	for(int i=0;i<10;i++){
		printf("%d ", lch[i]);
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		printf("%d ", rch[i]);
	}
	cout<<endl;
}

int main() {
  while(read_list(in_order)) {
    read_list(post_order);
    build(0, n-1, 0, n-1);
    print();
    best_sum = 1000000000;
    dfs(post_order[0], 0);
    cout << best << "\n";
  }
  return 0;
}

