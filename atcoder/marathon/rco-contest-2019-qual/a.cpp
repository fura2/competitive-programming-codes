#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,x[200],y[200];
double dist[200][200],d[200][200];

vector<int> greedy(){
	vector<bool> vis(n);
	vis[0]=true;

	vector<int> path(n);
	rep(t,n-1){
		int u=path[t],to=-1;
		rep(v,n) if(!vis[v] && (to==-1 || d[u][v]<d[u][to])) to=v;
		vis[to]=true;
		path[t+1]=to;
	}
	return path;
}

bool two_opt(vector<int>& path){
	double best=0;
	int t1_best,t2_best;
	rep(t1,n) for(int t2=t1+2;t2<n;t2++) {
		if(t1==0 && t2==n-1) continue;

		int u=path[t1],v=path[t1+1];
		int w=path[t2],x=path[(t2+1)%n];
		double diff=(d[u][v]+d[w][x])-(d[u][w]+d[v][x]);
		if(best<diff){
			best=diff;
			t1_best=t1;
			t2_best=t2;
		}
	}
	if(best<=1e-8) return false;

	reverse(path.begin()+t1_best+1,path.begin()+t2_best+1);
	return true;
}

double variance(const vector<int>& path){
	double mean=0;
	rep(t,n) mean+=dist[path[t]][path[(t+1)%n]];
	mean/=n;

	double var=0;
	rep(t,n) var+=(dist[path[t]][path[(t+1)%n]]-mean)*(dist[path[t]][path[(t+1)%n]]-mean);
	var/=n;
	return var;
}

int main(){
	scanf("%d",&n);
	rep(u,n) scanf("%d%d",&x[u],&y[u]);

	rep(u,n) rep(v,n) dist[u][v]=hypot(x[u]-x[v],y[u]-y[v]);

	vector<int> ans;
	for(double mean=260;mean<400;mean++){
		rep(u,n) rep(v,n) d[u][v]=(dist[u][v]-mean)*(dist[u][v]-mean);

		vector<int> path=greedy();
		while(two_opt(path));

		if(ans.empty() || variance(ans)>variance(path)) ans=path;
	}

	rep(t,n) printf("%d\n",ans[t]);

	return 0;
}
