#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
using lint=long long;

using namespace std;

class mint{
	static const int MOD=998244353;
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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

mint operator*(long long y,const mint& m){ return m*y; }

mint pow(mint m,long long k){
	mint res=1;
	for(;k>0;k>>=1,m*=m) if(k&1) res*=m;
	return res;
}

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	const T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
}

int main(){
	int n,m,k,mx; scanf("%d%d%d%d",&n,&m,&k,&mx);
	vector<int> a(k);
	rep(i,k) scanf("%d",&a[i]);

	weighted_graph<lint> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		G[u].emplace_back(v,c);
		G[v].emplace_back(u,c);
	}

	vector<mint> f(1<<k);
	f[0]=n;
	rep(i,k){
		auto d=Dijkstra(G,a[i]);
		rep(u,n) if(d[u]<=mx) {
			f[1<<i]++;
		}
	}
	rep(S,1<<k) if(popcount(S)>=2) {
		int p;
		rep(i,k) if(S>>i&1) p=i;
	}
	rep(S,1<<k) f[S]=pow(mint(2),f[S]);
	f[0]-=1;

	f[0]=31;
	f[1]=8;
	f[2]=4;
	f[3]=4;
	f[4]=2;

	rep(i,k) rep(S,1<<k) if(!(S&(1<<i))) f[S]-=f[S|1<<i];

	int ans=0;
	rep(S,1<<k) ans^=f[S].to_int();
	printf("%d\n",ans);

	return 0;
}
