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
	int n,hp,ox,oy,a[200][200];
	scanf("%d%d%d%d",&n,&hp,&ox,&oy); ox--; oy--;
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);

	weighted_graph<int> G(n*n);
	rep(i,n) rep(j,n) {
		if(i<n-1){
			G[i*n+j].emplace_back((i+1)*n+j,a[i+1][j]);
			G[(i+1)*n+j].emplace_back(i*n+j,a[i][j]);
		}
		if(j<n-1){
			G[i*n+j].emplace_back(i*n+(j+1),a[i][j+1]);
			G[i*n+(j+1)].emplace_back(i*n+j,a[i][j]);
		}
	}

	auto d=Dijkstra(G,0);
	if(hp>d[n*n-1]) return puts("YES"),0;

	if(ox==-1) return puts("NO"),0;

	auto d2=Dijkstra(G,oy*n+ox);

	puts(hp>d[oy*n+ox]&&2*(hp-d[oy*n+ox])>d2[n*n-1]?"YES":"NO");

	return 0;
}
