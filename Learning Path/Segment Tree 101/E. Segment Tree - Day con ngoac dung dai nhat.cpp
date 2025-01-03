#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000006;

string s; 
int n, q;
struct Node {
	int left, right, result;
};

Node operator + (Node a, Node b) {
	int val = min(a.left, b.right);
	int result = a.result + b.result + val*2;
	int left = a.left + b.left - val;
	int right = a.right + b.right - val;
	Node res = {left, right, result};
	return res;
}

Node segTree[MAXN*4];

void build (int id, int start, int end) {
	if (start == end) {
		segTree[id] = {0, 0, 0};
		if (s[start] == '(') 
			segTree[id].left = 1;
		else 
			segTree[id].right = 1;
		return;
	}
	int mid = (start + end) >> 1;
	build(id*2, start, mid);
	build(id*2+1, mid+1, end);
	segTree[id] = segTree[id*2] + segTree[id*2+1];
}

Node query(int id, int start, int end, int L, int R) {
	if (end < L || R < start) {
		return {0, 0, 0};
	}
	if (L <= start && end <= R) {
		return segTree[id];
	}
	int mid = (start + end) >> 1;
	return query(id*2, start, mid, L, R) + query(id*2+1, mid+1, end, L, R);
}

int main() {
	cin >> s >> q;
	n = s.size();
	s = ' ' + s;
	build(1, 1, n);
	while (q--) {
		int L, R; cin >> L >> R;
		Node ans = query(1, 1, n, L, R);
		cout << ans.result << "\n";
	}

	return 0;
}

