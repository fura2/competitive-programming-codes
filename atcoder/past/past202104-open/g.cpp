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

template<class M>
class segment_tree{
	int n,sz;
	vector<M> seg;
public:
	segment_tree(int n=0){ build(n); }
	template<class T>
	segment_tree(const vector<T>& a){ build(a); }

	void build(int n){
		this->n=n;
		for(sz=1;sz<n;sz<<=1);
		seg.assign(2*sz,M());
	}

	template<class T>
	void build(const vector<T>& a){
		build(a.size());
		rep(i,a.size()) seg[sz+i]=a[i];
		for(int i=sz-1;i>0;i--){
			seg[i]=seg[2*i]*seg[2*i+1];
		}
	}

	const M& operator[](int i)const{
		return seg[sz+i];
	}

	void update(int i,const M& x){
		i+=sz;
		seg[i]=x;
		for(i>>=1;i>0;i>>=1) seg[i]=seg[2*i]*seg[2*i+1];
	}

	M product(int l,int r)const{
		M lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*seg[a++];
			if(b&1) rcum=seg[--b]*rcum;
		}
		return lcum*rcum;
	}

	template<class N,class F>
	N operate(int l,int r,const F& f){
		N lcum,rcum;
		for(int a=l+sz,b=r+sz;a<b;a>>=1,b>>=1){
			if(a&1) lcum=lcum*f(seg[a++]);
			if(b&1) rcum=f(seg[--b])*rcum;
		}
		return lcum*rcum;
	}

	template<class F>
	int max_right(int l,const F& f)const{
		if(l==n) return n;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=cum*seg[u];
				return f(cum)?b:a;
			}

			int c=(a+b)/2;
			if(c<=l){
				return dfs(dfs,c,b,2*u+1);
			}
			if(l<=a && f(cum*seg[u])){
				cum=cum*seg[u];
				return b;
			}

			int idx=dfs(dfs,a,c,2*u);
			if(idx<c) return idx;
			return dfs(dfs,c,b,2*u+1);
		};
		return min(dfs(dfs,0,sz,1),n);
	}

	template<class F>
	int min_left(int r,const F& f)const{
		if(r==0) return 0;
		M cum;
		auto dfs=[&](auto&& dfs,int a,int b,int u){
			if(a==b-1){
				cum=seg[u]*cum;
				return f(cum)?a:b;
			}

			int c=(a+b)/2;
			if(r<=c){
				return dfs(dfs,a,c,2*u);
			}
			if(b<=r && f(seg[u]*cum)){
				cum=seg[u]*cum;
				return a;
			}

			int idx=dfs(dfs,c,b,2*u+1);
			if(idx>c) return idx;
			return dfs(dfs,a,c,2*u);
		};
		return dfs(dfs,0,sz,1);
	}
};

template<class T>
class max_monoid{
	T a;
public:
	max_monoid(const T& val=numeric_limits<T>::min()):a(val){}
	max_monoid operator*(const max_monoid& x)const{
		return max(a,x.a);
	}
	T& get(){ return a; }
	const T& get()const{ return a; }
};

int main(){
	int n,m,q; scanf("%d%d%d",&n,&m,&q);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c); u--; v--;
		add_undirected_edge(G,u,v,c);
	}

	vector<int> x(q);
	rep(i,q) scanf("%d",&x[i]);
	segment_tree<max_monoid<int>> S(x);

	int ans=0;
	vector<bool> vis(n);
	vector<vector<int>> Ev(q+1);
	Ev[0].emplace_back(0);
	rep(i,q+1){
		for(int u:Ev[i]){
			if(vis[u]) continue;
			vis[u]=true;
			ans++;

			if(i<q){
				for(auto e:G[u]){
					int v=e.to,wt=e.wt;
					int j=S.max_right(i,[&](max_monoid<int> m){ return m.get()<wt; });
					if(j<q){
						Ev[j+1].emplace_back(v);
					}
				}
			}
		}
		if(i>0) printf("%d\n",ans);
	}

	return 0;
}
