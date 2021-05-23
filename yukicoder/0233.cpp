#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const char* s="inabameguru";
bool used[11];
set<string> res;

bool isvowel(char c){
	return c=='a' || c=='i' || c=='u' || c=='e' || c=='o';
}

void dfs(int S,string t){
	if(S==(1<<11)-1){
		if(isvowel(t.back())) res.emplace(t);
		return;
	}
	rep(i,11) if((S>>i&1)==0) {
		if(t.empty() || isvowel(t.back()) || isvowel(s[i])){
			dfs(S|1<<i,t+s[i]);
		}
	}
}

int main(){
	dfs(0,"");

	int n; cin>>n;
	rep(i,n){
		string t; cin>>t;
		res.erase(t);
	}
	cout<<(res.empty()?"NO":*res.begin())<<'\n';

	return 0;
}
