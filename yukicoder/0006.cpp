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

inline int digital_root(long long n,long long base=10){
	if(n==0) return 0;
	else     return n%(base-1)!=0?n%(base-1):base-1;
}

int main(){
	int l,r; cin>>l>>r;
	Eratosthenes_sieve E(r);

	auto p=E.primes();
	rep(i,p.size()) if(p[i]>=l) {
		p.erase(p.begin(),p.begin()+i);
		break;
	}

	int m=p.size(),idx=0,ans=0,ans2=0;
	vector<int> cnt(10);
	rep(i,m){
		int d=digital_root(p[i]);
		while(cnt[d]>0){
			cnt[digital_root(p[idx])]--;
			idx++;
		}
		cnt[d]++;
		if(ans<=i-idx+1){
			ans=i-idx+1;
			ans2=p[idx];
		}
	}
	printf("%d\n",ans2);

	return 0;
}
