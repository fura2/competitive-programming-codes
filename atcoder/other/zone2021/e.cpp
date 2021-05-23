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

template<class T>
vector<T> Dijkstra(const weighted_graph<T>& G,int s){
	constexpr T INF=numeric_limits<T>::max();
	int n=G.size();
	vector<T> d(n,INF); d[s]=0;
	priority_queue<pair<T,int>,vector<pair<T,int>>,greater<>> Q;
	Q.emplace(0,s);
	while(!Q.empty()){
		T d0;
		int u; tie(d0,u)=Q.top();
		Q.pop();
		if(d0>d[u]) continue;
		for(const auto& e:G[u]){
			int v=e.to;
			if(d[v]>d[u]+e.wt){
				d[v]=d[u]+e.wt;
				Q.emplace(d[v],v);
			}
		}
	}
	return d;
}

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector a(h,vector(w-1,0));
	vector b(h-1,vector(w,0));
	rep(i,h) rep(j,w-1) scanf("%d",&a[i][j]);
	rep(i,h-1) rep(j,w) scanf("%d",&b[i][j]);

	weighted_graph<int> G(h*w);
	rep(i,h) rep(j,w) {
		if(j> 0 ) add_directed_edge(G,i*w+j,i*w+j-1,a[i][j-1]);
		if(j<w-1) add_directed_edge(G,i*w+j,i*w+j+1,a[i][j]);
		if(i<h-1) add_directed_edge(G,i*w+j,(i+1)*w+j,b[i][j]);
		for(int k=1;k<=i;k++){
			add_directed_edge(G,i*w+j,(i-k)*w+j,1+k);
		}
	}
	printf("%d\n",Dijkstra(G,0)[h*w-1]);

	return 0;
}
