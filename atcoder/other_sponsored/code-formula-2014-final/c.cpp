#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	set<string> ans;
	while(1){
		string s; cin>>s;
		if(s.empty()) break;

		while(!s.empty() && s[0]!='@') s=s.substr(1);
		while(!s.empty() && s[0]=='@'){
			int i;
			for(i=1;i<s.length();i++) if(s[i]=='@') break;
			if(i>=2 && islower(s[1])) ans.emplace(s.substr(1,i-1));
			s=s.substr(i);
		}
	}
	for(string s:ans) cout<<s<<'\n';
	return 0;
}
