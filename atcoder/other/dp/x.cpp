#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	tuple<int,int,int> a[1000];
	rep(i,n){
		int w,s,v; scanf("%d%d%d",&w,&s,&v);
		a[i]=make_tuple(w,s,v);
	}

	sort(a,a+n,[](const auto& x,const auto& y){
		return get<0>(x)+get<1>(x)<get<0>(y)+get<1>(y);
	});

	lint dp[20001];
	rep(x,20001) dp[x]=-INF;
	dp[0]=0;
	rep(i,n){
		int w,s,v; tie(w,s,v)=a[i];
		for(int x=s;x>=0;x--) if(dp[x]>-INF) {
			dp[x+w]=max(dp[x+w],dp[x]+v);
		}
	}
	printf("%lld\n",*max_element(dp,dp+20001));

	return 0;
}
