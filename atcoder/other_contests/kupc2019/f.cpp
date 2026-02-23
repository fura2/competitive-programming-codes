#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const lint INF=1LL<<61;

struct interval{
	int l,r;
	lint val;
	bool operator<(const interval& I)const{ return tie(r,l)<tie(I.r,I.l); }
};

int main(){
	int n,m;
	lint cost[3000];
	interval I[3000];

	cin>>n;
	rep(x,n) cin>>cost[x];
	cin>>m;
	rep(i,m) cin>>I[i].l>>I[i].r>>I[i].val, I[i].l--;

	sort(I,I+m);

	// dp[i][x] := ( I[0], ..., I[i] の順に割り当てるか使わないかを選び,
	//               最後に区間を割り当てた場所が x であるときのダメージの最大値 )
	static lint dp[3000][3000];
	rep(x,n){
		if(I[0].l<=x && x<I[0].r) dp[0][x]=I[0].val-cost[x];
		else                      dp[0][x]=-INF;
	}
	for(int i=1;i<m;i++){
		lint mx=0;
		rep(x,n){
			dp[i][x]=dp[i-1][x];
			mx=max(mx,dp[i-1][x]);
		}

		for(int x=I[i].l;x<I[i].r;x++){
			dp[i][x]=max({dp[i][x],dp[i-1][x]+I[i].val,mx+I[i].val-cost[x]});
		}
	}

	cout<<max(*max_element(dp[m-1],dp[m-1]+n),0LL)<<endl;

	return 0;
}
