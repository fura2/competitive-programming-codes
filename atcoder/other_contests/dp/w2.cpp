// w1.cpp を O(n log n) に高速化

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
	vector<int> l(m),r(m),val(m);
	rep(i,m) scanf("%d%d%d",&l[i],&r[i],&val[i]), r[i]++;

	vector<vector<int>> L(n+2),R(n+2);
	rep(i,m){
		L[l[i]].emplace_back(i);
		R[r[i]].emplace_back(i);
	}

	starry_sky_tree SS(n+2);
	SS.add(1,n+2,-INF);

	rep(x,n+2){
		for(int i:R[x]) SS.add(0,l[i],-val[i]);
		for(int i:L[x]) SS.add(0,l[i], val[i]);
		SS.update_max(x,SS.query_max(0,x));
	}
	printf("%lld\n",SS.query_max(0,n+2));

	return 0;
}
