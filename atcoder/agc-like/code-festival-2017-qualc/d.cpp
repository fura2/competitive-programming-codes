#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	map<int,int> dp;
	dp[0]=0;
	int cum=0;
	rep(i,n){
		cum^=1<<(s[i]-'a');

		int res=INF;
		if(dp.count(cum)>0) res=dp[cum]+1;
		rep(c,26){
			int cum2=cum^(1<<c);
			if(dp.count(cum2)>0) res=min(res,dp[cum2]+1);
		}

		if(dp.count(cum)==0){
			dp[cum]=res;
		}
		else{
			dp[cum]=min(dp[cum],res);
		}

		if(i==n-1) printf("%d\n",res);
	}

	return 0;
}
