#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<vector<int>> find_cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> Res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			Res.emplace_back(C);
		}
	}
	return Res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> f(n);
	rep(u,n) scanf("%d",&f[u]), f[u]--;

	vector<int> ans(n);
	for(auto C:find_cycles(f)) for(int u:C) ans[u]=C.size();
	rep(u,n) printf("%d%c",ans[u],u<n-1?' ':'\n');

	return 0;
}
