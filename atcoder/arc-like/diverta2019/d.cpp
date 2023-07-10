#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

int main(){
	lint n; scanf("%lld",&n);

	lint ans=0;
	for(lint d:divisors(n)){
		lint m=d-1;
		if(n/d<m) ans+=m;
	}
	printf("%lld\n",ans);

	return 0;
}
