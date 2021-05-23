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
	int n,a,b; scanf("%d%d%d",&n,&a,&b);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	union_find U(n);
	vector<int> sum(n+1);
	rep(i,n){
		int l=lower_bound(x.begin(),x.end(),x[i]+a)-x.begin();
		int r=upper_bound(x.begin(),x.end(),x[i]+b)-x.begin();
		if(l<r-1){
			sum[l]++;
			sum[r-1]--;
		}
		if(l<r) U.unite(i,l);

		l=lower_bound(x.begin(),x.end(),x[i]-b)-x.begin();
		r=upper_bound(x.begin(),x.end(),x[i]-a)-x.begin();
		if(l<r-1){
			sum[l]++;
			sum[r-1]--;
		}
		if(l<r) U.unite(i,l);
	}

	rep(i,n) sum[i+1]+=sum[i];
	rep(i,n) if(sum[i]>0) U.unite(i,i+1);

	rep(i,n) printf("%d\n",U.size(i));

	return 0;
}
