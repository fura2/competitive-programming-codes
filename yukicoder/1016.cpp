#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(string s){
	int n=s.length();
	// o???...(odd)...?o
	if(n>=3 && n%2==1 && s[0]=='o' && s[n-1]=='o') return true;
	// oo?, ?oo
	rep(i,n-2){
		if(s[ i ]=='o' && s[i+1]=='o') return true;
		if(s[i+1]=='o' && s[i+2]=='o') return true;
	}
	// ?o??, ??o?
	rep(i,n-3){
		if(s[i+1]=='o' || s[i+2]=='o') return true;
	}
	return false;
}

void solve(){
	int n;
	string s; cin>>n>>s;

	int pre=0;
	rep(i,n+1) if(i==n || s[i]=='x') {
		if(check(s.substr(pre,i-pre))){
			puts("O");
			return;
		}
		pre=i+1;
	}
	puts("X");
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
