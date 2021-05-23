#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

map<lint,lint> memo;

lint dfs(lint n){
	if(n==0) return 1;
	if(memo.count(n)) return memo[n];
	return memo[n]=dfs(n/3)+dfs(n/5);
}

int main(){
	lint n; cin>>n;
	cout<<dfs(n)<<'\n';
	return 0;
}
