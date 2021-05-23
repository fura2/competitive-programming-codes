#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void dfs(string s,string t,set<string>& S){
	if(s.empty()){
		S.emplace(t);
		return;
	}
	int n=s.length();
	dfs(s.substr(1),t+s[0],S);
	dfs(s.substr(0,n-1),t+s[n-1],S);
}

int main(){
	string s,t; cin>>s;
	set<string> S;
	dfs(s,t,S);
	cout<<S.size()<<'\n';
	return 0;
}
