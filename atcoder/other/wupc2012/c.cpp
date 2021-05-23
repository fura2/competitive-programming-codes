#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

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
			if(d[v]>d[u]+e.wt) d[v]=d[u]+e.wt, Q.emplace(-d[v],v);
		}
	}
	return d;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	weighted_graph<int> G(h*w);
	rep(i,h) rep(j,w) if(B[i][j]!='#') {
		if(i+1<h && B[i+1][j]!='#') add_undirected_edge(G,i*w+j,(i+1)*w+j,1);
		if(j+1<w && B[i][j+1]!='#') add_undirected_edge(G,i*w+j,i*w+(j+1),1);
	}

	int sx,sy,gx,gy,cx,cy;
	rep(i,h) rep(j,w) {
		if(B[i][j]=='S') sx=j, sy=i;
		if(B[i][j]=='G') gx=j, gy=i;
		if(B[i][j]=='C') cx=j, cy=i;
	}

	auto d=Dijkstra(G,cy*w+cx);
	printf("%d\n",d[sy*w+sx]<INF&&d[gy*w+gx]<INF?d[sy*w+sx]+d[gy*w+gx]:-1);

	return 0;
}
