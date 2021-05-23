#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

template<class G>
class Fenwick_tree{
	vector<G> a;
public:
	Fenwick_tree(){}
	Fenwick_tree(int n){ build(n); }
	Fenwick_tree(const vector<G>& a){ build(a); }
	void build(int n){
		a.assign(n,G{});
	}
	void build(const vector<G>& a){
		this->a=a;
		for(int i=1;i<a.size();i++) if(i+(i&-i)-1<a.size()) (this->a)[i+(i&-i)-1]+=(this->a)[i-1];
	}
	void add(int i,const G& val){
		for(i++;i<=a.size();i+=i&-i) a[i-1]+=val;
	}
	G sum(int l,int r)const{
		if(l==0){
			G res{};
			for(;r>0;r-=r&-r) res+=a[r-1];
			return res;
		}
		return sum(0,r)-sum(0,l);
	}
	int lower_bound(G val)const{
		if(val<=G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<val) val-=a[x+k-1], x+=k;
		return x;
	}
	int upper_bound(G val)const{
		if(val<G{}) return 0;
		int x=0,k;
		for(k=1;k<=a.size();k<<=1);
		for(k>>=1;k>0;k>>=1) if(x+k<=a.size() && a[x+k-1]<=val) val-=a[x+k-1], x+=k;
		return x;
	}
};

class lowest_common_ancestor{
	vector<int> dep;
	vector<vector<int>> par;
	const graph& T;

	void dfs(int u,int p){
		for(int v:T[u]) if(v!=p) {
			dep[v]=dep[u]+1;
			par[0][v]=u;
			dfs(v,u);
		}
	}

public:
	lowest_common_ancestor(const graph& T,int root):T(T){
		int n=T.size(),h;
		for(h=1;(1<<h)<n;h++);

		dep.assign(n,0);
		par.assign(h,vector<int>(n,-1));

		dfs(root,-1);
		rep(i,h-1) rep(u,n) if(par[i][u]!=-1) par[i+1][u]=par[i][par[i][u]];
	}

	int lca(int u,int v)const{
		int h=par.size();

		if(dep[u]>dep[v]) swap(u,v);
		rep(i,h) if((dep[v]-dep[u])>>i&1) v=par[i][v];
		if(u==v) return u;

		for(int i=h-1;i>=0;i--) if(par[i][u]!=par[i][v]) u=par[i][u], v=par[i][v];
		return par[0][u];
	}

	int distance(int u,int v)const{ return dep[u]+dep[v]-2*dep[lca(u,v)]; }
};

class Euler_tour_for_paths{
	vector<int> L,R;
	const graph& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(int v:Tr[u]) if(v!=p) dfs(v,u);
		R[u]=idx++;
	}
public:
	Euler_tour_for_paths(const graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	pair<int,int> get_indices(int u)const{ return {L[u],R[u]}; }
	pair<int,int> get_path(int u,int v)const{ return {L[u],R[v]}; }
};

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v);
		add_undirected_edge(T,u,v);
	}

	vector<lint> val(n);
	rep(u,n) scanf("%lld",&val[u]);

	lowest_common_ancestor LCA(T,0);
	Euler_tour_for_paths ET(T,0);

	Fenwick_tree<lint> F(2*n);
	rep(u,n){
		auto [l,r]=ET.get_indices(u);
		F.add(l, val[u]);
		F.add(r,-val[u]);
	}

	lint ans=0;
	int q; scanf("%d",&q);
	rep(_,q){
		int s,t,k; scanf("%d%d%d",&s,&t,&k);

		lint res;
		int w=LCA.lca(s,t);
		if(w==s){
			auto [l,r]=ET.get_path(s,t);
			res=F.sum(l,r);
		}
		else if(w==t){
			auto [l,r]=ET.get_path(t,s);
			res=F.sum(l,r);
		}
		else{
			auto [l1,r1]=ET.get_path(w,s);
			auto [l2,r2]=ET.get_path(w,t);
			res=F.sum(l1,r1)+F.sum(l2,r2)-val[w];
		}
		ans+=k*res;
	}
	printf("%lld\n",ans);

	return 0;
}
