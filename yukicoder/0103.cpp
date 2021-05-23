#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

Eratosthenes_sieve ES(1e4);

int memo[10001];

int grundy(int a){
	if(memo[a]!=-1) return memo[a];

	if(a==1) return memo[a]=0;

	set<int> S;
	for(int p:ES.primes()){
		if(p>a) break;
		if(a%p==0){
			S.emplace(grundy(a/p));
			if(a%(p*p)==0){
				S.emplace(grundy(a/(p*p)));
			}
		}
	}
	for(memo[a]=0;S.count(memo[a])>0;memo[a]++);
	return memo[a];
}

int main(){
	int n; scanf("%d",&n);

	rep(a,10001) memo[a]=-1;

	int g=0;
	rep(i,n){
		int a; scanf("%d",&a);
		g^=grundy(a);
	}
	puts(g>0?"Alice":"Bob");

	return 0;
}
