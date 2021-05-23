#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)
#define dbg(S) { int f=1; for(auto x:S) cerr<<(f?"[":", ")<<x, f=0; cerr<<"]\n"; }

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
	int n; cin>>n;
	vector<int> a(n),b(n);
	rep(i,n) cin>>a[i];
	rep(i,n) cin>>b[i];

	vector<pair<int,int>> a2(n),b2(n);
	rep(i,n){
		a2[i]={a[i],i};
		b2[i]={b[i],i};
	}
	sort(a2.begin(),a2.end());
	sort(b2.begin(),b2.end());

	bool ok=true;
	vector<int> to(n);
	rep(i,n){
		if(a2[i].first>b2[i].first) ok=false;
		to[a2[i].second]=b2[i].second;
	}
	if(!ok){
		cout<<"No\n";
		return 0;
	}

	// 行き先が 2 ヶ所以上ある a の要素があれば Yes
	ok=false;
	for(int i=n-1;i>0;i--) if(a2[i]<=b2[i-1]) ok=true;
	if(ok){
		cout<<"Yes\n";
		return 0;
	}

	// 行き先を伝って全体で 1 つのループになっていれば No, そうでなければ Yes
	union_find U(n);
	rep(i,n) U.unite(i,to[i]);
	cout<<(U.size()==1?"No":"Yes")<<'\n';

	return 0;
}
