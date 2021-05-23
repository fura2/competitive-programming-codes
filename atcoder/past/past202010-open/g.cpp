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

bool check(vector<string> B){
	int h=B.size(),w=B[0].size();
	union_find U(h*w);
	rep(i,h) rep(j,w) if(B[i][j]=='.') {
		if(i<h-1 && B[i+1][j]=='.') U.unite(i*w+j,(i+1)*w+j);
		if(j<w-1 && B[i][j+1]=='.') U.unite(i*w+j,i*w+(j+1));
	}

	int cnt=0;
	rep(i,h) rep(j,w) if(B[i][j]=='#') cnt++;
	return U.size()-cnt==1;
}

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h) rep(j,w) if(B[i][j]=='#') {
		B[i][j]='.';
		if(check(B)) ans++;
		B[i][j]='#';
	}
	printf("%d\n",ans);

	return 0;
}
