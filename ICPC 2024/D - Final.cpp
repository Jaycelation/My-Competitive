#include <bits/stdc++.h>
using namespace std;

bool check(int i, int j, float x, float y, float r) {
	return (i-x)*(i-x) + (j-y)*(j-y) <= r*r;
}

int main() {
	float xa, ya, r;
	cin >> xa >> ya >> r;
	
	int le = -r+xa; //cout << le << "\n";
	int ri = r+xa; //cout << ri << "\n";
	long long cnt = 0;
	//int val = left + right + 1;
	for (int i = le; i <= ri; ++i) {
		int x = i;
		int left = ya - sqrt((r*r - (x-xa)*(x-xa)));
		int right = ya + sqrt((r*r - (x-xa)*(x-xa)));	
		
		while (!check(i, left, xa, ya, r) && left <= right) {
			++left;
		}
		while (!check(i, right, xa, ya, r) && right >= left) {
			right--;
		}
		cnt += right - left + 1;
		//cnt += right - left + 1;
		//cout << left << " " << right << "\n";
//		for (int j = left; j <= right; ++j) {
//			//cnt++;
//			if (check(i, j, xa, ya, r)) {
//				//cout << i << " " << j << "\n";
//				++cnt;
//			}
//		}

		


	}
	
	cout << cnt << "\n";
	
	return 0;
}



