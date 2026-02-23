#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

string s;
lint memo[20][2][2][7];

lint dfs(int i,bool smaller,bool first,int mod){
	if(i==s.length()) return (mod==0?1:0);

	if(memo[i][smaller][first][mod]!=-1) return memo[i][smaller][first][mod];

	lint res=0;
	for(int d=(first?0:1);d<=7;d++) if(smaller || d<=s[i]-'0') {
		res+=dfs(i+1,smaller||d<s[i]-'0',first&&d==0,(10*mod+d)%7);
	}
	return memo[i][smaller][first][mod]=res;
}

int main(){
	cin>>s;
	memset(memo,-1,sizeof memo);
	cout<<dfs(0,false,true,0)-1<<'\n';
	return 0;
}
