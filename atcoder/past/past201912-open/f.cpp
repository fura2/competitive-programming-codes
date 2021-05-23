#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	vector<string> D;
	int pre=-1;
	rep(i,s.length()) if(isupper(s[i])) {
		if(pre==-1) pre=i;
		else{
			D.emplace_back(s.substr(pre,i-pre+1));
			pre=-1;
		}
	}

	for(auto& s:D){
		s[0]=tolower(s[0]);
		s.back()=tolower(s.back());
	}

	sort(D.begin(),D.end());

	for(auto& s:D){
		s[0]=toupper(s[0]);
		s.back()=toupper(s.back());
	}

	for(auto& s:D) cout<<s;
	cout<<'\n';

	return 0;
}
