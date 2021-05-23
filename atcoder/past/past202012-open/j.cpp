#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	string s;
	lint L; cin>>s>>L;
	int n=s.length();

	vector<lint> dp(n+1); // dp[i] = (s[0,i) が出力する文字数)
	rep(i,n){
		if(islower(s[i])){
			dp[i+1]=dp[i]+1;
		}
		else{
			dp[i+1]=min(dp[i]*(s[i]-'0'+1),INF);
		}
	}

	rep(i,n) if(dp[i+1]>=L) {
		for(;;i--) if(islower(s[i])) {
			if(L%dp[i+1]==0){
				printf("%c\n",s[i]);
				return 0;
			}
			L%=dp[i+1];
		}
	}

	return 0;
}
