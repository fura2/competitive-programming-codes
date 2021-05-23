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
	lint n; cin>>n;

	lint mn=n;
	auto D=divisors(n);
	rep(i,D.size()) for(int j=i;j<D.size();j++) {
		lint x=n/D[i];
		if(x/D[j]<D[j]) break;
		if(x%D[j]==0){
			mn=min(mn,(D[i]-1)+(D[j]-1)+(x/D[j]-1));
		}
	}
	printf("%lld %lld\n",mn,n-1);

	return 0;
}
