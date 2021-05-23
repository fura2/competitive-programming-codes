#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,bad[100000],deg[100000],ans[100000];

set<int> V; // unused vertices (and a centinel)
set<pair<int,int>> Deg; // (degree, vertex)

bool dfs(int i){
	if(i==n) return true;

	int x=Deg.rbegin()->second;
	if(deg[x]==n-i-1){
		if(i==0 || bad[ans[i-1]]!=x){
			int y=bad[x];
			bool b=V.count(y);

			Deg.erase({deg[x],x});
			if(b){
				Deg.erase({deg[y],y});
				deg[y]--;
				Deg.emplace(deg[y],y);
			}
			V.erase(x);

			ans[i]=x;
			if(dfs(i+1)) return true;

			V.emplace(x);
			if(b){
				Deg.erase({deg[y],y});
				deg[y]++;
				Deg.emplace(deg[y],y);
			}
			Deg.emplace(deg[x],x);
		}
		return false;
	}

	for(int x=*V.begin();x<n;x=*V.upper_bound(x)){
		if(i==0 || bad[ans[i-1]]!=x){
			int y=bad[x];
			bool b=V.count(y);

			Deg.erase({deg[x],x});
			if(b){
				Deg.erase({deg[y],y});
				deg[y]--;
				Deg.emplace(deg[y],y);
			}
			V.erase(x);

			ans[i]=x;
			if(dfs(i+1)) return true;

			V.emplace(x);
			if(b){
				Deg.erase({deg[y],y});
				deg[y]++;
				Deg.emplace(deg[y],y);
			}
			Deg.emplace(deg[x],x);
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&bad[i]), bad[i]--;

	rep(i,n+1) V.emplace(i);
	rep(i,n) deg[bad[i]]++;
	rep(i,n) Deg.emplace(deg[i],i);

	if(dfs(0)){
		rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');
	}
	else{
		puts("-1");
	}

	return 0;
}
