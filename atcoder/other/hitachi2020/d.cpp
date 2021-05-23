#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint T; scanf("%d%lld",&n,&T);

	vector<lint> a1,b1,b2;
	rep(i,n){
		lint a,b; scanf("%lld%lld",&a,&b);
		if(a>0){
			a1.emplace_back(a);
			b1.emplace_back(b);
		}
		else{
			b2.emplace_back(b);
		}
	}
	int n1=a1.size(),n2=b2.size();

	{
		vector<pair<lint,lint>> p(n1);
		rep(i,n1) p[i]={a1[i],b1[i]};
		sort(p.begin(),p.end(),[](auto x,auto y){
			return y.first*(x.second+1)<x.first*(y.second+1);
		});
		rep(i,n1) tie(a1[i],b1[i])=p[i];
	}
	sort(b2.begin(),b2.end());

	vector<lint> dp(31,T+1);
	dp[0]=0;
	rep(i,n1){
		for(int j=29;j>=0;j--){
			dp[j+1]=min(dp[j+1],(a1[i]+1)*(dp[j]+1)+b1[i]);
		}
	}

	int ans=0;
	rep(i,31) if(dp[i]<=T) {
		ans=max(ans,i);
		lint t=dp[i];
		rep(j,n2){
			t+=b2[j]+1;
			if(t<=T) ans=max(ans,i+j+1);
		}
	}
	printf("%d\n",ans);

	return 0;
}
