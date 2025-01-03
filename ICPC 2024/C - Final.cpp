#include <bits/stdc++.h>
using namespace std;
int n,m;
long long res = 0;
vector<int> a,b;
map<int,int> m1;
long long nCm(long long x,long long y){
	y=min(y,x-y);
	long long res =1;
	for(int i=1;i<=y;i++){
		res*=x-i+1;
		res/=i;
	}
	return res;
}
void check(){
	int cnt=0;
	int t=1;
	map<int,int> m2(m1.begin(),m1.end());
	for(int i=0;i<b.size();i++){
		if(b[i]==1){
			m2[a[i]]--;
			t*=a[i];
			cnt++;
		}
	}
	if(cnt==1) return;
	m2[1]+=cnt-1;
	if(t!=1) m2[t]++;
	if(!m1[1]) return;
	int N=n;
	long long Res=1;
	for(auto x:m2){
		cout<<x.first<<" "<<x.second<<endl;
		if(x.second==0) continue;
		Res*=nCm(N,x.second);
		N-=x.second;
	}
	cout<<endl;
	res+=Res;
}
void Try(int t){
	for(int i=0;i<=1;i++){
		b[t]=i;
		if(t==a.size()-1) check();
		else Try(t+1);
	}
}
int main() {
	cin>>n>>m;
	int M=m;
	int cnt=0;
	for(int i =2;i<=sqrt(M);i++){
		while(M%i==0) {
			m1[i]++;
			a.push_back(i);
			cnt++;
			M/=i;
		}
	}
	if(M!=1) a.push_back(M);
	
	
	b.resize(a.size());
	m1[1]=cnt-n;
	Try(0);
	cout<<res;
	return 0;
}

