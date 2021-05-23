#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			// 常に u 側を親にする
			// if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
	void make_set(){
		n++;
		p.emplace_back(-1);
	}
};

class Euler_tour_for_vertex{
	vector<int> L,R;
	const graph& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(int v:Tr[u]) if(v!=p) dfs(v,u);
		R[u]=idx;
	}
public:
	Euler_tour_for_vertex(const graph& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	int get_index(int u)const{ return L[u]; }
	pair<int,int> get_subtree(int u)const{ return {L[u],R[u]}; }
};

template<class G>
class Fenwick_tree_dual{
	vector<G> a;
public:
	Fenwick_tree_dual(int n):a(n){}
	void add(int l,int r,G val){
		if(l==0){
			for(;r>0;r-=r&-r) a[r-1]+=val;
			return;
		}
		add(0,r,val);
		add(0,l,-val);
	}
	G sum(int i)const{
		G res{};
		for(i++;i<=a.size();i+=i&-i) res+=a[i-1];
		return res;
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);

	int m=n;
	union_find U(n);
	graph T(n);
	vector<tuple<int,int,int>> Q;
	rep(i,q){
		int type,a,b; scanf("%d%d%d",&type,&a,&b);
		if(type==1){
			a--; b--;
			a=U.find(a);
			b=U.find(b);
			if(a!=b){
				U.make_set();
				U.unite(m,a);
				U.unite(m,b);
				T.emplace_back();
				add_edge(T,m,a);
				add_edge(T,m,b);
				m++;
			}
		}
		else if(type==2){
			a--;
			a=U.find(a);
			Q.emplace_back(type,a,b);
		}
		else{
			a--;
			Q.emplace_back(type,a,b);
		}
	}

	// T を連結にする
	if(U.size()>1){
		U.make_set();
		T.emplace_back();
		rep(u,n) if(!U.is_same(u,m)) {
			int a=U.find(u);
			U.unite(m,a);
			add_edge(T,m,a);
		}
		m++;
	}

	Euler_tour_for_vertex ET(T,m-1);
	Fenwick_tree_dual<int> FT(m);
	rep(i,Q.size()){
		int type,a,b; tie(type,a,b)=Q[i];
		if(type==2){
			int l,r; tie(l,r)=ET.get_subtree(a);
			FT.add(l,r,b);
		}
		else{
			printf("%d\n",FT.sum(ET.get_index(a)));
		}
	}

	return 0;
}
