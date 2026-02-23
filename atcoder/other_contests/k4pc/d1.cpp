// O(n log n) DP solution

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct interval{
	int l,r,wt;
	interval(){}
	interval(int l,int r,int wt):l(l),r(r),wt(wt){}
	bool operator<(const interval& I)const{ return r<I.r; }
};

int main(){
	const int L=1e5;

	int n,cost; scanf("%d%d",&n,&cost);
	vector<interval> I(n);
	rep(i,n) scanf("%d%d%d",&I[i].l,&I[i].r,&I[i].wt);

	sort(I.begin(),I.end());

	int ans=cost*L;
	vector<int> dp(n);
	rep(i,n){
		ans=max(ans,I[i].wt+cost*I[i].l+cost*(L-I[i].r)); // 区間 i のみを選ぶ

		dp[i]=I[i].wt+cost*I[i].l; // 区間 i を最初に選ぶ

		if(i>0) dp[i]=max(dp[i],dp[i-1]);

		int idx=upper_bound(I.begin(),I.end(),interval{-1,I[i].l,-1})-I.begin();
		if(idx==0) continue;
		idx--;
		dp[i]=max(dp[i],dp[idx]+I[i].wt); // 区間 i を途中で選ぶ
		ans=max(ans,dp[idx]+I[i].wt+cost*(L-I[i].r)); // 区間 i を最後に選ぶ
	}
	ans-=cost*L;

	printf("%d\n",ans);

	return 0;
}
