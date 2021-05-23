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

	int number_of_divisors(int a)const{
		assert(a<=(int)lpf.size()-1);
		int res=1,cnt=0,pre=-1;
		for(;a>1;a/=lpf[a]){
			if(pre==-1 || pre==lpf[a]){
				cnt++;
			}
			else{
				res*=cnt+1;
				cnt=1;
			}
			pre=lpf[a];
		}
		return res*(cnt+1);
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
	linear_sieve LS(1e6);

	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	vector<int> dp(n);
	rep(i,n){
		dp[i]=1;
		for(int d:divisors(LS.prime_factorize(a[i]))) if(d<a[i]) {
			int idx=lower_bound(a.begin(),a.end(),d)-a.begin();
			if(idx<a.size() && a[idx]==d){
				dp[i]=max(dp[i],dp[idx]+1);
			}
		}
	}
	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
