#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> struct interval{
	T l,r;
	interval():l(T{}),r(T{}){}
	interval(const T& l,const T& r):l(l),r(r){}
};

template<class T>
int interval_scheduling(vector<interval<T>> I){
	sort(I.begin(),I.end(),[](const interval<T>& a,const interval<T>& b){
		return make_pair(a.r,a.l)<make_pair(b.r,b.l);
	});

	int res=0;
	T now=I[0].l;
	for(auto J:I) if(now<=J.l) now=J.r, res++;
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<interval<int>> I(n);
	rep(i,n){
		int x,l; scanf("%d%d",&x,&l);
		I[i]={x-l,x+l};
	}

	printf("%d\n",interval_scheduling(I));

	return 0;
}
