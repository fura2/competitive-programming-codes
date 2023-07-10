#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool dfs(string s){
	if(s=="AKIHABARA") return true;
	if(s.length()>=9) return false;
	rep(i,s.length()+1) if(dfs(s.substr(0,i)+"A"+s.substr(i))) return true;
	return false;
}

int main(){
	string s; cin>>s;
	puts(dfs(s)?"YES":"NO");
	return 0;
}
