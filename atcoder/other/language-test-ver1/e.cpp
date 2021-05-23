#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y; scanf("%lld/%lld",&x,&y);

	lint g=gcd(x,y);
	x/=g;
	y/=g;

	vector<pair<lint,lint>> ans;
	// (n+1)/2-m/n = x/y
	// m = n(n+1)/2 - nx/y
	for(lint n=x/y*2-1;n<x/y*2+3;n++){
		if(n>0 && n%y==0){
			lint m=n*(n+1)/2-n/y*x;
			if(1<=m && m<=n){
				ans.emplace_back(n,m);
			}
		}
	}
	if(ans.empty()) puts("Impossible");
	else{
		rep(i,ans.size()) printf("%lld %lld\n",ans[i].first,ans[i].second);
	}

	return 0;
}
