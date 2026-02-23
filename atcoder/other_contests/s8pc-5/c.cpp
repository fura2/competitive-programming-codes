#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	string s; cin>>s;
	int n=s.length();

	int mx=0,mn=0,cur=0;
	rep(i,n){
		if(s[i]=='(') cur++;
		else          cur--;
		mx=max(mx,cur);
		mn=min(mn,cur);
	}
	puts(cur==0&&mx<=n/4&&mn>=-n/4?"Yes":"No");
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
