#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

class Eratosthenes_sieve{
	vector<bool> er;
	vector<int> p;
public:
	Eratosthenes_sieve(int n):er(n+1,true){
		if(n>=0) er[0]=false;
		if(n>=1) er[1]=false;
		for(int i=2;i*i<=n;i++) if(er[i]) for(int j=i*i;j<=n;j+=i) er[j]=false;
		rep(i,n+1) if(er[i]) p.emplace_back(i);
	}

	vector<int> primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}
};

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
	int n; scanf("%d",&n);
	vector<int> a(n+1);
	for(int i=n;i>=0;i--) scanf("%d",&a[i]);

	Eratosthenes_sieve E(n);

	vector<lint> ans;
	for(int p:E.primes()) if(a[0]%p==0) {
		vector<int> b(p);
		for(int i=1;i<=n;i++){
			int i2=(i-1)%(p-1)+1;
			b[i2]=(b[i2]+a[i])%p;
		}
		if(count(b.begin(),b.end(),0)==p){
			ans.emplace_back(p);
		}
	}

	int g=0;
	rep(i,n+1) g=gcd(g,a[i]);
	if(g!=0){
		for(lint p:prime_factors(g)) if(p>n) ans.emplace_back(p);
	}

	for(lint p:ans) printf("%lld\n",p);

	return 0;
}
