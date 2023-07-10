#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_undirected_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
	G[v].emplace_back(u,wt);
}

template<class T>
pair<vector<int>,vector<edge<T>>> odd_cycle(const weighted_graph<T>& G){
	int n=G.size();
	vector<int> color(n,-1);

	vector<int> res1;
	vector<edge<T>> res2;

	auto dfs=[&](auto&& dfs,int u,int c)->bool{
		color[u]=c;
		for(auto e:G[u]){
			if(color[e.to]==-1){
				if(dfs(dfs,e.to,1-c)){
					if(res2[0].to!=res1.back()){
						res1.emplace_back(u);
						res2.emplace_back(e);
					}
					return true;
				}
			}
			else if(color[e.to]==c){
				res1.emplace_back(u);
				res2.emplace_back(e);
				return true;
			}
		}
		return false;
	};

	rep(u,n) if(color[u]==-1 && dfs(dfs,u,0)) {
		reverse(res1.begin(),res1.end());
		reverse(res2.begin(),res2.end());
		break;
	}
	return {res1,res2};
}

const long long INF=1LL<<61;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v;
		lint c; scanf("%d%d%lld",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	auto [C,E]=odd_cycle(G);

	if(!C.empty()){
		lint sum=0;
		rep(i,E.size()){
			if(i%2==0) sum+=E[i].wt;
			else       sum-=E[i].wt;
		}
		if(sum%2==1){
			puts("0");
			return 0;
		}

		bool ok=(sum>=2);
		vector<lint> val(n,INF);
		val[C[0]]=sum/2;

		queue<int> Q;
		Q.emplace(C[0]);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			if(!ok) break;
			for(auto e:G[u]){
				if(val[e.to]==INF){
					if(e.wt-val[u]<=0){
						ok=false;
					}
					val[e.to]=e.wt-val[u];
					Q.emplace(e.to);
				}
				else if(val[e.to]!=e.wt-val[u]){
					ok=false;
				}
			}
		}
		puts(ok?"1":"0");
		return 0;
	}

	bool ok=true;
	vector<int> color(n,-1);
	vector<lint> val(n);
	color[0]=0;
	val[0]=0;

	queue<int> Q;
	Q.emplace(0);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		if(!ok) break;
		for(auto e:G[u]){
			if(color[e.to]==-1){
				color[e.to]=1-color[u];
				val[e.to]=e.wt-val[u];
				Q.emplace(e.to);
			}
			else if(val[e.to]!=e.wt-val[u]){
				ok=false;
			}
		}
	}
	if(!ok){
		puts("0");
		return 0;
	}

	lint L=INF,R=INF;
	rep(u,n){
		if(color[u]==0) L=min(L,val[u]);
		else            R=min(R,val[u]);
	}
	printf("%lld\n",max((R-1)-(1-L)+1,0LL));

	return 0;
}
