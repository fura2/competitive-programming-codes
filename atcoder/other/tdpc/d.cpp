#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	lint d; cin>>n>>d;

	int cnt[3]={};
	while(d%2==0) d/=2, cnt[0]++;
	while(d%3==0) d/=3, cnt[1]++;
	while(d%5==0) d/=5, cnt[2]++;

	if(d>1){ cout<<0<<endl; return 0; }

	// dp[t][i][j][k] = ( サイコロを i 回振った出目の積が gcd(2^i*3^j*5^k, d) になる確率 )
	static double dp[101][60][40][30];
	dp[0][0][0][0]=1;
	rep(t,n){
		rep(i,cnt[0]+1) rep(j,cnt[1]+1) rep(k,cnt[2]+1) {
			int i2,j2,k2;
			// 1
			i2=i; j2=j; k2=k;
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
			// 2
			i2=min(i+1,cnt[0]); j2=j; k2=k;
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
			// 3
			i2=i; j2=min(j+1,cnt[1]); k2=k;
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
			// 4
			i2=min(i+2,cnt[0]); j2=j; k2=k;
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
			// 5
			i2=i; j2=j; k2=min(k+1,cnt[2]);
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
			// 6
			i2=min(i+1,cnt[0]); j2=min(j+1,cnt[1]); k2=k;
			dp[t+1][i2][j2][k2]+=dp[t][i][j][k]/6;
		}
	}
	cout<<setprecision(9)<<dp[n][cnt[0]][cnt[1]][cnt[2]]<<endl;

	return 0;
}
