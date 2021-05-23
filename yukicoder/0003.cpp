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

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int n; cin>>n;
	weighted_graph<int> G(n);
	rep(u,n){
		int p=popcount(u+1);
		if(u-p>=0) G[u].emplace_back(u-p,1);
		if(u+p< n) G[u].emplace_back(u+p,1);
	}

	int ans=Dijkstra(G,0)[n-1];
	cout<<(ans<INT_MAX?ans+1:-1)<<'\n';

	return 0;
}
