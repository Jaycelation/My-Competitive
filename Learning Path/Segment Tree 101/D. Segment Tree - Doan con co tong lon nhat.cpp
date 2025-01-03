#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

int n, q, a[maxn];
struct Node {
	long long sum, pre, suf, id;
	Node(){}
	Node(int val) : sum(val), id(max(0, val)), suf(max(0, val)), pre(max(0, val)) {}
}segTree[maxn*4];

Node operator + (Node a, Node b) {
	Node ans;
	ans.sum = a.sum + b.sum;
	ans.pre = max(a.pre, b.pre + a.sum);
	ans.suf = max(b.suf, a.suf + b.sum);
	ans.id = max({a.id, b.id, a.suf + b.pre});
	return ans;
}

void update(int id, int start, int end, int pos, int val) {
	if (pos < start || end < pos) return;
	if (start == end) {
		segTree[id] = Node(val);
		return;
	}
	int mid = (start+end)/2;
	update(id*2, start, mid, pos, val);
	update(id*2+1, mid+1, end, pos, val);
	segTree[id] = segTree[id*2] + segTree[id*2+1];
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	
	while (q--) {
		int L, R; cin >> L >> R;
		update(1, 1, n, L, R);
		cout << segTree[1].id << "\n";
	}

	return 0;
}
