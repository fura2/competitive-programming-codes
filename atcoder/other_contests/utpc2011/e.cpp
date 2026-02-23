#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d%d",&a[i],&b[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return b[i]<b[j];
	});

	vector<int> dp(n+1,INF);
	dp[0]=0;
	rep(i,n){
		for(int j=i;j>=0;j--){
			if(dp[j]+a[p[i]]<=b[p[i]]){
				dp[j+1]=min(dp[j+1],dp[j]+a[p[i]]);
			}
		}

	}

	for(int i=n;i>=0;i--) if(dp[i]<INF) {
		printf("%d\n",i);
		break;
	}

	return 0;
}
