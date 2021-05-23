#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;


int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	vector<int> p(n);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return a[i]<a[j];
	});

	lint bsum=accumulate(b.begin(),b.end(),0LL);
	lint tmp=0;
	for(int i:p){
		tmp+=b[i];
		if(2*tmp>=bsum){
			lint ans=0;
			rep(j,n) ans+=b[j]*abs(a[j]-a[i]);
			printf("%lld %lld\n",a[i],ans);
			break;
		}
	}

	return 0;
}
