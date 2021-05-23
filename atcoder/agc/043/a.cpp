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
	int h,w; scanf("%d%d",&h,&w);
	char B[100][101];
	rep(i,h) scanf("%s",B[i]);

	weighted_graph<int> G(h*w+2);
	int s=h*w,t=h*w+1;
	rep(i,h) rep(j,w) {
		if(i<h-1) G[i*w+j].emplace_back((i+1)*w+j,B[i][j]==B[i+1][j]?0:1);
		if(j<w-1) G[i*w+j].emplace_back(i*w+(j+1),B[i][j]==B[i][j+1]?0:1);
	}
	G[s].emplace_back(0,B[0][0]=='.'?0:1);
	G[h*w-1].emplace_back(t,B[h-1][w-1]=='.'?0:1);

	printf("%d\n",(Dijkstra(G,s)[t]+1)/2);

	return 0;
}
