#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int dfs(string s){
	int n=s.length();

	int res=0;
	rep(i,n) if(s[i]!='0') for(int j=i+1;j<n;j++) if(s[j]!=s[i]) for(int k=j+1;k<n;k++) if(s[k]==s[j]) {
		string t;
		rep(x,n) if(x!=i && x!=j && x!=k) t+=s[x];
		res=max(res,dfs(t)+100*(s[i]-'0')+11*(s[j]-'0'));
	}
	return res;
}

int main(){
	string s; cin>>s;
	cout<<dfs(s)<<'\n';
	return 0;
}
