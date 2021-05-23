#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int s[61];
lint memo[62][2][2];

lint dfs(int i,bool smaller,bool ok){
	if(memo[i][smaller][ok]!=-1) return memo[i][smaller][ok];

	if(i==61) return memo[i][smaller][ok]=(ok?1:0);

	lint res=0;
	if(smaller){
		// i bit 目を 0 にする
		res+=dfs(i+1,true,ok);
		// i bit 目を 1 にする
		res+=dfs(i+1,true,ok||(s[i]==0));
	}
	else{
		// i bit 目を 0 にする
		res+=dfs(i+1,s[i]==1,ok);
		// i bit 目を 1 にする
		if(s[i]==1){
			res+=dfs(i+1,false,ok||(s[i]==0));
		}
	}
	return memo[i][smaller][ok]=res;
}

int main(){
	lint n; scanf("%lld",&n);

	rep(i,61) s[i]=n>>(60-i)&1;

	memset(memo,-1,sizeof memo);
	printf("%lld\n",dfs(0,false,false));

	return 0;
}
