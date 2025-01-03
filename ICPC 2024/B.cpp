#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int chiahet(string s, int n) {
	int uoc = 0, val = 1 % n;
	for (int i = s.size()-1; i >= 0; i--) {
		uoc = (uoc + (s[i]-'0') % n) * (val % n) % n;
		val = (val * 10) % n;
	}
	return uoc;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		dequeue<string> q;
		
		q.push_back("6");
		q.push_front("8");
	
		while (chiahet(q.front(), n) != 0 && q.front().size() <= 200 && !q.empty()) {
			string v = q.front();
			q.push(v+"6");
			q.push(v+"8"); 
			q.pop();
		}
		if (chiahet(q.front(), n) == 0 && q.front().size() <= 200) {
			cout << q.front() << "\n";
		} else {
			cout << -1 << "\n";
		}
		
	}

	return 0;
}

