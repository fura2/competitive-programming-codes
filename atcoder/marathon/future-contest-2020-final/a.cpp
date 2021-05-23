// this solution is based on
// https://atcoder.jp/contests/future-contest-2020-final-open/submissions/8823139

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	vector<int> x(n),y(n),c(n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&c[i]);

	vector<vector<int>> par(m,vector<int>(k));
	rep(i,m) for(int a=1;a<k;a++) scanf("%d",&par[i][a]), par[i][a]--;

	vector<vector<int>> ans(m,vector<int>(k));
	vector<vector<bool>> adj(n,vector<bool>(n));
	vector<pair<int,int>> E;
	vector<bool> ng(m),used(n);
	used[0]=true;

	rep(i,m){
		ans[i][0]=0;

		vector<bool> used_here(n);
		used_here[0]=true;

		for(int a=1;a<k;a++){
			bool ok=false;
			rep(u,n) if(!used_here[u]) {
				int p=ans[i][par[i][a]];
				if(!used[u]){
					if((x[u]-x[p])*(x[u]-x[p])+(y[u]-y[p])*(y[u]-y[p])<=(c[u]+c[p])*(c[u]+c[p])){
						E.emplace_back(u,p);
						adj[u][p]=adj[p][u]=true;
						used[u]=true;
						used_here[u]=true;
						ans[i][a]=u;
						ok=true;
						break;
					}
				}
				else{
					if(adj[u][p]){
						used_here[u]=true;
						ans[i][a]=u;
						ok=true;
						break;
					}
				}
			}
			if(!ok){ ng[i]=true; break; }
		}
	}

	printf("%lu\n",E.size());
	for(auto e:E) printf("%d %d\n",e.first+1,e.second+1);
	rep(i,m) rep(a,k) printf("%d%c",(!ng[i]?ans[i][a]:a)+1,a<k-1?' ':'\n');

	return 0;
}
