#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> in(n),out(n);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		in[v]++;
		out[u]++;
	}

	int ans=0;
	rep(u,n) if(in[u]>out[u]) ans+=in[u]-out[u];
	printf("%d\n",ans);
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
