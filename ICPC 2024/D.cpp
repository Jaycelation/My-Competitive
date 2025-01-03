#include <bits/stdc++.h>
using namespace std;
int n,size;
vector<int> a;
void Try(int t){
	if(n==0) return;
	if(t==0) {
		for(int i=1;i<=9;i++){
			if(n==0) return;
			a[t]=i;
			if(t==size-1) n--;
			else Try(t+1);
		}
	}
	else {
		for(int i=a[t-1]-1;i<=a[t-1]+1;i++){
			if(n==0) return;
			if(i==-1||i==10) continue;
			a[t]=i;
			if(t==size-1) n--;
			else Try(t+1);
			
		}
	}
	
}
int main() {
	cin>>n;size=1;
	while(1){
		a.resize(size);
		Try(0);
		size+=1;
		if(n==0) break;
	}
	for(int i=0;i<size-1;i++){
		cout<<a[i];
	}
	return 0;
}

