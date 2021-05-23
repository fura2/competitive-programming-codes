#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;
using lint=long long;

map<long long,int> prime_factorize(long long a){
	map<long long,int> res;
	if(a%2==0){
		int cnt=0;
		do{ cnt++; a/=2; }while(a%2==0);
		res.emplace(2,cnt);
	}
	for(long long p=3;p*p<=a;p+=2) if(a%p==0) {
		int cnt=0;
		do{ cnt++; a/=p; }while(a%p==0);
		res.emplace(p,cnt);
	}
	if(a>1) res.emplace(a,1);
	return res;
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

template<class T>
T xgcd(T a,T b,T& x,T& y){
	if(b==0){ x=1; y=0; return a; }
	T g=xgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

pair<long long,long long> Chinese_remainder(vector<long long> a,vector<long long> b,vector<long long> m){
	int n=a.size();
	assert(n==b.size() && n==m.size());

	long long x=0,M=1;
	rep(i,n){
		a[i]%=m[i]; if(a[i]<0) a[i]+=m[i];
		b[i]%=m[i]; if(b[i]<0) b[i]+=m[i];
		if(a[i]==0){
			if(b[i]!=0) return {-1,-1};
			continue;
		}

		long long p,q,g;
		g=xgcd(a[i],m[i],p,q);
		if(b[i]%g!=0) return {-1,-1};
		m[i]/=g;
		b[i]=(b[i]/g)*p%m[i];

		g=xgcd(M,m[i],p,q);
		if((b[i]-x)%g!=0) return {-1,-1};
		x+=M*((b[i]-x)/g*p%(m[i]/g));
		M*=m[i]/g;
	}
	x%=M; if(x<0) x+=M;
	return {x,M};
}

const long long INF=1LL<<61;

int main(){
	lint n; cin>>n;

	lint ans=LLONG_MAX;
	for(auto d:divisors(prime_factorize(2*n))){
//		vector<lint> a={1,1};
		vector<lint> b={0,2*n/d-1};
		vector<lint> m={d,2*n/d};
//		auto tmp=Chinese_remainder(a,b,m);
		auto tmp=crt(b,m);
		if(tmp.first!=0 || tmp.second!=0){
//		if(tmp.first!=-1){
			ans=min(ans,tmp.first==0?tmp.second:tmp.first);
		}
	}
	printf("%lld\n",ans);

	return 0;
}
