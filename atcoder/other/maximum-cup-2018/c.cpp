#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

vector<vector<int>> cycles(const vector<int>& f){
	int n=f.size();
	vector<vector<int>> res;
	vector<int> color(n,-1);
	rep(u,n) if(color[u]==-1) {
		int v=u;
		do{ color[v]=u; v=f[v]; }while(color[v]==-1);
		if(color[v]==u){
			vector<int> C;
			int w=v;
			do{ C.emplace_back(v); v=f[v]; }while(v!=w);
			res.emplace_back(C);
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> f(n);
	rep(i,n) scanf("%d",&f[i]), f[i]--;

	int ans=0;
	for(auto C:cycles(f)){
		if(C.size()%2==1){
			puts("-1");
			return 0;
		}
		ans+=C.size()/2;
	}
	printf("%d\n",ans);

	return 0;
}
