#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	set<string> ans;
	rep(i,n) for(int d=1;d<=3;d++) if(i+d<=n) {
		string t=s.substr(i,d);
		rep(S,1<<d){
			string r=t;
			rep(k,d) if(S>>k&1) r[k]='.';
			ans.emplace(r);
		}
	}
	cout<<ans.size()<<'\n';

	return 0;
}
