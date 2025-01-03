#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	map<int, int> mapR;
	map<int, int> mapG;
	map<int, int> mapB;
	vector<int> vr, vg, vb;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			vr.push_back(i);
		}
		else if (s[i] == 'G') {
			vg.push_back(i);
		}
		else {
			vb.push_back(i);
		}
	}
	for (int i : vr) {
		mapR[i*2] = 1;
	}
	for (int i : vg) {
		mapG[i*2] = 1;
	}
	for (int i : vb) {
		mapB[i*2] = 1;
	}
	
	
	long long result = vr.size()*vg.size()*vb.size();
	for (int i = 0; i < vr.size(); ++i) {
		for (int j = 0; j < vg.size(); ++j) {
			if (mapB[vr[i] + vg[j]]) {
				result--;
			}
		}
	}
	for (int i = 0; i < vg.size(); ++i) {
		for (int j = 0; j < vb.size(); ++j) {
			if (mapR[vg[i] + vb[j]]) {
				result--;
			}
		}
	}
	for (int i = 0; i < vb.size(); ++i) {
		for (int j = 0; j < vr.size(); ++j) {
			if (mapG[vb[i] + vr[j]]) {
				result--;
			}
		}
	}
	cout << result << "\n";

	return 0;
}

