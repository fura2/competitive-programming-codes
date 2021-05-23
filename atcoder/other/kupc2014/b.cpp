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

int ask(int n){
	printf("? %d\n",n);
	fflush(stdout);
	char res[2];
	scanf("%s",&res);
	return res[0];
}

int main(){
	Eratosthenes_sieve E(1000);

	int ans=1;
	for(auto p:E.primes()){
		int x=p;
		while(x<=1000){
			if(ask(x)=='Y') x*=p;
			else            break;
		}
		ans*=x/p;
	}
	printf("! %d\n",ans);
	fflush(stdout);

	return 0;
}
