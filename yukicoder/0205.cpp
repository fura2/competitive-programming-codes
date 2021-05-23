#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int m=0;
	vector<string> s(n);
	rep(i,n){
		cin>>s[i];
		m+=s[i].length();
		s[i]+='z'+1;
	}

	string ans;
	rep(_,m){
		int i=min_element(s.begin(),s.end())-s.begin();
		ans+=s[i][0];
		s[i].erase(0,1);
	}
	cout<<ans<<'\n';

	return 0;
}
