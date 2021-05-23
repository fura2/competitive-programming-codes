#include <bits/stdc++.h>
#include "grader.h"

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
		rep(i,n+1) if(er[i]) p.push_back(i);
	}

	vector<int> primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}
};

Eratosthenes_sieve ES(40000);

void taro(int n){
	vector<int> p=ES.primes();

	rep(i,p.size()) if(n!=p[i] && n%p[i]==0) {
		rep(b,12) send(i>>b&1);
		return;
	}

	rep(b,12) send(1);
}

int jiro(int m,int* x){
	vector<int> p=ES.primes();

	int res=0;
	rep(b,12) res+=x[b]<<b;
	return res<4095?p[res]:-1;
}
