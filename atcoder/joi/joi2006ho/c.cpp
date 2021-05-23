#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> ans;

void dfs(int n,int k){
	if(n==0){
		rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');
		return;
	}

	for(int i=k;i>0;i--){
		ans.emplace_back(i);
		dfs(n-i,min(i,n-i));
		ans.pop_back();
	}
}

int main(){
	int n; scanf("%d",&n);
	dfs(n,n);
	return 0;
}
