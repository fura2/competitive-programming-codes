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

random_device seed_gen;
mt19937 rng(seed_gen());

int n,m;
weighted_graph<int> G;

int calc_score(const vector<int>& p){
	int res=0;
	vector<bool> vis(n);
	rep(i,n){
		int u=p[n-1-i];
		vis[u]=true;
		for(auto e:G[u]) if(vis[e.to]) res+=e.wt;
	}
	return res;
}

int main(){
	auto start=std::chrono::system_clock::now();

	scanf("%d%d",&n,&m);
	G.resize(n);
	rep(i,m){
		int u,v,c; scanf("%d%d%d",&u,&v,&c);
		add_directed_edge(G,u,v,c);
	}

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	int ans=calc_score(p);
	auto p_ans=p;
	for(int t=0;;t++){
		auto now=std::chrono::system_clock::now();
		if(std::chrono::duration_cast<std::chrono::milliseconds>(now-start).count()>4990) break;

		shuffle(p.begin(),p.end(),rng);
		while(1){
			bool updated=false;
			rep(i,n) for(int j=i+1;j<n;j++) {
				swap(p[i],p[j]);
				int tmp=calc_score(p);
				if(tmp>ans){
					ans=tmp;
					p_ans=p;
					updated=true;
				}
				else{
					swap(p[i],p[j]);
				}
			}
			if(!updated) break;
		}
	}

	printf("%d\n",ans);
	rep(i,n) printf("%d%c",p_ans[i],i<n-1?' ':'\n');

	return 0;
}
