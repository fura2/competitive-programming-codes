#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n,m,c[88];
bool A[88][88];

bool used[88];
vector<int> memo[8889];

void dfs(int u,int sum,vector<int>& S){
	if(u==n){
		if(!memo[sum].empty()){
			for(auto T:{S,memo[sum]}){
				printf("%ld\n",T.size());
				rep(i,T.size()) printf("%d%c",T[i]+1,i+1<T.size()?' ':'\n');
			}
			exit(0);
		}
		memo[sum]=S;
		return;
	}

	dfs(u+1,sum,S);

	bool ok=true;
	rep(v,u) if(used[v] && A[u][v]) ok=false;
	if(ok){
		used[u]=true;
		S.emplace_back(u);
		dfs(u+1,sum+c[u],S);
		S.pop_back();
		used[u]=false;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	rep(u,n) scanf("%d",&c[u]);
	rep(i,m){
		int u,v; scanf("%d%d",&u,&v); u--; v--;
		A[u][v]=A[v][u]=true;
	}

	vector<int> S;
	dfs(0,0,S);

	return 0;
}
