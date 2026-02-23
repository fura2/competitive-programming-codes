#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

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

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

template<class T>
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>> Q; Q.emplace(0,s);
	while(!Q.empty()){
		T d0=-Q.top().first;
		int u=Q.top().second; Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(-d[v],v);
			}
		}
	}
	return d;
}

int main(){
	int h,w,n,sx,sy,gx,gy;
	scanf("%d%d%d%d%d%d%d",&h,&w,&n,&sx,&sy,&gx,&gy); sx--; sy--; gx--; gy--;
	vector B(h,vector(w,0));
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);
	vector<lint> cost(n+1);
	rep(i,n) scanf("%lld",&cost[i+1]);

	union_find U(h*w);
	rep(i,h) rep(j,w) {
		if(i<h-1 && B[i][j]==B[i+1][j]) U.unite(i*w+j,(i+1)*w+j);
		if(j<w-1 && B[i][j]==B[i][j+1]) U.unite(i*w+j,i*w+(j+1));
	}

	map<int,int> f;
	rep(i,h) rep(j,w) {
		int x=U.find(i*w+j);
		if(f.count(x)==0) f[x]=f.size();
	}

	weighted_graph<lint> G(U.size());
	rep(i,h) rep(j,w) {
		int u=f[U.find(i*w+j)];
		rep(k,4){
			int x=i+dx[k],y=j+dy[k];
			if(0<=x && x<h && 0<=y && y<w && B[i][j]!=B[x][y]){
				int v=f[U.find(x*w+y)];
				add_directed_edge(G,u,v,cost[B[x][y]]);
			}
		}
	}

	int s=f[U.find(sx*w+sy)];
	int g=f[U.find(gx*w+gy)];
	printf("%lld\n",Dijkstra(G,s)[g]);

	return 0;
}
