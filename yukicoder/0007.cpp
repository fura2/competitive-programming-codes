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

	bool is_prime(int a)const{
		assert(a<=(int)er.size()-1);
		return a>=0 && er[a];
	}

	const vector<int>& primes()const{ return p; }
};

int main(){
	int n; cin>>n;

	auto P=Eratosthenes_sieve(n).primes();

	vector<bool> win(n+1);
	win[0]=win[1]=true;
	rep(i,n+1){
		for(int p:P){
			if(i-p<0) break;
			if(!win[i-p]){ win[i]=true; break; }
		}
	}
	puts(win[n]?"Win":"Lose");

	return 0;
}
