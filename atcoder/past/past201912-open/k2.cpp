// solution by Euler tour

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

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

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	int root;
	rep(u,n){
		int p; scanf("%d",&p);
		if(p==-1) root=u;
		else{
			p--;
			T[u].emplace_back(p);
			T[p].emplace_back(u);
		}
	}

	Euler_tour_for_vertex E(T,root);

	int q; scanf("%d",&q);
	rep(_,q){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		auto I=E.get_subtree(b);
		puts(I.first<=E.get_index(a)&&E.get_index(a)<I.second?"Yes":"No");
	}

	return 0;
}
