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
	int n;
	double p; scanf("%d%lf",&n,&p);

	linear_sieve LS(n);

	double ans=0;
	for(int i=2;i<=n;i++){
		ans+=pow(1-p,LS.number_of_divisors(i)-2);
	}
	printf("%.9f\n",ans);

	return 0;
}
