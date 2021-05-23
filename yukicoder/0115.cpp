#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	int n,d,k; scanf("%d%d%d",&n,&d,&k);

	// dp[i][w][j] = i+1 円以上の商品だけからちょうど d 個選んで w 円を作るときの, 選べる商品の値段の最小値 (作れないなら INF)
	int dp[101][1001][11];
	rep(i,n+1) rep(w,d+1) rep(j,k+1) dp[i][w][j]=INF;
	rep(i,n+1) dp[i][0][0]=n+1;
	for(int i=n;i>0;i--){
		for(int w=d-i;w>=0;w--){
			for(int j=k-1;j>=0;j--){
				dp[i-1][w+i][j+1]=dp[i][w+i][j+1];
				if(dp[i][w][j]<INF){
					dp[i-1][w+i][j+1]=min(dp[i-1][w+i][j+1],i);
				}
			}
		}
	}

	int i;
	for(i=0;i<n;i++) if(dp[i][d][k]<INF) break;
	if(i==n) return puts("-1"),0;

	vector<int> ans;
	int w=d,j=k;
	while(w>0){
		int next=dp[i][w][j];
		ans.emplace_back(next);
		w-=next;
		j--;
		i=next;
	}
	rep(i,ans.size()) printf("%d%c",ans[i],i+1<ans.size()?' ':'\n');

	return 0;
}
