#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;

void dfs(string s){
	if(s.length()==n){
		puts(s.c_str());
		return;
	}
	char mx=*max_element(s.begin(),s.end());
	for(char c='a';c<=mx+1;c++) dfs(s+c);
}

int main(){
	cin>>n;
	dfs("a");
	return 0;
}
