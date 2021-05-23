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

int main(){
	lint n,L; cin>>n>>L;

	lint ans=0;
	for(int p:Eratosthenes_sieve(L).primes()){
		if(p*(n-1)<=L){
			ans+=L-p*(n-1)+1;
		}
	}
	cout<<ans<<'\n';

	return 0;
}
