#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

int n;
graph T;

vector<int> color;

void dfs(int u,int p,int dep){
	color[u]=dep%2;
	for(int v:T[u]) if(v!=p) dfs(v,u,dep+1);
}

int main(){
	scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v);
		T[v].emplace_back(u);
	}

	color.resize(n);
	dfs(0,-1,0);

	int nb=count(color.begin(),color.end(),0);
	int nw=count(color.begin(),color.end(),1);

	if(nb>nw){
		swap(nb,nw);
		rep(u,n) color[u]=1-color[u];
	}

	vector<int> ans(n);
	if(nb<=n/3){
		int bcnt=3,wcnt=1;
		rep(u,n){
			if(color[u]==0) ans[u]=bcnt, bcnt+=3;
			else            ans[u]=wcnt, wcnt+=(wcnt%3==1?1:2);
		}
		rep(u,n) if(ans[u]>n) ans[u]=bcnt, bcnt+=3;
	}
	else{
		int bcnt=1,wcnt=2;
		rep(u,n){
			if(color[u]==0) ans[u]=bcnt, bcnt+=3;
			else            ans[u]=wcnt, wcnt+=3;
		}
		int cnt=3;
		rep(u,n) if(ans[u]>n) ans[u]=cnt, cnt+=3;
	}
	rep(u,n) printf("%d%c",ans[u],u<n-1?' ':'\n');

	return 0;
}
