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
void add_directed_edge(weighted_graph<T>& G,int u,int v,const T& wt){
	G[u].emplace_back(v,wt);
}

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

int calc(string t){
	int h,m; sscanf(t.c_str(),"%d:%d",&h,&m);
	return 60*h+m;
}

int main(){
	weighted_graph<int> G(50);

	map<string,int> f;
	string sa; cin>>sa;
	f[sa]=0;
	string name[24];
	rep(i,24) cin>>name[i];

	int m; cin>>m;
	rep(i,m){
		string s1,t1,s2,t2; cin>>s1>>t1>>s2>>t2;
		int u,v;
		if(f.count(s1)==0) u=f.size(), f[s1]=u; else u=f[s1];
		if(f.count(s2)==0) v=f.size(), f[s2]=v; else v=f[s2];

		int w1=calc(t1),w2=calc(t2);
		add_directed_edge(G,u,v,w2-w1+24*60);
		add_directed_edge(G,v,u,w1-w2+24*60);
	}

	string sb,tb; cin>>sb>>tb;
	int g;
	if(f.count(sb)==0) g=f.size(), f[sb]=g; else g=f[sb];
	int tg=calc(tb);

	cout<<name[(Dijkstra(G,g)[0]+tg)%(24*60)/60]<<'\n';

	return 0;
}
