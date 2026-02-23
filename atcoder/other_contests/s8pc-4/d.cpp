#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using graph=vector<vector<int>>;

void add_undirected_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void add_directed_edge(graph& G,int u,int v){
	G[u].emplace_back(v);
}

template<class M,class F,class G>
vector<M> rerooting(const graph& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(int v:T[u]) if(v!=p) {
			dfs1(dfs1,v,u);
			dp1[u]=dp1[u]*f(dp1[v],v);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			int v=T[u][i];
			lcum[i+1]=rcum[i]=(v==p?f(dp_par,p):f(dp1[v],v));
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			int v=T[u][i];
			if(v!=p){
				dfs2(dfs2,v,u,g(lcum[i]*rcum[i+1],u));
			}
		}
	};

	dfs1(dfs1,0,-1);
	dfs2(dfs2,0,-1,M());

	return dp2;
}

template<class T>
class add_monoid{
	T a;
public:
	add_monoid():a(){}
	add_monoid(const T& val):a(val){}
	add_monoid operator*(const add_monoid& x)const{
		return a+x.a;
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

class monoid{
public:
	add_monoid<double> x;
	int deg;
	monoid():x(),deg(0){}
	monoid(const add_monoid<double>& x,int deg):x(x),deg(deg){}
	monoid operator*(const monoid& m)const{
		return {x*m.x,deg+m.deg};
	}
};

int main(){
	int n; scanf("%d",&n);
	graph T(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		add_undirected_edge(T,u,v);
	}

	auto f=[&](monoid m,int u)->monoid{
		return {m.x,1};
	};
	auto g=[&](monoid m,int u)->monoid{
		if(m.deg==0){
			return {0,m.deg};
		}
		else{
			return {1+m.x.get()/m.deg,m.deg};
		}
	};
	for(auto res:rerooting<monoid>(T,f,g)){
		printf("%.9f\n",res.x);
	}

	return 0;
}
