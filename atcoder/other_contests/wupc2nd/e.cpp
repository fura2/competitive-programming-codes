#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

class two_edge_connected_components{
	int idx;
	vector<int> ord,low,id;
	const graph& G;

	vector<vector<int>> Comp;
	vector<pair<int,int>> B;
	graph Tr;

	void dfs1(int u,int p){
		ord[u]=low[u]=idx++;
		bool f=true;
		for(int v:G[u]){
			if(v==p && f){ f=false; continue; }
			if(ord[v]==-1){
				dfs1(v,u);
				low[u]=min(low[u],low[v]);
			}
			else{
				low[u]=min(low[u],ord[v]);
			}
		}
	}

	void dfs2(int u,int p){
		if(p==-1 || ord[p]<low[u]){
			id[u]=idx++;
			if(p!=-1) B.emplace_back(minmax(p,u));
		}
		else{
			id[u]=id[p];
		}
		for(int v:G[u]) if(id[v]==-1) dfs2(v,u);
	}

public:
	two_edge_connected_components(const graph& G):G(G){
		int n=G.size();

		idx=0;
		ord.assign(n,-1);
		low.assign(n,-1);
		rep(u,n) if(ord[u]==-1) dfs1(u,-1);

		idx=0;
		id.assign(n,-1);
		rep(u,n) if(id[u]==-1) dfs2(u,-1);

		Comp.resize(idx);
		Tr.resize(idx);
		rep(u,n){
			Comp[id[u]].emplace_back(u);
			for(int v:G[u]) if(id[u]!=id[v]) Tr[id[u]].emplace_back(id[v]);
		}
	}

	int operator[](int i)const{ return id[i]; }

	const vector<int>& component(int i)const{ return Comp[i]; }
	const vector<pair<int,int>>& bridges()const{ return B; }
	const graph& bridge_block_tree()const{ return Tr; }
};

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);

	graph G(n);
	union_find U(n);
	vector<tuple<int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v);
		U.unite(u,v);
		E[i]={min(u,v),max(u,v),c};
	}

	auto B=two_edge_connected_components(G).bridges();

	vector<int> costB,costC; // bridge, cycle
	rep(i,m){
		bool b=false;
		for(auto e:B) if(get<0>(E[i])==e.first && get<1>(E[i])==e.second) b=true;
		if(b) costB.emplace_back(get<2>(E[i]));
		else  costC.emplace_back(get<2>(E[i]));
	}
	sort(costB.begin(),costB.end());
	sort(costC.begin(),costC.end());

	k-=U.size();
	if(k<=0) return puts("0"),0;

	int ans=INT_MAX;
	// 橋だけを消す
	if(costB.size()>=k){
		ans=min(ans,accumulate(costB.begin(),costB.begin()+k,0));
	}
	// 閉路の辺も消す
	if(!costC.empty()){
		costB.insert(costB.end(),costC.begin()+1,costC.end());
		sort(costB.begin(),costB.end());
		ans=min(ans,costC[0]+accumulate(costB.begin(),costB.begin()+k,0));
	}
	printf("%d\n",ans);

	return 0;
}
