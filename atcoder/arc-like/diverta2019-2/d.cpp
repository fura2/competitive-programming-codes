#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(lint n,vector<pair<lint,lint>>& d){
	if(d.empty()) return n;

	auto [a,b]=d.back();
	if(d.size()==1) return n+(n/a)*(b-a);

	lint res=n;
	rep(i,n/a+1){
		d.pop_back();
		res=max(res,i*b+solve(n-i*a,d));
		d.emplace_back(a,b);
	}
	return res;
}

int main(){
	int n,a[3],b[3]; cin>>n;
	rep(i,3) cin>>a[i];
	rep(i,3) cin>>b[i];

	vector<pair<lint,lint>> d1,d2;
	rep(i,3){
		if(a[i]<b[i]) d1.emplace_back(a[i],b[i]);
		if(a[i]>b[i]) d2.emplace_back(b[i],a[i]);
	}

	cout<<solve(solve(n,d1),d2)<<'\n';

	return 0;
}
