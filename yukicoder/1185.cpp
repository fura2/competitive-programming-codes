#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n;
vector<lint> res;

void dfs(lint x){
	if(x>n) return;
	if(x>=10) res.emplace_back(x);
	dfs(10*x);
	dfs(10*x+3);
	dfs(10*x+6);
	dfs(10*x+9);
}

int main(){
	scanf("%d",&n);

	dfs(3);
	dfs(6);
	dfs(9);

	rep(a,10) if(a>0) rep(b,10) if((a+b)%3==0 && a%3!=0 && b%3!=0) {
		if(10*a+b<=n) res.emplace_back(10*a+b);
	}
	printf("%ld\n",res.size());

	return 0;
}
