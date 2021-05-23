// OEIS A002326

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modpow(lint a,lint k,int m){
	lint r=1%m;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

lint phi(lint a){
	lint res=a;
	for(lint p=2;p*p<=a;p++) if(a%p==0) {
		res=res/p*(p-1);
		do{ a/=p; }while(a%p==0);
	}
	if(a>1) res=res/a*(a-1);
	return res;
}

void solve(){
	int n; scanf("%d",&n);
	for(lint d:divisors(phi(2*n-1))){
		if(modpow(2,d,2*n-1)==1%(2*n-1)){
			printf("%lld\n",d);
			break;
		}
	}
}

int main(){
// experiment
/*
	for(int n=1;n<30;n++){
		auto f=[&](vector<int> p){
			vector<int> q(2*n);
			rep(i,n){
				q[2*i]=p[i];
				q[2*i+1]=p[n+i];
			}
			return q;
		};

		vector<int> p(2*n);
		iota(p.begin(),p.end(),0);
		auto p0=p;
		int cnt=0;
		while(1){
			p=f(p);
			cnt++;
			if(p==p0) break;
		}
		printf("n = %2d: %d\n",n,cnt);
	}
*/
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
