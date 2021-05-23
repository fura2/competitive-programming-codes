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
	Eratosthenes_sieve ES(3e6);

	const auto& P=ES.primes();

	priority_queue<tuple<lint,int,int>> Q;
	Q.emplace(-2*2*2,0,-1);
	rep(i,P.size()-1){
		lint p=P[i],q=P[i+1];
		Q.emplace(-p*q,i,i+1);
	}

	int n; scanf("%d",&n);
	rep(t,n){
		auto [x,i,j]=Q.top(); Q.pop();
		if(t==n-1) printf("%lld\n",-x);
		if(j==-1){ // 三乗数
			lint p=P[i+1];
			Q.emplace(-p*p*p,i+1,-1);
		}
		else{ // 異なる素数の積
			lint p=P[i],q=P[j+1];
			Q.emplace(-p*q,i,j+1);
		}
	}

	return 0;
}
