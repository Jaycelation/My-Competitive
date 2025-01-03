#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
long long ans;
int bit[MAXN], n, a[MAXN];

int getSum(int x) {
	int s = 0;
	while (x <= n) {
		s += bit[x];
		x += x & -x;
	}
	return s;
}

void update(int x, int val) {
	while (x > 0) {
		bit[x] += val;
		x -= x & -x;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		update(a[i], 1);
		ans += getSum(a[i]+1);
	}
	cout << ans << "\n";
	return 0;
}
