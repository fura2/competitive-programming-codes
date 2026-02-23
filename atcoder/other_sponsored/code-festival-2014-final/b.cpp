#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int ans=0;
	rep(i,s.length()) ans+=(i%2==0?1:-1)*(s[i]-'0');
	printf("%d\n",ans);
	return 0;
}
