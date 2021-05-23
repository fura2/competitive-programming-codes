#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n;
	string s; cin>>n>>s;

	rep(i,n) if(s[i]=='Y') s[i]='B';

	vector<int> pos[3];
	rep(i,n){
		if(s[i]=='R') pos[0].emplace_back(i);
		if(s[i]=='G') pos[1].emplace_back(i);
		if(s[i]=='B') pos[2].emplace_back(i);
	}
	int m[3];
	rep(i,3) m[i]=pos[i].size();

	static int dp[401][401][401][3];
	rep(c0,m[0]+1) rep(c1,m[1]+1) rep(c2,m[2]+1) rep(last,3) dp[c0][c1][c2][last]=INF;
	rep(last,3) dp[0][0][0][last]=0;
	rep(len,n){
		int c[3];
		for(c[0]=0;c[0]<=min(m[0],len);c[0]++){
			for(c[1]=0;c[1]<=min(m[1],len-c[0]);c[1]++){
				c[2]=len-c[0]-c[1];
				if(c[2]>m[2]) continue;

				rep(last,3) if(dp[c[0]][c[1]][c[2]][last]<INF) {
					rep(last2,3){
						if(last2==last || c[last2]+1>m[last2]) continue;

						int p=pos[last2][c[last2]],cnt=0;
						rep(i,3){
							int idx=upper_bound(pos[i].begin(),pos[i].end(),p)-pos[i].begin();
							cnt+=max(c[i]-idx,0);
						}
						p+=cnt;

						int c2[3]={c[0],c[1],c[2]};
						c2[last2]++;
						dp[c2[0]][c2[1]][c2[2]][last2]
						=min(dp[c2[0]][c2[1]][c2[2]][last2],dp[c[0]][c[1]][c[2]][last]+p-len);
					}
				}
			}
		}
	}

	int ans=INF;
	rep(last,3) ans=min(ans,dp[m[0]][m[1]][m[2]][last]);
	printf("%d\n",ans<INF?ans:-1);

	return 0;
}
