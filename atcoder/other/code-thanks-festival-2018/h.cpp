#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n,a[1000];
lint cum[1001];

lint tar;
int memo[1001][2][8];

// k = (これまでに作った tar 以上の整数の個数) - (これまでに作った tar 未満の整数の個数)
bool dfs(int i,int turn,int k){
	int& res=memo[i][turn][k+4];
	if(res!=-1) return res;

	if(turn==0){
		if(k>0) return res=true;
		if(i==n) return res=(k>=0);
	}
	else{
		if(k<-1) return res=true;
		if(i==n) return res=(k<0);
	}

	for(int j=i+1;j<=n;j++){
		if(cum[j]-cum[i]>=tar){
			if(!dfs(j,1-turn,k+1)) return res=true;
		}
		else{
			if(!dfs(j,1-turn,k-1)) return res=true;
		}
	}
	return res=false;
}

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) cum[i+1]=cum[i]+a[i];

	lint lo=-1e12,hi=1e12+1;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		tar=mi;

		memset(memo,-1,sizeof memo);
		if(dfs(0,0,0)) lo=mi;
		else           hi=mi;
	}
	printf("%lld\n",lo);

	return 0;
}
