#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int bit[63];
lint memo[63][2];

lint dfs(int b,lint k,bool smaller){
	if(b==-1) return 1;

	if(memo[b][smaller]!=-1) return memo[b][smaller];

	lint res=0;
	// 2^b の桁を 0 にする
	if(bit[b]!=1){
		res+=dfs(b-1,k,smaller||(k>>b&1)==1);
	}
	// 2^b の桁を 1 にする
	if(bit[b]!=0 && (smaller||(k>>b&1)==1)){
		res+=dfs(b-1,k,smaller);
	}
	return memo[b][smaller]=res;
}

int main(){
	int n;
	lint l,r; cin>>n>>l>>r;
	vector<lint> a(n);
	rep(i,n) cin>>a[i];

	rep(b,63) bit[b]=-1;
	rep(i,n-1){
		int b;
		for(b=62;b>=0;b--) if((a[i]^a[i+1])>>b&1) break;
		if(a[i]<a[i+1]){
			if(bit[b]==1) return puts("0"),0;
			bit[b]=0;
		}
		else{
			if(bit[b]==0) return puts("0"),0;
			bit[b]=1;
		}
	}

	memset(memo,-1,sizeof memo);
	lint ans=dfs(62,r,false);
	if(l>0){
		memset(memo,-1,sizeof memo);
		ans-=dfs(62,l-1,false);
	}
	cout<<ans<<'\n';

	return 0;
}
