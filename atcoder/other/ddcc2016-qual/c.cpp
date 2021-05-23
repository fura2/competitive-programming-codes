#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint k; scanf("%d%lld",&n,&k);

	map<lint,lint> freq;
	rep(i,n){
		lint a; scanf("%lld",&a);
		++freq[gcd(a,k)];
	}

	lint ans=0;
	for(auto [x1,c1]:freq) for(auto [x2,c2]:freq) {
		if(x1*x2%k==0){
			ans+=c1*c2;
			if(x1==x2) ans-=c1;
		}
	}
	ans/=2;
	printf("%lld\n",ans);

	return 0;
}
