#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct edge{
	int to;
	T wt1,wt2;
	edge(int to,const T& wt1,const T& wt2):to(to),wt1(wt1),wt2(wt2){}
};
template<class T> using weighted_graph=vector<vector<edge<T>>>;

const int INF=1<<29;

int main(){
	int n,c,m; scanf("%d%d%d",&n,&c,&m);
	weighted_graph<int> G(n);
	{
		vector<int> a(m),b(m),wt1(m),wt2(m);
		rep(i,m) scanf("%d",&a[i]), a[i]--;
		rep(i,m) scanf("%d",&b[i]), b[i]--;
		rep(i,m) scanf("%d",&wt1[i]);
		rep(i,m) scanf("%d",&wt2[i]);
		rep(i,m) G[a[i]].emplace_back(b[i],wt1[i],wt2[i]);
	}

	vector<vector<int>> d(n,vector<int>(c+1,INF));
	d[0][c]=0;
	priority_queue<tuple<int,int,int>> Q; Q.emplace(0,0,c);
	while(!Q.empty()){
		int d0,u,c0; tie(d0,u,c0)=Q.top(); d0*=-1;
		Q.pop();
		if(d0>d[u][c0]) continue;

		if(u==n-1) return printf("%d\n",d0),0;

		for(const auto& e:G[u]){
			int v=e.to,c1=c0-e.wt1;
			if(c1>=0 && d[v][c1]>d[u][c0]+e.wt2) d[v][c1]=d[u][c0]+e.wt2, Q.emplace(-d[v][c1],v,c1);
		}
	}

	puts("-1");

	return 0;
}
