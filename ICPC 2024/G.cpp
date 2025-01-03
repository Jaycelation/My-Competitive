#include <bits/stdc++.h>
using namespace std;

long long count(long long m) {
	long long val = 0;
	for (int i = 1; i <= sqrt(m); ++i) {
		if (m % i == 0) {
			if (m / i == i) {
				val += 1;
			} else {
				val += 2;
			}
		}
	}
	return val;
}

int main() {
	long long m; cin >> m;
	long long result = count(2*m);
	for (int i = 1; i <= sqrt(2*m); ++i) {
		if ((2*m) % i == 0) {
			if (((2*m)/i + 1-i) % 2 != 0) {
				result--;
			}
			if ((i+1-2*m/i) % 2 != 0) {
				result--;
			}
		}
	}
	cout << result << "\n";

	return 0;
}

