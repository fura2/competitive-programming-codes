#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> x(n),y(n),hp(n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&hp[i]), x[i]+=500, y[i]+=500;

	static int sum[1502][1502];
	rep(i,k){
		int ax,ay,w,h,d; scanf("%d%d%d%d%d",&ax,&ay,&w,&h,&d); ax+=500; ay+=500;
		sum[ay][ax]+=d;
		sum[ay][ax+w+1]-=d;
		sum[ay+h+1][ax]-=d;
		sum[ay+h+1][ax+w+1]+=d;
	}
	rep(i,1502) rep(j,1501) sum[i][j+1]+=sum[i][j];
	rep(i,1501) rep(j,1502) sum[i+1][j]+=sum[i][j];

	int ans=0;
	rep(i,n) ans+=max(hp[i]-sum[y[i]][x[i]],0);
	printf("%d\n",ans);

	return 0;
}
