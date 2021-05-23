#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m=0; scanf("%d",&n);
	queue<int> Q[1000];
	rep(i,n){
		int p; scanf("%d",&p);
		rep(j,p){
			int a; scanf("%d",&a);
			Q[i].push(a);
		}
		m+=p;
	}

	vector<int> ans;
	while(ans.size()<m){
		rep(i,n) if(!Q[i].empty()) ans.emplace_back(Q[i].front()), Q[i].pop();
	}
	rep(i,m) printf("%d%c",ans[i],i<m-1?' ':'\n');

	return 0;
}
