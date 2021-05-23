#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

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

const int INF=1<<29;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	int a[50][50];
	rep(i,h) rep(j,w) scanf("%d",&a[i][j]);

	weighted_graph<int> G(h*w);
	rep(i,h) rep(j,w) rep(k,4) {
		int y=i+dy[k],x=j+dx[k];
		if(0<=y && y<h && 0<=x && x<w){
			G[i*w+j].emplace_back(y*w+x,a[y][x]);
		}
	}

	int ans=INF;
	rep(i,h) rep(j,w) {
		auto d=Dijkstra(G,i*w+j);
		if(d[(h-1)*w]<INF && d[h*w-1]<INF && d[w-1]<INF) ans=min(ans,a[i][j]+d[(h-1)*w]+d[h*w-1]+d[w-1]);
	}
	printf("%d\n",ans);

	return 0;
}
