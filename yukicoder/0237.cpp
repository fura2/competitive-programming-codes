#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint F[]={3,5,17,257,65537}; // Fermat primes

	vector<lint> X;
	rep(S,1<<5){
		lint m=1;
		rep(i,5) if(S>>i&1) m*=F[i];
		if(m>=3) X.emplace_back(m);
		while(m<=1e9){
			m*=2;
			if(m>=3) X.emplace_back(m);
		}
	}

	sort(X.begin(),X.end());

	lint a; scanf("%lld",&a);
	printf("%ld\n",upper_bound(X.begin(),X.end(),a)-X.begin());

	return 0;
}
