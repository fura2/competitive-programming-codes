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

class mint{
	static const int MOD=1e9+7;
	int x;
public:
	mint():x(0){}
	mint(long long y){ x=y%MOD; if(x<0) x+=MOD; }

	mint& operator+=(const mint& m){ x+=m.x; if(x>=MOD) x-=MOD; return *this; }
	mint& operator-=(const mint& m){ x-=m.x; if(x<   0) x+=MOD; return *this; }
	mint& operator*=(const mint& m){ x=1LL*x*m.x%MOD; return *this; }
	mint& operator/=(const mint& m){ return *this*=inverse(m); }
	mint operator+(const mint& m)const{ return mint(*this)+=m; }
	mint operator-(const mint& m)const{ return mint(*this)-=m; }
	mint operator*(const mint& m)const{ return mint(*this)*=m; }
	mint operator/(const mint& m)const{ return mint(*this)/=m; }
	mint operator-()const{ return mint(-x); }

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator+(long long x,const mint& m){ return mint(x)+m; }
mint operator-(long long x,const mint& m){ return mint(x)-m; }
mint operator*(long long x,const mint& m){ return mint(x)*m; }
mint operator/(long long x,const mint& m){ return mint(x)/m; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

weighted_graph<mint> T;
int sz[200000];
mint memo1[200000]; // memo1[u] = (u を根とする部分木について u からの距離の総和)
mint memo2[200000]; // memo2[u] = (u を根とする部分木について u を通るパスの距離の総和)

void dfs(int u,int p){
	sz[u]=1;

	for(auto e:T[u]){
		int v=e.to;
		if(v!=p){
			dfs(v,u);
			sz[u]+=sz[v];
			memo1[u]+=memo1[v]+sz[v]*e.wt;
		}
	}

	for(auto e:T[u]){
		int v=e.to;
		if(v!=p){
			memo2[u]+=(sz[u]-sz[v])*(memo1[v]+sz[v]*e.wt);
		}
	}
}

int main(){
	int n,m,base; scanf("%d%d%d",&n,&m,&base);
	T.resize(n);
	union_find U(n);
	rep(i,m){
		int u,v,z; scanf("%d%d%d",&u,&v,&z); u--; v--;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			add_undirected_edge(T,u,v,pow(mint(base),z));
		}
	}

	dfs(0,-1);

	cout<<accumulate(memo2,memo2+n,mint(0))<<'\n';

	return 0;
}
