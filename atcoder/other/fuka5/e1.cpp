#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	while(1){
		int n; scanf("%d",&n);
		if(n==0) break;
		vector<int> a(n);
		rep(i,n) scanf("%d",&a[i]);

		vector<int> nxt(n);
		for(int x=n-1;x>=0;x--){
			if     (a[x]==-1) nxt[x]=0;
			else if(a[x]== 0) nxt[x]=x;
			else              nxt[x]=nxt[min(x+a[x],n-1)];
		}

		double lo=0,hi=1e7;
		rep(_,50){
			double mi=(lo+hi)/2;

			vector dp(n,0.0);
			for(int x=n-2;x>=0;x--){
				for(int d=1;d<=6;d++){
					int x2=nxt[min(x+d,n-1)];
					if(x2==0) dp[x]+=mi/6;
					else      dp[x]+=dp[x2]/6;
				}
				dp[x]++;
			}
			if(dp[0]<mi) hi=mi;
			else         lo=mi;
		}
		printf("%.9f\n",lo);
	}

	return 0;
}
