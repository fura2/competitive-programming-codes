// Day 2: Regions

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

int n;
weighted_graph<int> T;

int diam,d_max[200000];

int dfs(int u,int p){
	int res=0;
	vector<int> L;
	for(auto e:T[u]){
		int v=e.to;
		if(v==p) continue;

		res+=dfs(v,u);

		if(d_max[v]+e.wt>diam){ // remove the edge (u,v)
			res++;
		}
		else{
			L.emplace_back(d_max[v]+e.wt);
		}
	}

	int m=L.size();
	sort(L.begin(),L.end());

	d_max[u]=0;
	rep(i,m){
		if(d_max[u]+L[i]>diam){
			res++;
		}
		else{
			d_max[u]=L[i];
		}
	}
	return res;
}

int main(){
	int k; scanf("%d%d",&n,&k);
	T.resize(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(T,u,v,c);
	}

	int lo=-1,hi=100*n;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		diam=mi;
		int res=dfs(0,-1)+1;

		if(res<=k) hi=mi;
		else       lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
