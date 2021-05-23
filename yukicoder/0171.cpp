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

int main(){
	linear_sieve LS(1000);

	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;

	int cnt[1000]={};
	for(int i=2;i<=s.length();i++){
		for(auto q:LS.prime_factorize(i)){
			cnt[q.first]+=q.second;
		}
	}
	rep(c,128) for(int i=2;i<=hist[c];i++) {
		for(auto q:LS.prime_factorize(i)){
			cnt[q.first]-=q.second;
		}
	}

	int ans=1;
	rep(i,1000) rep(j,cnt[i]) ans=ans*i%573;
	ans=(ans-1+573)%573;
	printf("%d\n",ans);

	return 0;
}
