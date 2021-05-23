#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint d; scanf("%d%lld",&n,&d);
	vector<lint> x(n);
	rep(i,n) scanf("%lld",&x[i]);

	lint res1=0;
	rep(j,n){
		int i=lower_bound(x.begin(),x.end(),x[j]-d)-x.begin();
		int k=upper_bound(x.begin(),x.end(),x[j]+d)-x.begin();
		res1+=lint(j-i)*(k-j-1);
	}

	lint res2=0;
	rep(i,n){
		int k=upper_bound(x.begin(),x.end(),x[i]+d)-x.begin();
		res2+=lint(k-i-1)*(k-i-2)/2;
	}

	printf("%lld\n",res1-res2);

	return 0;
}
