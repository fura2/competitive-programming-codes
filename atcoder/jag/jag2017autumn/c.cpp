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
	Eratosthenes_sieve E(32000);

	int l,r; scanf("%d%d",&l,&r); r++;

	vector<int> cnt(r-l),t(r-l);
	for(int x=l;x<r;x++) t[x-l]=x;
	for(int p:E.primes()){
		for(int x=(l+p-1)/p*p;x<r;x+=p){
			do{
				cnt[x-l]++;
				t[x-l]/=p;
			}while(t[x-l]%p==0);
		}
	}
	for(int x=l;x<r;x++) if(t[x-l]>=2) cnt[x-l]++;

	int ans=0;
	for(int x=l;x<r;x++) if(E.is_prime(cnt[x-l])) ans++;
	printf("%d\n",ans);

	return 0;
}
