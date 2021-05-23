#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	int h,w,n; scanf("%d%d%d",&w,&h,&n);
	vector<int> x(n+2),y(n+2);
	rep(i,n) scanf("%d%d",&x[i],&y[i]), x[i]--, y[i]--;
	x[n]=0; x[n+1]=w-1;
	y[n]=0; y[n+1]=h-1;
	n+=2;

	vector<pair<int,pair<int,int>>> XtoY(n),YtoX(n);
	rep(i,n){
		XtoY[i]={x[i],{y[i],i}};
		YtoX[i]={y[i],{x[i],i}};
	}
	sort(XtoY.begin(),XtoY.end());
	sort(YtoX.begin(),YtoX.end());

	weighted_graph<lint> G(2*n);
	rep(i,n) if(i<n-2) {
		G[i].emplace_back(n+i,1);
		G[n+i].emplace_back(i,1);
	}
	rep(i,n){
		int idx=upper_bound(XtoY.begin(),XtoY.end(),make_pair(x[i],make_pair(y[i],i)))-XtoY.begin();
		if(idx<n && XtoY[idx].first==x[i]){
			int yy,v;
			tie(yy,v)=XtoY[idx].second;
			G[i].emplace_back(v,abs(yy-y[i]));
			G[v].emplace_back(i,abs(yy-y[i]));
		}

		idx=upper_bound(YtoX.begin(),YtoX.end(),make_pair(y[i],make_pair(x[i],i)))-YtoX.begin();
		if(idx<n && YtoX[idx].first==y[i]){
			int xx,v;
			tie(xx,v)=YtoX[idx].second;
			G[n+i].emplace_back(n+v,abs(xx-x[i]));
			G[n+v].emplace_back(n+i,abs(xx-x[i]));
		}
	}

	auto d=Dijkstra(G,n-2);
	lint ans=min(d[n-1],d[2*n-1]);
	printf("%lld\n",ans<LLONG_MAX?ans:-1);

	return 0;
}
