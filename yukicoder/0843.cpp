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

int main(){
	int n; scanf("%d",&n);
	Eratosthenes_sieve E(n);

	int ans=0;
	auto p=E.primes();
	rep(k,p.size()){
		int r=p[k];
		if(r>n || r*r>2*n) break;
		rep(i,p.size()){
			int q=r*r-p[i];
			if(q<=n && E.is_prime(q)) ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
