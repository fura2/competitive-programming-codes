#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

using graph=vector<vector<int>>;

void add_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

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
	int n; scanf("%d",&n);
	graph T(n);
	for(int u=1;u<n;u++){
		int p; scanf("%d",&p);
		add_edge(T,p,u);
	}

	Euler_tour_for_vertex ET(T,0);
	Fenwick_tree_dual<int> F(n);

	lint ans=0;
	rep(u,n){
		int l,r;
		tie(l,r)=ET.get_subtree(u);
		ans+=F.sum(l);
		F.add(l,r,1);
	}
	printf("%lld\n",ans);

	return 0;
}
