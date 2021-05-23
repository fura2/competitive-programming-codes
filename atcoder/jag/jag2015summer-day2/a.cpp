#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<long long> prime_factors(long long a){
	vector<long long> res;
	if(a%2==0){
		do a/=2; while(a%2==0);
		res.emplace_back(2);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		do a/=p; while(a%p==0);
		res.emplace_back(p);
	}
	if(a>1) res.emplace_back(a);
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int p,q; scanf("%d%d",&p,&q);

	int ans=1;
	for(auto a:prime_factors(q/gcd(p,q))) ans*=a;
	printf("%d\n",ans);

	return 0;
}
