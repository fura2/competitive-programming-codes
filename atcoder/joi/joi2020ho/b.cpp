#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	int sum[3][200001]={};
	rep(c,3) rep(i,n) sum[c][i+1]=sum[c][i]+(s[i]=="JOI"[c]?1:0);

	int ans=n;
	rep(i,n) if(s[i]=='J') {
		// J : s[i,x)
		int x=lower_bound(sum[0]+i,sum[0]+n+1,sum[0][i]+k)-sum[0];
		if(x>n) continue;

		// O : s[x,y)
		int y=lower_bound(sum[1]+x,sum[1]+n+1,sum[1][x]+k)-sum[1];
		if(y>n) continue;

		// I : s[y,z)
		int z=lower_bound(sum[2]+y,sum[2]+n+1,sum[2][y]+k)-sum[2];
		if(z>n) continue;

		ans=min(ans,z-i-3*k);
	}
	printf("%d\n",ans<n?ans:-1);

	return 0;
}
