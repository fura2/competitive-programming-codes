#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

string normalize(string s){
	if(count(s.begin()+600,s.end(),'9')<400) return s;

	for(int i=999;i>=0;i--) if(s[i]!='.') {
		if(s[i]=='9'){
			s[i]='0';
		}
		else{
			s[i]++;
			return s;
		}
	}
	return "1"+s.substr(0,999);
}

int main(){
	int n; cin>>n;

	set<string> ans;
	rep(_,n){
		string s; cin>>s;
		int l=s.find('('),r=s.find(')');
		if(l==string::npos){
			s+=string(1000-s.length(),'0');
		}
		else{
			string t=s.substr(l+1,r-l-1);
			s=s.substr(0,l);
			while(s.length()<1000) s+=t;
			while(s.length()>1000) s.pop_back();
		}
		ans.emplace(normalize(s));
	}
	cout<<ans.size()<<'\n';

	return 0;
}
