#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class union_find{
	int n;
	vector<int> p;
public:
	union_find(int n):n(n),p(n,-1){}
	int find(int u){ return p[u]<0?u:p[u]=find(p[u]); }
	void unite(int u,int v){
		u=find(u); v=find(v);
		if(u!=v){
			if(p[v]<p[u]) swap(u,v);
			p[u]+=p[v]; p[v]=u; n--;
		}
	}
	bool is_same(int u,int v){ return find(u)==find(v); }
	int size(){ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n,m,W; cin>>n>>m>>W;
	vector<int> w(n),v(n);
	rep(i,n) cin>>w[i]>>v[i];

	union_find U(n);
	rep(i,m){
		int a,b; cin>>a>>b; a--; b--;
		U.unite(a,b);
	}

	vector<int> dp(W+1,-1);
	dp[0]=0;
	vector<bool> vis(U.size());
	rep(u,n){
		int i=U.find(u);
		if(vis[i]) continue;
		vis[i]=true;

		int wsum=0,vsum=0;
		rep(x,n) if(U.find(x)==i) wsum+=w[x], vsum+=v[x];

		for(int a=W-wsum;a>=0;a--) if(~dp[a]) {
			dp[a+wsum]=max(dp[a+wsum],dp[a]+vsum);
		}
	}

	cout<<*max_element(dp.begin(),dp.end())<<endl;

	return 0;
}
