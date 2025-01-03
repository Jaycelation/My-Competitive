#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int n, k;
int minRange[MAXN], a[MAXN];

//Min max tren doan tinh tien
void problem_set_1() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	deque<int> dq;
	while (dq.size()) dq.pop_front();
	
	for (int i = 1; i <= n; ++i) {
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();
		
		dq.push_back(i);
		
		if (dq.front() + k <= i) dq.pop_front();
		
		if (i >= k) minRange[i] = a[dq.front()];
	}
	
	for (int i = n-k; i <= n; ++i) {
		cout << minRange[i] << " ";
	}
	cout << "\n";
}

int dp[MAXN], ans;

//
void problem_set_2() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	ans = 0;
	
	deque<int> dq;
	dq.push_back(0);
	
	for (int i = 1; i <= n+1; ++i) {
		while (dq.size() && dq.front() < i-k) {
			cout << dq.front() << " ";
			dq.pop_front();	
		} 
		dp[i] = dp[dq.front()] + a[i]; 
		ans += a[i];
		
		while (dq.size() && dp[dq.back()] >= dp[i]) dq.pop_back();
		
		dq.push_back(i);
		
	}
	cout << ans - dp[n+1] << "\n";
}

int main() {
	
	problem_set_2();


	return 0;
}
