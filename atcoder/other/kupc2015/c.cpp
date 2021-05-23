#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

void solve(){
	int n; scanf("%d",&n);
	int d[30][30];
	rep(u,n) rep(v,n) {
		scanf("%d",&d[u][v]);
		if(d[u][v]==-1) d[u][v]=INF;
	}

	rep(u,n) if(d[u][u]!=0) {
		puts("NO");
		return;
	}

	rep(u,n) rep(v,n) rep(w,n) {
		if(d[u][v]+d[v][w]<d[u][w]){
			puts("NO");
			return;
		}
	}

	puts("YES");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
