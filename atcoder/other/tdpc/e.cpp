#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MOD=1e9+7;

int d,n;
string s;

bool vis[10001][2];
int memo[10001][2][100];

void dfs(int i,bool sat){
	if(i==n){
		memo[n][sat][0]=1;
		return;
	}

	if(vis[i][sat]) return;
	vis[i][sat]=true;

	rep(a,10){
		if(sat && s[i]<a+'0') break;
		bool sat2=(sat && s[i]==a+'0');
		dfs(i+1,sat2);
		rep(j,d) (memo[i][sat][(j+a)%d]+=memo[i+1][sat2][j])%=MOD;
	}
}

int main(){
	cin>>d>>s;
	n=s.length();

	dfs(0,true);
	cout<<(memo[0][true][0]-1+MOD)%MOD<<endl;

	return 0;
}
