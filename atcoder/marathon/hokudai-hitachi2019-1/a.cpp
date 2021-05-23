#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	weighted_graph<int> G(n);
	rep(i,m){
		int u,v,d; scanf("%d%d%d",&u,&v,&d); u--; v--;
		G[u].emplace_back(v,d);
		G[v].emplace_back(u,d);
	}
	int Tmax; scanf("%d",&Tmax);

	// Warshall-Floyd
	vector<vector<int>> d(n,vector<int>(n,INF));
	rep(u,n) d[u][u]=0;
	rep(u,n) for(auto e:G[u]) {
		int v=e.to;
		d[u][v]=min(d[u][v],e.wt);
	}
	rep(w,n) rep(u,n) rep(v,n) d[u][v]=min(d[u][v],d[u][w]+d[w][v]);

	list<pair<int,int>> Wait,Now;
	int phase=0;
	int cur=0,next,edge_pos,goal;
	bool on_edge=false;
	rep(t,Tmax){
		int n_new; scanf("%d",&n_new);
		if(n_new>0){
			int id,dst; scanf("%d%d",&id,&dst); id--; dst--;
			Wait.emplace_back(id,dst);
		}

		int res=-1;

		if(phase%2==0 && cur==0){ // at the shop
			Now.insert(Now.end(),Wait.begin(),Wait.end());
			Wait.clear();
			if(!Now.empty()){
				goal=Now.front().second;
				phase++;
			}
		}
		else if(phase%2==0){ // at customer
			for(auto it=Now.begin();it!=Now.end();++it) if(it->second==goal) {
					it=Now.erase(it);
					--it;
			}
			goal=0;
			for(auto p:Now){
				if(goal==0 || d[cur][p.second]<d[cur][goal]) goal=p.second;
			}
			phase++;
		}

		if(phase%2==1){ // moving
			if(!on_edge){
				next=-1;
				for(auto e:G[cur]){
					if(next==-1 || d[cur][goal]==e.wt+d[e.to][goal]) next=e.to;
				}
				edge_pos=1;
				on_edge=true;
			}
			else{ // on_edge
				edge_pos++;
			}
			res=next;

			if(on_edge && edge_pos==d[cur][next]){
				on_edge=false;
				if(next==goal){
					phase++;
				}
				cur=next;
			}
		}

		printf("%d\n",res==-1?-1:res+1);
	}

	return 0;
}
