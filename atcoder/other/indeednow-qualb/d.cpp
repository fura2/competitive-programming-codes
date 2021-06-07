#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,c; scanf("%d%d",&n,&c);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector L(c,vector<int>(1,-1));
	rep(i,n){
		L[a[i]].emplace_back(i);
	}
	rep(x,c) L[x].emplace_back(n);

	rep(x,c){
		lint ans=n*(n+1LL)/2;
		rep(i,L[x].size()-1){
			lint w=L[x][i+1]-L[x][i];
			ans-=w*(w-1)/2;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
