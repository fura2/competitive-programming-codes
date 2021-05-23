#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

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

	auto pf=prime_factorize(n);
	int m=0;
	for(auto q:pf) m+=q.second;

	if(m<k) return puts("-1"),0;

	vector<int> ans;
	for(auto q:pf){
		rep(_,q.second){
			if(ans.size()<k){
				ans.emplace_back(q.first);
			}
			else{
				ans.back()*=q.first;
			}
		}
	}
	rep(i,k) printf("%d%c",ans[i],i<k-1?' ':'\n');

	return 0;
}
