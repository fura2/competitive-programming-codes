#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	int n; scanf("%d",&n);
	vector<lint> p(n),m(n);
	rep(i,n) scanf("%lld%lld",&p[i],&m[i]);

	lint total=inner_product(p.begin(),p.end(),m.begin(),0LL);

	lint ans=0;
	for(lint x=max(total-3030,0LL);x<=total;x++){
		lint t=x,sum=0;
		rep(i,n){
			sum+=m[i]*p[i];
			rep(_,m[i]){
				if(t%p[i]!=0) break;
				t/=p[i];
				sum-=p[i];
			}
		}
		if(t==1 && sum==x) ans=x;
	}
	printf("%lld\n",ans);
}

int main(){
	int t; scanf("%d",&t);
	rep(_,t){
		printf("Case #%d: ",_+1);
		solve();
	}
	return 0;
}
