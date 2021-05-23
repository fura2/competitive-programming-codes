#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool Miller_Rabin(lint n){
	if(n<=1)   return false;
	if(n%2==0) return n==2;

	auto modpow=[](lint a,lint k,lint m){
		lint r=1;
		for(lint x=a;k>0;k>>=1){
			if(k&1) r=__int128(r)*x%m;
			x=__int128(x)*x%m;
		}
		return r;
	};

	int r=0;
	lint d=n-1;
	while(d%2==0) r++, d>>=1;

	for(lint a:{2,3,5,7,11,13,17,19,23,29,31,37}){
		if(a>=n-2) break;
		lint x=modpow(a,d,n);
		if(x==1 || x==n-1) continue;
		bool b=false;
		rep(_,r-1){
			x=__int128(x)*x%n;
			if(x==n-1){
				b=true;
				break;
			}
		}
		if(!b) return false;
	}
	return true;
}

map<lint,int> Pollard_rho(lint n){
	map<lint,int> pf;
	if(n<=1) return pf;
	if(Miller_Rabin(n)){ ++pf[n]; return pf; }

	auto divisor=[](lint n,int c)->lint{
		if(n%2==0) return 2;

		lint x=2,y=2,d=1;
		while(d==1){
			x=__int128(x)*x%n+c; if(x<0) x+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			y=__int128(y)*y%n+c; if(y<0) y+=n;
			d=gcd(abs(x-y),n);
		}
		return d<n?d:-1;
	};

	lint d=-1;
	for(int c=1;d==-1;c++) d=divisor(n,c);

	for(auto [p,e]:Pollard_rho( d )) pf[p]+=e;
	for(auto [p,e]:Pollard_rho(n/d)) pf[p]+=e;
	return pf;
}

template<class T>
vector<T> divisors(const map<T,int>& pf){
	vector<T> res={T(1)};
	for(const auto& q:pf){
		int m=res.size();
		T pp=1;
		rep(i,q.second){
			pp*=q.first;
			rep(i,m) res.emplace_back(res[i]*pp);
		}
	}
	sort(res.begin(),res.end());
	return res;
}

lint modpow(lint a,lint k,int m){
	lint r=1%m;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int main(){
	int n; scanf("%d",&n);
	map<lint,lint> f;
	rep(i,n){
		lint b,a; scanf("%lld%lld",&b,&a);
		f[b]+=a;
	}
	for(auto it=f.begin();it!=f.end();){
		if(it->second==0){
			it=f.erase(it);
		}
		else{
			++it;
		}
	}

	if(f.empty()){
		puts("Yes 1");
		return 0;
	}

	lint ans=-1;
	for(lint x:divisors(Pollard_rho(abs(f.begin()->second)))){
		const lint MOD1=1e9+7;
		const lint MOD2=1e9+9;

		lint v1=0,v2=0;
		for(auto [i,a]:f){
			v1+=a%MOD1*modpow(x,i,MOD1); v1%=MOD1;
			v2+=a%MOD2*modpow(x,i,MOD2); v2%=MOD2;
		}
		if(v1!=0 || v2!=0) continue;

		v1=v2=0;
		for(auto [i,a]:f) if(i>0) {
			v1+=a%MOD1*i%MOD1*modpow(x,i-1,MOD1); v1%=MOD1;
			v2+=a%MOD2*i%MOD2*modpow(x,i-1,MOD2); v2%=MOD2;
		}
		if(v1!=0 || v2!=0) continue;

		if(ans==-1 || ans>x) ans=x;
	}
	if(ans==-1){
		puts("No");
	}
	else{
		printf("Yes %lld\n",ans);
	}

	return 0;
}
