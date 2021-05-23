#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct interval{
	T l,r;
	interval(){}
	interval(const T& l,const T& r):l(l),r(r){}
	bool operator<(const interval& I)const{ return make_tuple(r,l)<make_tuple(I.r,I.l); }
};

int input(){
	int d,h,m; scanf("%d%d:%d",&d,&h,&m);
	return 24*60*(d-2)+60*h+m;
}

int main(){
	int k,n; scanf("%d%d",&k,&n);
	vector<interval<int>> I(n);
	rep(i,n){
		I[i].l=input();
		I[i].r=input()+1;
	}

	sort(I.begin(),I.end());

	int ans=0;
	vector<int> cnt(24*60*7);
	rep(i,n){
		int mx=0;
		for(int x=I[i].l;x<I[i].r;x++) mx=max(mx,cnt[x]);
		if(mx<k){
			ans++;
			for(int x=I[i].l;x<I[i].r;x++) cnt[x]++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
