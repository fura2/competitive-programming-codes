#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

map<long long,int> prime_factorize(long long a){
	map<long long,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
}

int main(){
	lint n; scanf("%lld",&n);

	auto pf=prime_factorize(n);

	auto dfs=[&](auto&& dfs,auto it,lint a,lint b,lint c){
		if(it==pf.end()){
			return (a<=b&&b<=c?1:0);
		}
		int res=0;
		auto [p,e]=*it;
		rep(i,e+1) rep(j,e-i+1) {
			int k=e-i-j;
			res+=dfs(dfs,next(it),a*pow(p,i),b*pow(p,j),c*pow(p,k));
		}
		return res;
	};

	printf("%lld\n",dfs(dfs,pf.begin(),1,1,1));

	return 0;
}
