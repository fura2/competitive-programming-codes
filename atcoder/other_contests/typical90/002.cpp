#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;

void dfs(int i,int dep,string s){
	if(i==n){
		if(dep==0) cout<<s<<'\n';
		return;
	}
	dfs(i+1,dep+1,s+'(');
	if(dep>0) dfs(i+1,dep-1,s+')');
}

int main(){
	cin>>n;
	dfs(0,0,"");
	return 0;
}
