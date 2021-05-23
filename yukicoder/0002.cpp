#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int n; cin>>n;

	int g=0;
	for(auto q:prime_factorize(n)) g^=q.second;
	puts(g!=0?"Alice":"Bob");

	return 0;
}
