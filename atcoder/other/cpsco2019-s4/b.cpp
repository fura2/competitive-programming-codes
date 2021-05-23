#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; cin>>n>>d;
	vector<string> s(d);
	rep(i,d) cin>>s[i];

	int ans=0;
	rep(i,d) for(int j=i+1;j<d;j++) {
		int cnt=0;
		rep(k,n) if(s[i][k]=='o' || s[j][k]=='o') cnt++;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
