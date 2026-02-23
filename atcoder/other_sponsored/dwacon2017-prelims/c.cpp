#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int cnt[5]={};
	rep(i,n){ int a; scanf("%d",&a); cnt[a]++; }

	int ans=0;
	ans+=cnt[4];
	ans+=cnt[3]; cnt[1]-=min(cnt[1],cnt[3]);
	ans+=cnt[2]/2; cnt[2]%=2;
	if(cnt[2]>0) cnt[1]+=2;
	ans+=(cnt[1]+3)/4;
	cout<<ans<<endl;

	return 0;
}
