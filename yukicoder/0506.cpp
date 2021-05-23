#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

inline int popcount(int x){
	x=((x>>1)&0x55555555)+(x&0x55555555);
	x=((x>>2)&0x33333333)+(x&0x33333333);
	x=((x>>4)+x)&0x0f0f0f0f;
	x+=(x>>8);
	x+=(x>>16);
	return x&0x3f;
}

int main(){
	int h,w,k,p; scanf("%d%d%d%d",&w,&h,&k,&p);
	vector<int> x(k),y(k);
	vector<string> s(k);
	rep(i,k) cin>>x[i]>>y[i]>>s[i];

	lint ans=0;
	int S_ans=0;
	rep(S,1<<k) if(popcount(S)==p) {
		bool ng[33][33]={};
		rep(i,k) if((S>>i&1)==0) ng[y[i]][x[i]]=true;

		lint dp[33][33]={1};
		rep(i,h+1) rep(j,w+1) if(!ng[i][j]) {
			if(i<h) dp[i+1][j]+=dp[i][j];
			if(j<w) dp[i][j+1]+=dp[i][j];
		}
		if(ans<dp[h][w]){
			ans=dp[h][w];
			S_ans=S;
		}
	}

	cout<<ans%1000000007<<'\n';
	rep(i,k) if(S_ans>>i&1) cout<<s[i]<<'\n';

	return 0;
}
