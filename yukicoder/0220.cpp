#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint memo[20][3][2];

lint dfs(int n,int sum,bool f){
	if(memo[n][sum][f]!=-1) return memo[n][sum][f];

	if(n==0) return memo[n][sum][f]=((sum==0||f)?1:0);

	if(f) return memo[n][sum][f]=10*dfs(n-1,sum,true);

	lint res=0;
	rep(d,10){
		res+=dfs(n-1,(sum+d)%3,d==3);
	}
	return memo[n][sum][f]=res;
}

int main(){
	int n; scanf("%d",&n);
	memset(memo,-1,sizeof memo);
	printf("%lld\n",dfs(n,0,false)-1);
	return 0;
}
