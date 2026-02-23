#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		vector<lint> a(2);
		lint x; scanf("%lld%lld%lld",&a[0],&a[1],&x);

		for(int i=1;;i++){
			if(a[i-1]+a[i]>x) break;
			a.emplace_back(a[i-1]+a[i]);
		}
		int n=a.size();

		lint ans=0;
		rep(k,2){
			lint y=(k==0?x:x-a[0]);
			for(int i=n-1;i>=k+1;i--){
				if(y>=a[i]) y-=a[i];
			}
			if(y==0) ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
