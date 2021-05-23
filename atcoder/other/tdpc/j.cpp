#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

int main(){
	int n,x[16]; cin>>n;
	rep(i,n) cin>>x[i];

	double dp[1<<16];
	rep(S,1<<n) dp[S]=(S==0?0:INF);
	rep(S,1<<n) rep(y,16) {
		int T[]={S,S,S};
		rep(i,n){
			if(y-1==x[i]) T[0]&=~(1<<i);
			if(y  ==x[i]) T[1]&=~(1<<i);
			if(y+1==x[i]) T[2]&=~(1<<i);
		}

		int cnt=0;
		double rhs=0;
		rep(i,3){
			if(T[i]==S) cnt++;
			else rhs+=dp[T[i]];
		}
		if(cnt<3) dp[S]=min(dp[S],(rhs+3)/(3-cnt));
	}

	cout<<setprecision(9)<<dp[(1<<n)-1]<<endl;

	return 0;
}
