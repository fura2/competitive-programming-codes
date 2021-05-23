// Day 1: Factorial

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
	lint n; cin>>n;
	auto pf=prime_factorize(n);

	lint lo=0,hi=n;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		bool ok=true;
		for(auto q:pf){
			lint cnt=0;
			for(lint pw=q.first;pw<=mi;pw*=q.first){
				cnt+=mi/pw;
			}
			if(cnt<q.second){
				ok=false;
				break;
			}
		}

		if(ok) hi=mi;
		else   lo=mi;
	}
	cout<<hi<<'\n';

	return 0;
}
