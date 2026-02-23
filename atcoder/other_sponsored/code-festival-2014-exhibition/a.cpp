#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int n,m; scanf("%d%d",&n,&m);
	pair<int,int> E[2000];
	bool A[2000][2000]={};
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		E[i]={u,v};
		A[u][v]=A[v][u]=true;
	}

	vector<int> tar(n);
	rep(u,n) scanf("%d",&tar[u]), tar[u]--;

	union_find U(n);
	rep(i,m){
		int u,v; tie(u,v)=E[i];
		rep(w,n) if(A[u][w] && A[v][w]) {
			U.unite(u,v);
			U.unite(u,w);
		}
	}

	vector<vector<int>> Comp(n);
	rep(u,n) Comp[U.find(u)].emplace_back(u);

	for(const auto& C:Comp) if(!C.empty()) {
		int k=C.size();
		vector<int> seq(k);
		rep(i,k) seq[i]=tar[C[i]];

		{
			auto tmp=seq;
			sort(tmp.begin(),tmp.end());
			if(tmp!=C) return puts("NO"),0;
		}

		if(k==1) continue;

		rep(i,k-2) if(seq[i]!=C[i]) {
			int j;
			for(j=i+1;j<k;j++) if(seq[j]==C[i]) break;
			int idx=(j==k-1?k-2:k-1);

			int tmp=seq[i];
			seq[i]=seq[j];
			seq[j]=seq[idx];
			seq[idx]=tmp;
		}
		if(seq[k-1]!=C[k-1]) return puts("NO"),0;
	}
	puts("YES");

	return 0;
}
