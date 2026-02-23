#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint a,b;
bool used[36];

int dfs(lint x){
	if(x>b) return 1;

	lint res=dfs(x+1);
	bool ok=true;
	for(lint y=a;y<x;y++) if(used[y-a] && gcd(y,x)!=1) {
		ok=false;
		break;
	}
	if(ok){
		used[x-a]=true;
		res+=dfs(x+1);
		used[x-a]=false;
	}
	return res;
}

int main(){
	scanf("%lld%lld",&a,&b);
	cout<<dfs(a)<<'\n';
	return 0;
}
