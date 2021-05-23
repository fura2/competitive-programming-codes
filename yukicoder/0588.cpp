#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0;
	rep(i,n){
		int cnt=1;
		for(int d=1;0<=i-d&&i+d<n;d++) if(s[i-d]==s[i+d]) cnt+=2;
		ans=max(ans,cnt);

		cnt=0;
		for(int d=1;0<=i-d&&i+d-1<n;d++) if(s[i-d]==s[i+d-1]) cnt+=2;
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);

	return 0;
}
