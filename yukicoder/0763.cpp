#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt;
	edge(int to,const T& wt):to(to),wt(wt){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

weighted_graph<int> T;

int memo[200000][2];

int dfs(int u,int p,int id,bool b){ // id: 辺 p-u の番号, b: 頂点 u を残すかどうか
	if(~memo[id][b]) return memo[id][b];

	int res;
	if(b){
		res=1;
		for(auto e:T[u]) if(e.to!=p) {
			res+=dfs(e.to,u,e.wt,false);
		}
	}
	else{
		res=0;
		for(auto e:T[u]) if(e.to!=p) {
			res+=max(dfs(e.to,u,e.wt,true),dfs(e.to,u,e.wt,false));
		}
	}
	return memo[id][b]=res;
}

int main(){
	int n; scanf("%d",&n);
	T.resize(n);
	rep(i,n-1){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		T[u].emplace_back(v,i);
		T[v].emplace_back(u,i+n);
	}

	int ans=0;
	memset(memo,-1,sizeof memo);
	rep(u,n){
		int tmp=0;
		for(auto e:T[u]) tmp+=dfs(e.to,u,e.wt,true);
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);

	return 0;
}
