#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a[10];
	rep(i,n){
		int b,t; scanf("%d%d",&b,&t); t--;
		a[t].emplace_back(b);
	}
	rep(t,10) sort(a[t].rbegin(),a[t].rend());

	vector dp(k+1,-INF);
	dp[0]=0;
	rep(t,10){
		auto next=dp;
		int sum=0;
		rep(i,a[t].size()){
			sum+=a[t][i];
			for(int j=k;j>=i+1;j--) next[j]=max(next[j],dp[j-(i+1)]+sum+i*(i+1));
		}
		dp=next;
	}
	printf("%d\n",dp[k]);

	return 0;
}
