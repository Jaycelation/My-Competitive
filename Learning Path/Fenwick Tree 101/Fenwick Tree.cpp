#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int bit[MAXN], n, q, a[MAXN];

int getSum(int p) {
	int idx = p, ans = 0;
	
	while (idx > 0) {
		ans += bit[idx];
		idx -= (idx & (-idx));
	}
	return ans;
}

void update(int u, int v) {
	int idx = u;
	while (idx <= n) {
		bit[idx] += v;
		idx += (idx & (-idx));
	}
}

void updateRange(int l, int r, int v) {
	update(l, v);
	update(r+1, -v);
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(i, a[i]);
	}

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, v; cin >> x >> v;
			update(x, v-a[x]);
			a[x] = v;
		} else {
			int x; cin >> x;
			cout << getSum(x) << "\n";
		}
	}

	return 0;
}
