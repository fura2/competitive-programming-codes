#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using graph=vector<vector<int>>;

vector<int> distance(const graph& G,int s){
	const int INF=INT_MAX;
	int n=G.size();
	vector<int> d(n,INF);
	d[s]=0;
	queue<int> Q; Q.emplace(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		for(int v:G[u]) if(d[v]==INF) {
			d[v]=d[u]+1;
			Q.emplace(v);
		}
	}
	return d;
}

int main(){
	int h,w,n; scanf("%d%d%d",&w,&h,&n);

	static int rsum[1000][1000],csum[1000][1000];
	rep(i,n){
		int m; scanf("%d",&m);
		static int b[1001];
		rep(j,m+1) scanf("%d",&b[j]);

		rep(j,m){
			int y1=b[ j ]/w,x1=b[ j ]%w;
			int y2=b[j+1]/w,x2=b[j+1]%w;
			if(y1==y2){
				csum[y1][min(x1,x2)]++;
				csum[y1][max(x1,x2)]--;
			}
			else{
				rsum[min(y1,y2)][x1]++;
				rsum[max(y1,y2)][x1]--;
			}
		}
	}

	rep(i,h) rep(j,w-1) csum[i][j+1]+=csum[i][j];
	rep(j,w) rep(i,h-1) rsum[i+1][j]+=rsum[i][j];

	graph G(h*w);
	rep(i,h) rep(j,w) {
		if(rsum[i][j]>0){
			G[i*w+j].emplace_back((i+1)*w+j);
			G[(i+1)*w+j].emplace_back(i*w+j);
		}
		if(csum[i][j]>0){
			G[i*w+j].emplace_back(i*w+j+1);
			G[i*w+j+1].emplace_back(i*w+j);
		}
	}

	int ans=distance(G,0)[h*w-1];
	if(ans<h*w) printf("%d\n",ans);
	else puts("Odekakedekinai..");

	return 0;
}
