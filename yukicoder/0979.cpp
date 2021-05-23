#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

class linear_sieve{
	vector<int> lpf,p;
public:
	linear_sieve(int n):lpf(n+1){
		for(int i=2;i<=n;i++){
			if(lpf[i]==0){
				lpf[i]=i;
				p.emplace_back(i);
			}
			for(int j=0;j<p.size()&&p[j]<=lpf[i]&&i*p[j]<=n;j++) lpf[i*p[j]]=p[j];
		}
	}

	const vector<int>& primes()const{ return p; }

	bool is_prime(int a)const{
		assert(a<=(int)lpf.size()-1);
		return a>0 && lpf[a]==a;
	}

	map<int,int> prime_factorize(int a)const{
		assert(a<=(int)lpf.size()-1);
		map<int,int> pf;
		for(;a>1;a/=lpf[a]) ++pf[lpf[a]];
		return pf;
	}
};

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

int main(){
	linear_sieve LS(300001);

	int n; scanf("%d",&n);

	vector<int> dp(300001);
	rep(i,n){
		int a; scanf("%d",&a);
		dp[a]=max(dp[a],1);
		for(int d:divisors(LS.prime_factorize(a))) if(d<a) dp[a]=max(dp[a],dp[d]+1);
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
