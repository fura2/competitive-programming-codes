#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q;
	string s; cin>>q>>s;

	int ans=0;
	rep(_,q){
		string t; cin>>t;
		bool ok=false;
		for(int d=1;d<=50;d++){
			rep(i,t.length()){
				if(i+(s.length()-1)*d>=t.length()) break;

				string tmp;
				rep(j,s.length()) tmp+=t[i+j*d];
				if(tmp==s) ok=true;
			}
		}
		if(ok) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
