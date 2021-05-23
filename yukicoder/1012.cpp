#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> x(n),w(n);
	rep(i,n) scanf("%lld%lld",&x[i],&w[i]);
	vector<lint> a(q);
	rep(i,q) scanf("%lld",&a[i]);

	vector<int> p(q);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){ return a[i]<a[j]; });

	lint cost_L=0,cost_R=0,wsum_L=0,wsum_R=0;
	set<pair<lint,lint>> L,R;
	rep(i,n){
		R.emplace(x[i],w[i]);
		cost_R+=w[i]*x[i];
		wsum_R+=w[i];
	}
	vector<lint> ans(q);
	for(int i:p){
		while(!R.empty() && R.begin()->first<a[i]){
			auto [x0,w0]=*R.begin();
			R.erase(R.begin());
			cost_R-=w0*x0;
			wsum_R-=w0;
			L.emplace(x0,w0);
			cost_L+=w0*x0;
			wsum_L+=w0;
		}
		ans[i]=(cost_R-wsum_R*a[i])+(wsum_L*a[i]-cost_L);
	}

	rep(i,q) printf("%lld\n",ans[i]);

	return 0;
}
