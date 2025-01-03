#include <bits/stdc++.h>
using namespace std;

long long tongCs(long long n) {
	long long tong = 0;
	while (n > 0) {
		tong += n % 10;
		n /= 10;
	}
	return tong;
}

int main() {
	int T; cin >> T;
	while (T--) {
		long long a, b;
		long long tong = 0;
		cin >> a >> b;
		for (int i = a; i <= b; ++i) {
			tong += tongCs(i);
		}
		cout << tong << "\n";
	}

	return 0;
}

