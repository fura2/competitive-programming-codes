#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using ulint=unsigned long long;

auto basis(const vector<unsigned long long>& a){
	vector<unsigned long long> B;
	for(auto v:a){
		for(const auto& b:B) v=min(v,v^b);
		if(v!=0) B.emplace_back(v);
	}
	return B;
}

bool is_linearly_independent(unsigned long long v,const vector<unsigned long long>& B){
	for(const auto& b:B) v=min(v,v^b);
	return v!=0;
}

int main(){
	int n; scanf("%d",&n);
	vector<ulint> a(n),b(n);
	rep(i,n) scanf("%llu",&a[i]);
	rep(i,n) scanf("%llu",&b[i]);

	auto A=basis(a);
	auto B=basis(b);

	if(A.size()!=B.size()){
		puts("No");
		return 0;
	}

	for(auto a:A) if(is_linearly_independent(a,B)) {
		puts("No");
		return 0;
	}

	puts("Yes");

	return 0;
}
