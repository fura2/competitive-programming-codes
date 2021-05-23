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

template<class T>
pair<T,weighted_graph<T>> Kruskal(const weighted_graph<T>& G){
	int n=G.size();
	vector<tuple<T,int,int>> E;
	rep(u,n) for(const auto& e:G[u]) {
		int v=e.to;
		if(u<v) E.emplace_back(e.wt,u,v);
	}

	sort(E.begin(),E.end());

	T ans{};
	weighted_graph<T> Res(n);
	union_find U(n);
	for(const auto& e:E){
		if(U.size()==1) break;
		T wt;
		int u,v; tie(wt,u,v)=e;
		if(!U.is_same(u,v)){
			U.unite(u,v);
			ans+=wt;
			Res[u].emplace_back(v,wt);
			Res[v].emplace_back(u,wt);
		}
	}
	return {ans,Res};
}

const double INF=1e77;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> px(n),py(n),cx(m),cy(m),r(m);
	rep(i,n) scanf("%d%d",&px[i],&py[i]);
	rep(i,m) scanf("%d%d%d",&cx[i],&cy[i],&r[i]);

	double ans=INF;
	rep(S,1<<m){
		weighted_graph<double> G(n+m);
		rep(i,n){
			rep(j,n) if(i<j) {
				add_undirected_edge(G,i,j,hypot(px[i]-px[j],py[i]-py[j]));
			}
			rep(j,m) if(S>>j&1) {
				double cost=abs(hypot(px[i]-cx[j],py[i]-cy[j])-r[j]);
				add_undirected_edge(G,i,j+n,cost);
			}
		}
		rep(i,m) if(S>>i&1) {
			rep(j,m) if(S>>j&1 && i<j) {
				double cost;
				if((cx[i]-cx[j])*(cx[i]-cx[j])+(cy[i]-cy[j])*(cy[i]-cy[j])>=(r[i]+r[j])*(r[i]+r[j])){
					cost=hypot(cx[i]-cx[j],cy[i]-cy[j])-(r[i]+r[j]);
				}
				else if((cx[i]-cx[j])*(cx[i]-cx[j])+(cy[i]-cy[j])*(cy[i]-cy[j])<=(r[i]-r[j])*(r[i]-r[j])){
					cost=abs(r[i]-r[j])-hypot(cx[i]-cx[j],cy[i]-cy[j]);
				}
				else{
					cost=0;
				}
				add_undirected_edge(G,i+n,j+n,cost);
			}
		}
		ans=min(ans,Kruskal(G).first);
	}
	printf("%.9f\n",ans);

	return 0;
}
