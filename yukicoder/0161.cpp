#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int f(int i,int j){
	if((i+1)%3==j) return 3;
	else if(i==j)  return 1;
	else return 0;
}

string s;
int memo[301][301][301];

int dfs(int g,int c,int p){
	if(g==0 && c==0 && p==0) return 0;

	if(memo[g][c][p]!=-1) return memo[g][c][p];

	int op;
	if(s[s.length()-g-c-p]=='G') op=0;
	if(s[s.length()-g-c-p]=='C') op=1;
	if(s[s.length()-g-c-p]=='P') op=2;

	int res=0;
	if(g>0) res=max(res,dfs(g-1,c,p)+f(0,op));
	if(c>0) res=max(res,dfs(g,c-1,p)+f(1,op));
	if(p>0) res=max(res,dfs(g,c,p-1)+f(2,op));
	return memo[g][c][p]=res;
}

int main(){
	int g,c,p;
	cin>>g>>c>>p>>s;

	memset(memo,-1,sizeof memo);
	cout<<dfs(g,c,p)<<'\n';

	return 0;
}
