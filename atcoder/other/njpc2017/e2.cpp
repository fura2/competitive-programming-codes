// 抽象化 rerooting の verify

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

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class M,class W,class F,class G>
vector<M> rerooting(const weighted_graph<W>& T,const F& f,const G& g){
	int n=T.size();
	vector<M> dp1(n),dp2(n);

	auto dfs1=[&](auto&& dfs1,int u,int p)->void{
		for(const auto& e:T[u]) if(e.to!=p) {
			dfs1(dfs1,e.to,u);
			dp1[u]=dp1[u]*f(dp1[e.to],e);
		}
		dp1[u]=g(dp1[u],u);
	};

	auto dfs2=[&](auto&& dfs2,int u,int p,const M& dp_par)->void{
		int k=T[u].size();

		vector<M> lcum(k+1),rcum(k+1);
		rep(i,k){
			const auto& e=T[u][i];
			lcum[i+1]=rcum[i]=f(e.to==p?dp_par:dp1[e.to],e);
		}
		rep(i,k){
			lcum[i+1]=lcum[i+1]*lcum[i];
			rcum[k-i-1]=rcum[k-i-1]*rcum[k-i];
		}

		dp2[u]=g(lcum[k],u);
		rep(i,k){
			const auto& e=T[u][i];
			if(e.to!=p){
				dfs2(dfs2,e.to,u,g(lcum[i]*rcum[i+1],u));
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

template<class T>
class max_monoid{
	T a;
public:
	max_monoid():a(numeric_limits<T>::min()){}
	max_monoid(const T& val):a(val){}
	max_monoid operator*(const max_monoid& x)const{
		return max(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

const int INF=1<<29;

int main(){
	int n,d_max; scanf("%d%d",&n,&d_max);
	weighted_graph<int> T1(n),T2(n);
	rep(i,n-1){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_directed_edge(T1,u,v,1);
		add_directed_edge(T1,v,u,0);
		add_undirected_edge(T2,u,v,c);
	}

	using M1=add_monoid<int>;
	auto f1=[](M1 m,edge<int> e)->M1{
		return m.get()+e.wt;
	};
	auto g1=[](M1 m,int u)->M1{
		return m;
	};
	auto res1=rerooting<M1>(T1,f1,g1);

	using M2=max_monoid<int>;
	auto f2=[](M2 m,edge<int> e)->M2{
		return m.get()+e.wt;
	};
	auto g2=[](M2 m,int u)->M2{
		return max(m.get(),0);
	};
	auto res2=rerooting<M2>(T2,f2,g2);

	int ans=INF;
	rep(u,n) if(res2[u].get()<=d_max) {
		ans=min(ans,res1[u].get());
	}
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
