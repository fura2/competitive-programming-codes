#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	string s; cin>>s;
	int n=s.length();

	int ans=11;
	rep(i,n) for(int j=i+4;j+7<=n;j++) {
		int cost=11;
		if(s[i  ]=='g') cost--;
		if(s[i+1]=='o') cost--;
		if(s[i+2]=='o') cost--;
		if(s[i+3]=='d') cost--;
		if(s[j  ]=='p') cost--;
		if(s[j+1]=='r') cost--;
		if(s[j+2]=='o') cost--;
		if(s[j+3]=='b') cost--;
		if(s[j+4]=='l') cost--;
		if(s[j+5]=='e') cost--;
		if(s[j+6]=='m') cost--;
		ans=min(ans,cost);
	}
	printf("%d\n",ans);
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
