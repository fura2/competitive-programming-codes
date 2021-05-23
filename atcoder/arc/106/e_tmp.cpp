#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T>
class network{
	struct edge{
		int to,rev;
		T capa,flow;
		edge(int to,int rev,const T& capa,const T& flow):to(to),rev(rev),capa(capa),flow(flow){}
	};

	int s,t;
	vector<vector<edge>> G;

	vector<int> layer,now;

	bool make_layer(){
		int n=G.size();
		rep(u,n) layer[u]=(u==s?0:-1);

		queue<int> Q; Q.emplace(s);
		while(!Q.empty()){
			int u=Q.front(); Q.pop();
			for(const edge& e:G[u]) if(layer[e.to]==-1 && e.capa-e.flow>0) {
				layer[e.to]=layer[u]+1;
				if(e.to==t) return true;
				Q.emplace(e.to);
			}
		}
		return false;
	}

	T augment(int u,const T& water){
		if(u==t) return water;

		for(int& i=now[u];i<G[u].size();i++){
			edge& e=G[u][i];
			if(layer[e.to]>layer[u] && e.capa-e.flow>0){
				T w=augment(e.to,min(water,e.capa-e.flow));
				if(w>0){
					e.flow+=w;
					G[e.to][e.rev].flow-=w;
					return w;
				}
			}
		}
		return 0;
	}

public:
	network(int n,int s,int t):s(s),t(t),G(n){}

	void add_directed_edge(int u,int v,const T& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,   0,0);
	}

	void add_undirected_edge(int u,int v,const T& capa){
		G[u].emplace_back(v,G[v].size()  ,capa,0);
		G[v].emplace_back(u,G[u].size()-1,capa,0);
	}

	T maximum_flow(){
		int n=G.size();
		layer.resize(n);

		T res=0;
		while(make_layer()){
			now.assign(n,0);
			for(T water=1;water>0;res+=water) water=augment(s,numeric_limits<T>::max());
		}
		return res;
	}

	void add_capacity(int u,int v,int c){
		for(auto& e:G[u]) if(e.to==v) {
			e.capa+=c;
			G[v][e.rev].capa-=c;
			break;
		}
	}
};

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int N=n+(1<<n)+2;
	int s=N-2,t=N-1;
	network<int> G0(N,s,t);
	rep(i,n) G0.add_directed_edge(i,t,k);
	rep(i,n) rep(S,1<<n) if(S>>i&1) G0.add_directed_edge(n+S,i,k);

	auto G=G0;
	int flow;
	bool pre=false;

	int lo=n*k-1,hi=4*n*k;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		if(pre){
			int cnt[1<<18]={};
			for(int x=lo;x<mi;x++){
				int S=0;
				rep(i,n) if(x%(2*a[i])<a[i]) S|=1<<i;
				cnt[S]++;
			}
			rep(S,1<<n) if(cnt[S]>0) G.add_capacity(s,n+S,cnt[S]);
			flow+=G.maximum_flow();
		}
		else{
			G=G0;
			int cnt[1<<18]={};
			rep(x,mi){
				int S=0;
				rep(i,n) if(x%(2*a[i])<a[i]) S|=1<<i;
				cnt[S]++;
			}
			rep(S,1<<n) if(cnt[S]>0) G.add_directed_edge(s,n+S,cnt[S]);
			flow=G.maximum_flow();
		}

		if(flow==n*k){
			hi=mi;
			pre=false;
		}
		else{
			lo=mi;
			pre=true;
		}
	}
	printf("%d\n",hi);

	return 0;
}
