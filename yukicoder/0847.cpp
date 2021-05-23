#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
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

lint k,m;
map<lint,int> pf;
map<lint,int>::iterator it;

int dfs(lint x){
	if(it==pf.end()) return 1;

	lint p=it->first,q=k*it->second;
	int res=0;
	rep(i,q+1){
		++it;
		res+=dfs(x);
		--it;
		x*=p;
		if(x>m) break;
	}
	return res;
}

int main(){
	lint n; cin>>n>>k>>m;
	pf=prime_factorize(n);
	it=pf.begin();
	cout<<dfs(1)<<'\n';
	return 0;
}
