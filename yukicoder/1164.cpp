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

const int MOD=1e9+7;

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int main(){
	int a,b,n; scanf("%d%d%d",&a,&b,&n);

	Eratosthenes_sieve E(b);

	int ans=1;
	for(auto p:E.primes()){
		lint k=0;
		for(lint q=p;q<=b;q*=p){
			k+=modpow(b/q-(a-1)/q,n,MOD-1);
		}
		k%=MOD-1;
		ans=ans*modpow(p,k,MOD)%MOD;
	}
	printf("%d\n",ans);

	return 0;
}
