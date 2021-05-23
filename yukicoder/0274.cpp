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
	int n,m; scanf("%d%d",&n,&m);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]);

	union_find U(n);
	rep(i,n) for(int j=i+1;j<n;j++) {
		int cnt=0;
		if(l[j]<=r[i] && l[i]<=r[j]) cnt++;
		if(m-r[j]-1<=r[i] && l[i]<=m-l[j]-1) cnt++;
		if(cnt==2) return puts("NO"),0;
		if(cnt==1){
			if(U.is_same(i,j)) return puts("NO"),0;
			U.unite(i,j);
		}
	}

	puts("YES");

	return 0;
}
