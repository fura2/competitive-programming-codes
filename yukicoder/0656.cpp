#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int ans=0;
	rep(i,9) ans+=(s[i]=='0'?10:s[i]-'0');
	printf("%d\n",ans);
	return 0;
}
