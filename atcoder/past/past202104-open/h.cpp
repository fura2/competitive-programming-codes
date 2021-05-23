#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n,m,k;
	lint l; scanf("%d%d%d%lld",&n,&m,&k,&l);
	vector<lint> a,b;
	rep(i,n){
		lint x;
		int type; scanf("%lld%d",&x,&type);
		if(type==0) a.emplace_back(x);
		else        b.emplace_back(x);
	}

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	vector<lint> acum(a.size()+1),bcum(b.size()+1);
	rep(i,a.size()) acum[i+1]=acum[i]+a[i];
	rep(i,b.size()) bcum[i+1]=bcum[i]+b[i];

	lint ans=INF;
	rep(i,a.size()+1) if(m-i<=b.size()) {
		ans=min(ans,acum[i]+bcum[m-i]+(m-i+k-1)/k*l);
	}
	printf("%lld\n",ans);

	return 0;
}
