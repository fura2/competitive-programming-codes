#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	rep(_,n){
		string s,t; cin>>s>>t;
		int n=s.length(),m=t.length();
		int idx=0;
		rep(i,n) if(idx<m && s[i]==t[idx]) idx++;
		if(idx==m) return puts("YES"),0;
	}
	puts("NO");

	return 0;
}
