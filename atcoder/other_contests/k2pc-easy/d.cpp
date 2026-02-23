#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int k,n; scanf("%d%d",&k,&n);
	vector<lint> a[51];
	rep(i,n){
		int p;
		lint q; scanf("%d%lld",&p,&q); q--;
		a[p].emplace_back(q);
	}

	rep(i,k+1) sort(a[i].begin(),a[i].end());

	lint ans=(1LL<<(k+1))-1;
	rep(i,k+1) for(lint q:a[i]) {
		int d=i;
		lint x=q;
		bool found=false;
		while(d>0){
			x/=2;
			d--;
			if(binary_search(a[d].begin(),a[d].end(),x)){ found=true; break; }
		}
		if(!found) ans-=(1LL<<(k-i+1))-1;
	}
	printf("%lld\n",ans);

	return 0;
}
