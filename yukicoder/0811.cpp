#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

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

int main(){
	int n,k; scanf("%d%d",&n,&k);

	int ans=-1,d_ans=0;
	auto pf=prime_factorize(n);
	for(int i=1;i<n;i++){
		auto qf=prime_factorize(i);
		int cnt=0;
		for(auto x:pf) if(qf.count(x.first)>0) cnt+=min(x.second,qf[x.first]);
		if(cnt>=k){
			int d=divisors(i).size();
			if(d_ans<d){
				d_ans=d;
				ans=i;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
