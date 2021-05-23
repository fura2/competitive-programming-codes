#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	int ans=0,cnt1=0,cnt2=0,cnt3=0;
	rep(i,n){
		string s; cin>>s;
		int len=s.length();
		rep(j,len-1) if(s[j]=='A' && s[j+1]=='B') ans++;
		if(s[0]=='B' && s[len-1]=='A') cnt1++;
		else if(s[  0  ]=='B') cnt2++;
		else if(s[len-1]=='A') cnt3++;
	}

	ans+=min(cnt2,cnt3);
	if(cnt2+cnt3>0) ans+=cnt1;
	else            ans+=max(cnt1-1,0);

	printf("%d\n",ans);

	return 0;
}
