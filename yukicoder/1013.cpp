#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> p(n);
	rep(i,n) scanf("%d",&p[i]);

	vector dbl(30,vector<pair<int,int>>(n));
	rep(i,n){
		if(i+p[i]<n) dbl[0][i]={i+p[i],0};
		else         dbl[0][i]={(i+p[i]-n),1};
	}
	for(int t=1;t<30;t++){
		rep(i,n){
			auto [i1,c1]=dbl[t-1][i];
			auto [i2,c2]=dbl[t-1][i1];
			dbl[t][i]={i2,c1+c2};
		}
	}

	rep(i,n){
		lint x=i,c=0;
		rep(t,30) if(k>>t&1) {
			c+=dbl[t][x].second;
			x=dbl[t][x].first;
		}
		printf("%lld\n",x+n*c+1);
	}

	return 0;
}
