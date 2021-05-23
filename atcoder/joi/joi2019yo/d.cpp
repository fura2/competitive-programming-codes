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
	int size()const{ return n; }
	int size(int u){ return -p[find(u)]; }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<pair<int,int>> p(n);
	rep(i,n) p[i]={a[i],i};
	sort(p.rbegin(),p.rend());

	int ans=0;
	union_find U(n);
	vector<bool> live(n,false);
	rep(i,n){
		int j=p[i].second;
		if(a[j]==0) break;

		live[j]=true;
		if(j> 0  && live[j-1]) U.unite(j-1,j);
		if(j<n-1 && live[j+1]) U.unite(j,j+1);

		if(i==n-1 || p[i+1].first<p[i].first){
			ans=max(ans,int(U.size()-(n-i-1)));
		}
	}
	printf("%d\n",ans);

	return 0;
}
