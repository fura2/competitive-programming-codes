#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	if(n%2==1) return puts("-1"),0;

	int ans=0;
	rep(i,n/2) if(s[i]!=s[n/2+i]) ans++;
	printf("%d\n",ans);

	return 0;
}
