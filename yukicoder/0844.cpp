#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> struct interval{
	T l,r;
	int wt;
	bool operator<(const interval& I)const{ return make_tuple(r,l)<make_tuple(I.r,I.l); }
};

const long long INF=1LL<<61;

int main(){
	int L,m,c; scanf("%d%d%d",&L,&m,&c);
	vector<interval<int>> I(m);
	rep(i,m) scanf("%d%d%d",&I[i].l,&I[i].r,&I[i].wt), I[i].r++;

	sort(I.begin(),I.end());

	int idx=0;
	// dp[x] = ([1, x) に含まれる区間だけを考えて, x の左に区切りを入れたときのスコアの最大値)
	vector<lint> dp(L+2,-INF),dp_max(L+2,-INF);
	dp[1]=0;
	dp_max[1]=0;
	for(int x=2;x<=L+1;x++){
		while(idx<m && I[idx].r==x){
			dp[x]=max(dp[x],dp[I[idx].l]+I[idx].wt-(x<L+1?c:0));
			dp[x]=max(dp[x],dp_max[I[idx].l-1]+I[idx].wt-(x<L+1?2*c:c));
			idx++;
		}
		dp_max[x]=max(dp_max[x-1],dp[x]);
	}
	printf("%lld\n",dp_max[L+1]);

	return 0;
}
