#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	graph T(n+1);
	int root=-1;
	rep(u,n){
		int v; scanf("%d",&v); v--;
		if(v==-1) root=u;
		else      add_undirected_edge(T,u,v);
	}
	add_undirected_edge(T,n,root);
	root=n;

	vector<int> dep(n+1,-1);
	dep[root]=0;
	queue<pair<int,int>> Q; Q.emplace(root,-1);
	while(!Q.empty()){
		int v,p;
		tie(v,p)=Q.front(); Q.pop();
		for(int w:T[v]) if(w!=p) {
			dep[w]=dep[v]+1;
			Q.emplace(w,v);
		}
	}

	vector<int> ans(n,-1);
	bool used[300]={};
	rep(i,m){
		rep(u,n){
			bool ok=false;
			vector<int> a;
			queue<pair<int,int>> Q; Q.emplace(root,-1);
			while(!Q.empty()){
				int v,p;
				tie(v,p)=Q.front(); Q.pop();
				for(int w:T[v]) if(w!=p && !used[w]) {
					if(w==u){
						ok=true;
					}
					else{
						a.emplace_back(dep[w]);
						Q.emplace(w,v);
					}
				}
			}
			if(!ok) continue;

			int m2=m-i-1;
			if(a.size()>=m2
			&& k-dep[u]>=accumulate(a.begin(),a.begin()+m2,0)
			&& k-dep[u]<=accumulate(a.end()-m2,a.end(),0)){
				ans[i]=u;
				used[u]=true;
				k-=dep[u];
				break;
			}
		}

		if(ans[i]==-1){
			puts("-1");
			return 0;
		}
	}

	rep(i,m) printf("%d%c",ans[i]+1,i<m-1?' ':'\n');

	return 0;
}
