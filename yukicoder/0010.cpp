#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool solve(const vector<int>& a,int total){
	int n=a.size();
	static bool dp[50][100001];
	rep(i,n) rep(x,total+1) dp[i][x]=false;
	dp[0][a[0]]=true;
	rep(i,n-1) rep(x,total+1) if(dp[i][x]) {
		if(x+a[i+1]<=total) dp[i+1][x+a[i+1]]=true;
		if(x*a[i+1]<=total) dp[i+1][x*a[i+1]]=true;
	}
	return dp[n-1][total];
}

int main(){
	int n,total; scanf("%d%d",&n,&total);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	string ans;
	rep(i,n-1){
		for(char c:{'+','*'}){
			ans+=c;

			bool ok=true;
			vector<int> b(n-i-1);
			b[0]=a[0];
			rep(j,i+1){
				if(ans[j]=='+') b[0]+=a[j+1];
				else            b[0]*=a[j+1];
				if(b[0]>total){ ok=false; break; }
			}
			rep(j,n-i-2) b[j+1]=a[j+i+2];

			if(ok && solve(b,total)) break;

			ans.pop_back();
		}
	}
	puts(ans.c_str());

	return 0;
}
