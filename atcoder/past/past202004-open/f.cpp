#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<vector<int>> ev(n);
	rep(i,n){
		int a,b; scanf("%d%d",&a,&b); a--;
		ev[a].emplace_back(b);
	}

	int ans=0;
	priority_queue<int> Q;
	rep(i,n){
		for(int b:ev[i]) Q.push(b);
		ans+=Q.top(); Q.pop();
		printf("%d\n",ans);
	}

	return 0;
}
