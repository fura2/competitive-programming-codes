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
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]), x[i]--, y[i]--;

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return x[i]<x[j];
	});

	union_find U(n);
	stack<int> S;
	for(int i:p){
		if(S.empty() || y[S.top()]>y[i]){
			S.push(i);
		}
		else{
			int tmp=S.top();
			while(!S.empty() && y[S.top()]<y[i]){
				U.unite(S.top(),i);
				S.pop();
			}
			S.push(tmp);
		}
	}
	rep(i,n) printf("%d\n",U.size(i));

	return 0;
}
