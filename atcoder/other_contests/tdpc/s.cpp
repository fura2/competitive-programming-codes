#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1000000007;

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
	int h,w; cin>>w>>h;

	map<vector<int>,int> dp[101];
	{
		vector<int> S0(w,-1);
		S0[0]=0;
		dp[0][S0]=1;
	}
	rep(i,h) for(const auto &a:dp[i]) rep(S,1<<w) {
		const auto &pre=a.first;

		union_find U(2*w);
		rep(j,w){
			if(pre[j]!=-1 && (S>>j&1)==0) U.unite(j,w+j);
			if(j<w-1 && (S>>j&1)==0 && (S>>(j+1)&1)==0) U.unite(w+j,w+j+1);
			for(int k=j+1;k<w;k++) if(pre[j]==pre[k]) U.unite(j,k);
		}

		vector<int> next(w);
		map<int,int> f;
		rep(j,w) if(pre[j]==0) f[U.find(j)]=0;
		rep(j,w){
			if((S>>j&1)==1) next[j]=-1;
			else{
				int id=U.find(w+j);
				if(f.count(id)==0) f[id]=f.size();
				next[j]=f[id];
			}
		}
		if(count(next.begin(),next.end(),0)==0) continue;

		dp[i+1][next]=(dp[i+1][next]+a.second)%MOD;
	}

	int ans=0;
	for(const auto &a:dp[h]) if(a.first[w-1]==0) ans=(ans+a.second)%MOD;
	cout<<ans<<endl;

	return 0;
}
