#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	vector pos(m,vector<int>());
	rep(i,n) pos[a[i]].emplace_back(i);

	vector dp(1<<m,INF);
	dp[0]=0;
	rep(S,1<<m){
		int len=0;
		rep(c,m) if(S>>c&1) len+=pos[c].size();

		rep(c,m) if((S>>c&1)==0) {
			int cnt=lower_bound(pos[c].begin(),pos[c].end(),len+pos[c].size())
				   -lower_bound(pos[c].begin(),pos[c].end(),len);
			dp[S|1<<c]=min<int>(dp[S|1<<c],dp[S]+pos[c].size()-cnt);
		}
	}
	printf("%d\n",dp[(1<<m)-1]);

	return 0;
}
