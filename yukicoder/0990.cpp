#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

vector<long long> divisors(long long a){
	vector<long long> res;
	for(long long i=1;i*i<=a;i++) if(a%i==0) {
		res.emplace_back(i);
		if(i*i<a) res.emplace_back(a/i);
	}
	sort(res.begin(),res.end());
	return res;
}

int main(){
	int n,m;
	lint k;
	char op; cin>>n>>m>>k>>op;
	vector<lint> b(m),a(n);
	rep(j,m) scanf("%lld",&b[j]), b[j]%=k;
	rep(i,n) scanf("%lld",&a[i]), a[i]%=k;

	sort(b.begin(),b.end());

	lint ans=0;
	if(op=='+'){
		rep(i,n){
			auto p=equal_range(b.begin(),b.end(),(k-a[i])%k);
			ans+=p.second-p.first;
		}
	}
	else{
		auto D=divisors(k);
		vector<lint> cnt1(D.size()),cnt2(D.size());
		rep(i,n){
			a[i]=gcd(a[i],k);
			cnt1[lower_bound(D.begin(),D.end(),a[i])-D.begin()]++;
		}
		rep(j,m){
			b[j]=gcd(b[j],k);
			cnt2[lower_bound(D.begin(),D.end(),b[j])-D.begin()]++;
		}
		rep(i,D.size()) rep(j,D.size()) if(D[i]*D[j]%k==0) ans+=cnt1[i]*cnt2[j];
	}
	printf("%lld\n",ans);

	return 0;
}
