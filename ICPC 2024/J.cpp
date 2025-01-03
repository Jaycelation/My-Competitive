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

long long val(long long n) {
	long long result = 0;
	long long dp[16] = {1};
	dp[1] = 45;
	for (int i = 2; i <= 15; ++i) {
		long long tmp = 0;
		for (int j = 1; j <= i; ++j) {
			tmp += 9*dp[j];
		}
		dp[i] = pow(10, i-1)*45 + tmp;
	} 
	return result;
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
