#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class segment_tree{
	int n;
	vector<int> seg,lazy;

	void propagate(int u){
		if(lazy[u]!=0){
			seg[u]=max(seg[u],lazy[u]);
			if(2*u  <2*n) lazy[2*u  ]=max(lazy[2*u  ],lazy[u]);
			if(2*u+1<2*n) lazy[2*u+1]=max(lazy[2*u+1],lazy[u]);
			lazy[u]=0;
		}
	}

	void update(int l,int r,int v,int u,int a,int b){
		propagate(u);

		if(l<=a && b<=r){
			lazy[u]=max(lazy[u],v);
			propagate(u);
			return;
		}

		int c=(a+b)/2;
		if(l<c && a<r) update(l,r,v,2*u  ,a,c);
		if(l<b && c<r) update(l,r,v,2*u+1,c,b);

		seg[u]=max(seg[2*u],seg[2*u+1]);
	}

	int get(int l,int r,int u,int a,int b){
		propagate(u);

		if(l<=a && b<=r){
			return seg[u];
		}

		int c=(a+b)/2,res=0;
		if(l<c && a<r) res=max(res,get(l,r,2*u  ,a,c));
		if(l<b && c<r) res=max(res,get(l,r,2*u+1,c,b));
		return res;
	}

public:
	segment_tree(int N){
		for(n=1;n<N;n<<=1);
		seg.assign(2*n,0);
		lazy.assign(2*n,0);
	}

	void update(int l,int r,int v){
		update(l,r,v,1,0,n);
	}

	int get(int l,int r){
		return get(l,r,1,0,n);
	}
};

int main(){
	int n,q; scanf("%d%d",&n,&q);

	segment_tree ST(n);
	rep(_,q){
		int l,r; scanf("%d%d",&l,&r); l--;
		int h=ST.get(l,r);
		ST.update(l,r,h+1);
		printf("%d\n",h+1);
	}

	return 0;
}
