#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<string,string>> p(n);
	rep(i,n) cin>>p[i].first>>p[i].second;
	sort(p.begin(),p.end());
	rep(i,n) cout<<p[i].first<<' '<<p[i].second<<'\n';
	return 0;
}
