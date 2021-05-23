#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);

	int res1=0,res2=0;
	vector<int> V,W;
	rep(i,n){
		int v,w; scanf("%d%d",&w,&v);
		int x=v-w+w/100*20;
		if(x>=0){
			res1+=v;
			res2+=w;
		}
		else if(x>-20){
			V.emplace_back(w%100);
			W.emplace_back(-x);
		}
	}
	n=V.size();

	vector<int> dp(2001,-INF);
	dp[0]=res2%100;
	rep(i,n){
		for(int a=2000;a>=W[i];a--){
			if(dp[a-W[i]]!=-INF){
				dp[a]=max(dp[a],dp[a-W[i]]+V[i]);
			}
		}
	}
	int res3=0;
	rep(a,2001) if(dp[a]!=-INF) res3=max(res3,dp[a]/100*20-a);

	printf("%d\n",res1-res2+res2/100*20+res3);

	return 0;
}
