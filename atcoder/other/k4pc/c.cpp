#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

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

template<class T>
class Euler_tour_for_vertex{
	vector<int> L,R;
	const weighted_graph<T>& Tr;
	int idx;
	void dfs(int u,int p){
		L[u]=idx++;
		for(const auto& e:Tr[u]){
			int v=e.to;
			if(v!=p) dfs(v,u);
		}
		R[u]=idx;
	}
public:
	Euler_tour_for_vertex(const weighted_graph<T>& Tr,int root):L(Tr.size()),R(Tr.size()),Tr(Tr),idx(0){
		dfs(root,-1);
	}
	int get_index(int u)const{ return L[u]; }
	pair<int,int> get_subtree(int u)const{ return {L[u],R[u]}; }
};

vector<int> cost;

void dfs(int u,int p,const weighted_graph<int>& T){
	for(const auto& e:T[u]){
		int v=e.to;
		if(v==p) continue;
		cost[v]=cost[u]+e.wt;
		dfs(v,u,T);
	}
}

int main(){
	int n,q; scanf("%d%d",&n,&q);
	weighted_graph<int> T(n);
	for(int u=1;u<n;u++){
		int v,wt; scanf("%d%d",&v,&wt); v--;
		T[u].emplace_back(v,wt);
		T[v].emplace_back(u,wt);
	}

	cost.resize(n);
	dfs(0,-1,T);

	Euler_tour_for_vertex<int> ET(T,0);

	priority_queue<pair<int,int>> Q;
	rep(u,n) if(u!=0 && T[u].size()==1) Q.emplace(-cost[u],u);
	Fenwick_tree_dual<int> F(n);

	rep(_,q){
		int u; scanf("%d",&u); u--;
		int l,r; tie(l,r)=ET.get_subtree(u);
		F.add(l,r,1);
		while(!Q.empty()){
			int v=Q.top().second;
			if(F.sum(ET.get_index(v))==0) break;
			Q.pop();
		}
		printf("%d\n",Q.empty()?-1:-Q.top().first);
	}

	return 0;
}
