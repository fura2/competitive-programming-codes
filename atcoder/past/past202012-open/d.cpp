#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;
	vector<pair<string,int>> S(n);
	rep(i,n){
		string s; cin>>s;
		int m=s.length();
		rep(j,m+1) if(j==m || s[j]!='0') {
			S[i]=make_pair(s.substr(j),j);
			break;
		}
	}

	sort(S.begin(),S.end(),[&](auto x,auto y){
		if(x.first.length()!=y.first.length()){
			return x.first.length()<y.first.length();
		}
		if(x.first!=y.first) return x.first<y.first;
		return x.second>y.second;
	});

	rep(i,n) cout<<string(S[i].second,'0')<<S[i].first<<'\n';

	return 0;
}
