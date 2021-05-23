#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n,m; scanf("%lld%lld",&n,&m);

	if(m<n-1 || (n/2)*(n-n/2)<m){
		puts("NO");
		return 0;
	}

	set<pair<int,int>> E;
	rep(i,n-1){
		E.emplace(i/2,n/2+(i+1)/2);
	}
	rep(u,n/2){
		if(E.size()==m) break;
		for(int v=n/2;v<n;v++){
			if(E.size()==m) break;
			E.emplace(u,v);
		}
	}

	puts("YES");
	rep(u,n) printf("%d%c",u<n/2?1+u:100000-(u-n/2),u<n-1?' ':'\n');
	for(auto [u,v]:E) printf("%d %d\n",u+1,v+1);

	return 0;
}
