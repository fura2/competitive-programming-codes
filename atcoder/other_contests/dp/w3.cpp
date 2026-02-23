#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

class starry_sky_tree{
	int n;
	vector<lint> dat1,dat2;

	void add(int l,int r,int a,int b,int u,lint val){
		if(b<=l || r<=a) return;
		if(l<=a && b<=r){ dat1[u]+=val; return; }

		add(l,r,a,(a+b)/2,2*u+1,val);
		add(l,r,(a+b)/2,b,2*u+2,val);

		dat2[u]=max(dat2[2*u+1]+dat1[2*u+1],dat2[2*u+2]+dat1[2*u+2]);
	}

	lint query_max(int l,int r,int a,int b,int u){
		if(b<=l || r<=a) return -INF;
		if(l<=a && b<=r) return dat1[u]+dat2[u];

		lint res1=query_max(l,r,a,(a+b)/2,2*u+1);
		lint res2=query_max(l,r,(a+b)/2,b,2*u+2);
		return max(res1,res2)+dat1[u];
	}

public:
	starry_sky_tree(int N){
		for(n=1;n<N;n*=2);
		dat1.assign(2*n,0);
		dat2.assign(2*n,0);
	}

	void add(int l,int r,lint val){ add(l,r,0,n,0,val); }
	void update_max(int x,lint val){
		lint tmp=query_max(x,x+1);
		if(tmp<val) add(x,x+1,val-tmp);
	}

	lint query_max(int l,int r){ return query_max(l,r,0,n,0); }
};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<pair<int,int>>> Ev(n+1);
	rep(i,m){
		int l,r,val; scanf("%d%d%d",&l,&r,&val); l--;
		Ev[r].emplace_back(l,val);
	}

	// dp[x] = ([0,t) に含まれる区間のみを考えて, 文字列の先頭から x 文字目までを決めたとき,
	//          x 文字目を 1 にして得られる最大スコア) (x は 1-indexed)
	// t = 0, 1, 2, ... について, 同じ dp 配列を使いまわして更新していく
	starry_sky_tree dp(n+1);
	dp.add(1,n+1,-INF);
	for(int x=1;x<=n;x++){
		// update dp[x]
		lint tmp=dp.query_max(0,x);
		for(auto p:Ev[x]){
			int val=p.second;
			tmp+=val;
		}
		dp.update_max(x,tmp);

		// update dp[y] for 0<=y<x
		for(auto p:Ev[x]){
			int l,val; tie(l,val)=p;
			dp.add(l+1,x,val);
		}
	}
	printf("%lld\n",dp.query_max(0,n+1));

	return 0;
}
