#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

int m,val[200];
weighted_graph<int> T;

vector<int> dfs(int u,int p){
	vector<int> res(m+1);
	res[0]=val[u];

	for(auto e:T[u]) if(e.to!=p) {
		int v=e.to;
		auto tmp=dfs(v,u),next=res;
		rep(w1,m+1) rep(w2,m+1) {
			if(w1+2*e.wt+w2>m) break;
			next[w1+2*e.wt+w2]=max(next[w1+2*e.wt+w2],res[w1]+tmp[w2]);
		}
		res=next;
	}
	return res;
}

int main(){
	int n; scanf("%d%d",&n,&m);
	rep(u,n) scanf("%d",&val[u]);
	T.resize(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_undirected_edge(T,u,v,c);
	}

	auto ans=dfs(0,-1);
	printf("%d\n",*max_element(ans.begin(),ans.end()));

	return 0;
}
