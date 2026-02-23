#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	bool dp[1001]={};
	dp[0]=dp[58]=dp[136]=true;
	for(int x:{25,39,51,76,163,111,128,133,138}){
		for(int y=1000;y>=x;y--) if(dp[y-x]) dp[y]=true;
	}
	rep(x,1001) if(dp[x]) printf("%d\n",x);

	return 0;
}
