#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	lint n,k; cin>>n>>k;
	lint ans=0;
	for(lint d:divisors(k)){
		lint c1,c2;
		if     (d<= n ) c1=d-1;
		else if(d<=2*n) c1=2*n-d+1;
		else            c1=0;
		if     (k/d<= n ) c2=k/d-1;
		else if(k/d<=2*n) c2=2*n-k/d+1;
		else              c2=0;
		ans+=c1*c2;
	}
	cout<<ans<<'\n';
	return 0;
}
