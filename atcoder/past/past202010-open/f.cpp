#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; cin>>n>>k; k--;
	map<string,int> freq;
	rep(i,n){
		string s; cin>>s;
		++freq[s];
	}

	vector<pair<int,string>> a,b;
	for(auto p:freq){
		a.emplace_back(p.second,p.first);
		b.emplace_back(p.second,p.first);
	}
	sort(a.begin(),a.end(),[&](auto x,auto y){
		if(x.first!=y.first) return x.first>y.first;
		return x.second<y.second;
	});
	sort(b.begin(),b.end(),[&](auto x,auto y){
		if(x.first!=y.first) return x.first>y.first;
		return x.second>y.second;
	});

	if(a[k]==b[k]) cout<<a[k].second<<'\n';
	else           cout<<"AMBIGUOUS\n";

	return 0;
}
