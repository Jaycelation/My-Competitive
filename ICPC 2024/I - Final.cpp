#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		
		int a[n], b[n];
		
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		
		int cnt = 0, idx = n-1;
		for (int i = n-1; i >= 0; i--) {
			while (a[idx] != b[i] && idx >= 0) {
				idx--;
			}
			if (a[idx] == b[i]) {
				++cnt; 
			}
			
		}
		cout << n-cnt << "\n";
		
	}

	return 0;
}

