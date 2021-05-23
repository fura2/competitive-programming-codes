#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

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
	vector<int> cost(n),to(n);
	rep(u,n) scanf("%d%d",&cost[u],&to[u]), to[u]--;

	double ans=accumulate(cost.begin(),cost.end(),0)/2.0;
	for(auto C:find_cycles(to)){
		int mn=INF;
		for(int u:C) mn=min(mn,cost[u]);
		ans+=mn/2.0;
	}
	printf("%.1f\n",ans);

	return 0;
}
