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

template<class T> struct interval{
	T l,r;
	interval(){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

template<class T>
vector<interval<T>> interval_union(vector<interval<T>> I){
	sort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){ return a.l<b.l; });

	int n=I.size();
	if(n==0) return {};

	vector<interval<T>> res;
	T l=I[0].l,r=I[0].r;
	for(int i=1;i<=n;i++){
		if(i==n || r<I[i].l){
			res.emplace_back(l,r);
			if(i<n){
				l=I[i].l;
				r=I[i].r;
			}
		}
		else if(r<I[i].r){
			r=I[i].r;
		}
	}
	return res;
}

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
	vector<interval<int>> H;
	vector<int> I,Y;
	int y_pre=-1;
	for(int i=n-1;i>=0;i--){
		int idx=p[i];

		int l=upper_bound(Y.begin(),Y.end(),y[idx])-Y.begin();
		if(l<Y.size()){
			U.unite(idx,I[l]);
			H.emplace_back(l,Y.size()-1);
		}

		if(y[idx]>y_pre){
			I.emplace_back(idx);
			Y.emplace_back(y[idx]);
			y_pre=y[idx];
		}
	}

	for(auto J:interval_union(H)){
		for(int i=J.l;i<J.r;i++) U.unite(I[i],I[i+1]);
	}
	rep(i,n) printf("%d\n",U.size(i));

	return 0;
}
