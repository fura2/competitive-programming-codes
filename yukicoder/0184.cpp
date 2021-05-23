#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

auto basis(const vector<unsigned long long>& a){
	vector<unsigned long long> B;
	for(auto v:a){
		for(auto b:B) v=min(v,v^b);
		if(v!=0) B.emplace_back(v);
	}
	return B;
}

int main(){
	int n; scanf("%d",&n);
	vector<unsigned long long> a(n);
	rep(i,n) scanf("%llu",&a[i]);

	printf("%lld\n",1LL<<basis(a).size());

	return 0;
}
