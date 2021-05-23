#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
vector<int> sliding_window_minimum(const vector<T>& a,int w){
	int n=a.size();
	if(w>n) return {};

	vector<int> res(n-w+1);
	deque<int> D;
	rep(i,n){
		while(!D.empty() && a[D.back()]>a[i]) D.pop_back();
		D.emplace_back(i);
		if(i>=w-1){
			if(i-D.front()>=w) D.pop_front();
			res[i-w+1]=D.front();
		}
	}
	return res;
}

int main(){
int q; scanf("%d",&q);
rep(_,q){
printf("#%d\n",_);
	int n,d,k; scanf("%d%d%d",&n,&d,&k);
	vector<int> a(2*n);
	rep(i,n) scanf("%d",&a[i]), a[i]*=-1;

	auto idx=sliding_window_minimum(a,d);

	lint ans=0;
	int l,r;
	rep(i,n){
		lint buy=-a[i],sell=-a[idx[i+1]];
		if(ans<k*(sell-buy)){
			ans=k*(sell-buy);
			l=i;
			r=idx[i+1];
		}
	}

	printf("%lld\n",ans);
	if(ans>0) printf("%d %d\n",l,r);
}
	return 0;
}
