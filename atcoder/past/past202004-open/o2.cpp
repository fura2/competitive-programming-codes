#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class persistent_union_find{
	int n,t;
	vector<int> p,t0;
	vector<vector<pair<int,int>>> Sz;
public:
	persistent_union_find(int n):n(n),t(0),p(n,-1),t0(n,1e9),Sz(n,{make_pair(-1,1)}){}
	int find(int u,int t){
		while(t>t0[u]) u=find(p[u],t);
		return u;
	}
	void unite(int u,int v){
		u=find(u,t); v=find(v,t);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u;
			t0[v]=t;
			Sz[u].emplace_back(t,-p[u]);
			n--;
		}
		t++;
	}
	bool is_same(int u,int v,int t){ return find(u,t)==find(v,t); }
	int size()const{ return n; }
	int size(int u,int t){
		u=find(u,t);
		return (--lower_bound(Sz[u].begin(),Sz[u].end(),make_pair(t,0)))->second;
	}
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<tuple<lint,int,int,int>> E(m);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		E[i]={c,u,v,i};
	}

	sort(E.begin(),E.end());

	// Kruskal
	lint cost=0;
	vector<bool> used(m);
	persistent_union_find U(n);
	vector<lint> his; // his[i] = i 回目に選んだ辺のコスト
	for(const auto& e:E){
		lint wt;
		int u,v,id; tie(wt,u,v,id)=e;
		if(!U.is_same(u,v,his.size())){
			U.unite(u,v);
			cost+=wt;
			used[id]=true;
			his.emplace_back(wt);
		}
	}

	vector<lint> ans(m);
	rep(i,m){
		lint c;
		int u,v,id; tie(c,u,v,id)=E[i];

		int lo=0,hi=his.size();
		while(hi-lo>1){
			int mi=(lo+hi)/2;
			if(U.is_same(u,v,mi)) hi=mi;
			else                  lo=mi;
		}
		ans[id]=cost-his[hi-1]+c;
	}
	rep(i,m) printf("%lld\n",ans[i]);

	return 0;
}
