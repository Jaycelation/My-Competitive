#include <bits/stdc++.h>
using namespace std;

#define N 1000
#define M 10

int val[M][N], dp[N], a[M][N];
int n, m;   

bool check(int x, int y) {
    for (int i = 0; i < m; ++i) {
        if (val[i][x] > val[i][y])
            return 0;
    }
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> a[i][j];
			val[i][--a[i][j]] = j;    		
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (check(a[0][j], a[0][i])) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	
	int result = 1;
	for (int i = 0; i < n; ++i) {
		result = max(result, dp[i]);
	}
	cout << result << "\n";
	
    return 0;
}
