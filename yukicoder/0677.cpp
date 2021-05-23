#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

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
	int n; scanf("%d",&n);
	map<lint,int> pf;
	pf[2]=n;
	pf[5]=n;
	for(lint d:divisors(pf)) printf("%lld\n",d);
	return 0;
}
