#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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

	friend mint inverse(const mint& m){
		int a=m.x,b=MOD,u=1,v=0;
		while(b>0){ int t=a/b; a-=t*b; swap(a,b); u-=t*v; swap(u,v); }
		return u;
	}

	friend istream& operator>>(istream& is,mint& m){ long long t; is>>t; m=mint(t); return is; }
	friend ostream& operator<<(ostream& os,const mint& m){ return os<<m.x; }
	int to_int()const{ return x; }
};

using graph=vector<vector<int>>;

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

vector<int> topological_order(const graph& D){
	int n=D.size();
	vector<int> deg(n);
	rep(u,n) for(int v:D[u]) deg[v]++;

	vector<int> res;
	queue<int> Q;
	rep(u,n) if(deg[u]==0) Q.emplace(u);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		res.emplace_back(u);
		for(int v:D[u]) if(--deg[v]==0) Q.emplace(v);
	}
	return res;
}

mint calc(const graph& D){
	int n=D.size();
	vector<mint> dp(n);
	dp[0]=1;
	for(int u:topological_order(D)) for(int v:D[u]) dp[v]+=dp[u];
	return dp[n-1];
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m),b(m);
	vector<lint> cost1(m),cost2(m);
	weighted_graph<lint> G1(n),G2(n);
	rep(i,m){
		scanf("%d%d%lld%lld",&a[i],&b[i],&cost1[i],&cost2[i]); a[i]--; b[i]--;
		G1[a[i]].emplace_back(b[i],cost1[i]);
		G1[b[i]].emplace_back(a[i],cost1[i]);
		G2[a[i]].emplace_back(b[i],cost2[i]);
		G2[b[i]].emplace_back(a[i],cost2[i]);
	}

	auto d1=Dijkstra(G1,0);
	auto d2=Dijkstra(G2,0);

	graph D1(n),D2(n),D3(n);
	rep(i,m){
		rep(_,2){
			bool f1=(d1[a[i]]+cost1[i]==d1[b[i]]);
			bool f2=(d2[a[i]]+cost2[i]==d2[b[i]]);
			if(f1)       D1[a[i]].emplace_back(b[i]);
			if(f2)       D2[a[i]].emplace_back(b[i]);
			if(f1 && f2) D3[a[i]].emplace_back(b[i]);
			swap(a[i],b[i]);
		}
	}

	cout<<calc(D1)+calc(D2)-calc(D3)<<'\n';

	return 0;
}
