#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int arr[MAXN], n, q;
long long segTree[4*MAXN];

void build(int id, int start, int end) {
    if (start == end) {
        segTree[id] = arr[start]; 
        return;
    }
    int mid = (start + end) / 2;
    build(2*id, start, mid);
    build(2*id+1, mid+1, end);
    segTree[id] = segTree[2*id] + segTree[2*id+1];
}

long long query(int id, int start, int end, int L, int R) {
    if (start > R || end < L) {
    	return 0;
    }
    if (start >= L && end <= R) {
        return segTree[id];
    }
    int mid = (start + end) / 2;
    return query(2*id, start, mid, L, R) + query(2*id+1, mid+1, end, L, R);
}

void update(int id, int start, int end, int pos, int val) {
    if (pos < start || pos > end) return;
    if (start == end) {
    	segTree[id] = val;
    	arr[start] = val;
    	return;
	}
	int mid = (start + end) / 2;
	update(id*2, start, mid, pos, val);
	update(id*2+1, mid+1, end, pos, val);
	segTree[id] = segTree[id*2] + segTree[id*2+1];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
	
    build(1, 1, n);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x, v;
            cin >> x >> v;
            update(1, 1, n, x, v);
        } else if (type == 2) {
            int X; cin >> X;
            cout << query(1, 1, n, 1, X) << "\n";
        }
    }

    return 0;
}
