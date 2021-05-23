#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	const int W=1000;

	lint x; scanf("%lld",&x);

	if(x==1) return puts("1 1\n2"),0;

	lint dp[W+1]={1};
	vector<int> Ans;
	while(2*accumulate(dp,dp+W+1,0LL)<=x){
		for(int a=W;a>=1;a--) dp[a]+=dp[a-1];
		Ans.emplace_back(1);
	}

	x-=accumulate(dp,dp+W+1,0LL);
	while(x>0){
		int w=W/2+1;
		lint sum=accumulate(dp,dp+W-w+1,0LL);
		for(;sum>x;w++) sum-=dp[W-w];

		for(int a=W;a>=w;a--) dp[a]+=dp[a-w];
		Ans.emplace_back(w);
		x-=sum;
	}

	printf("%lu %d\n",Ans.size(),W);
	for(auto w:Ans) printf("%d\n",w);

	return 0;
}
