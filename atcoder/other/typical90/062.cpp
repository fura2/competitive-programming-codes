#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	vector<vector<pair<int,int>>> L(n);
	vector<bool> vis(n);
	queue<int> Q;
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b); a--; b--;
		if(a==i || b==i){
			vis[i]=true;
			Q.emplace(i);
		}
		else{
			L[a].emplace_back(b,i);
			L[b].emplace_back(a,i);
		}
	}

	vector<int> ans;
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		ans.emplace_back(u);
		for(auto [_,v]:L[u]){
			if(!vis[v]){
				vis[v]=true;
				Q.emplace(v);
			}
		}
	}

	if(ans.size()<n){
		puts("-1");
	}
	else{
		reverse(ans.begin(),ans.end());
		rep(i,n) printf("%d\n",ans[i]+1);
	}

	return 0;
}
