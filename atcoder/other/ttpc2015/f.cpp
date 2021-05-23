#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int n;
string s;

int memo[101][2];

int dfs(int i,int carry){
	if(i==-1){
		return 0;
	}

	int& res=memo[i][carry];
	if(res!=-1) return res;

	res=0;
	int a=s[i]-'0';
	rep(d,10){
		res=max(res,dfs(i-1,(d+a+carry)/10)+(d==a&&d==(d+a+carry)%10?1:0));
	}
	return res;
}

int main(){
	cin>>s;
	n=s.length();

	memset(memo,-1,sizeof memo);
	cout<<dfs(n-1,0)<<'\n';

	return 0;
}
