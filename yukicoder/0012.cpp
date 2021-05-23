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

vector<int> f(int a){
	bool fr[10]={};
	for(char c:to_string(a)) fr[c-'0']=true;

	vector<int> res;
	rep(d,10) if(fr[d]) res.emplace_back(d);
	return res;
}

int main(){
	auto p=Eratosthenes_sieve(5e6).primes();

	int n; cin>>n;
	int S=0;
	rep(i,n){ int a; cin>>a; S|=1<<a; }

	int m=p.size(),ans=-1,idx=0,cnt[10]={};
	rep(i,m){
		for(int d:f(p[i])) cnt[d]++;
		int T=0;
		rep(d,10) if(cnt[d]>0) T|=1<<d;

		while(S!=T && (S&T)==S){
			for(int d:f(p[idx])) cnt[d]--;
			T=0;
			rep(d,10) if(cnt[d]>0) T|=1<<d;
			idx++;
		}

		if(S==T){
			int l=(idx==0?1:p[idx-1]+1);
			int r=(i==m-1?5000000:p[i+1]-1);
			ans=max(ans,r-l);
		}
	}
	printf("%d\n",ans);

	return 0;
}
