#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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
	int a,b; cin>>a>>b;
	for(auto c:divisors(a+b)){
		if(a!=c && b!=c && (a+c)%b==0 && (b+c)%a==0) return printf("%lld\n",c),0;
	}
	puts("-1");
	return 0;
}
