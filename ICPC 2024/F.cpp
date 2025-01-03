#include <bits/stdc++.h>
using namespace std;

//string next(string s) {
//	int result = (s[0]-'0')*100 + (s[1]-'0')*10 + (s[0]-'0') + 8;
//	return res;
//}
bool check(int i){
	string s = to_string(i);
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') return false;
	}
	return true;
}

int main() {
	string s; cin >> s;
	
	vector<string> v;
	for(int i=104;i<=992;i+=8){
		if(check(i)) v.push_back(to_string(i));
	}

	if (s.size() == 1) {
		if (s == "8") {
			cout << "YES\n";
		} else {
			cout << "NO";
		}
	}else if (s.size() == 2) {
		if (((s[1]-'0')*10 + (s[0]-'0'))%8==0 || ((s[0]-'0')*10 + (s[1]-'0'))%8==0 ) 
			cout << "YES";
		else cout << "NO";
	} else {
		map<char, int> m1;
		
		for (int i = 0; i < s.size(); ++i) {
			m1[s[i]]++;
		}
		for(int i=0;i<v.size();i++){
			map<char,int> m(m1.begin(), m1.end());
			m[v[i][0]]--;
			m[v[i][1]]--;
			m[v[i][2]]--;
			if(m[v[i][0]]>=0 && m[v[i][1]]>=0 && m[v[i][2]]>=0){
				cout<<"YES\n";
				return 0;
			}
		}
		cout<<"NO\n";
	}

	return 0;
}


