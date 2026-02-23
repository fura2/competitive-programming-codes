#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(vector<string> B,int a,int b){
	int h=B.size(),w=B[0].length();

	int ans=0;

	int cnt1=0;
	rep(i,h/2) rep(j,w) if(B[i][j]!=B[h-i-1][j]) {
		B[i][j]=B[h-i-1][j]='.';
		cnt1++;
	}
	if(cnt1>0) ans+=a;

	int cnt2=0;
	rep(j,w/2) rep(i,h) if(B[i][j]!=B[i][w-j-1]) {
		B[i][j]=B[i][w-j-1]='.';
		cnt2++;
	}
	ans+=cnt2/2*a;
	if(cnt1+cnt2>0) ans+=b;

	int cnt3=0;
	rep(i,h) rep(j,w) if(B[i][j]=='S') cnt3++;
	ans+=cnt3/2*max(a,b)+cnt3/4*min(a,b);

	return ans;
}

int main(){
	int h,w,a,b; cin>>h>>w>>a>>b;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector<string> Bt(w,string(h,'?'));
	rep(i,h) rep(j,w) Bt[j][i]=B[i][j];

	printf("%d\n",max(solve(B,a,b),solve(Bt,b,a)));

	return 0;
}
