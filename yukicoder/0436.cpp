#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans=0;
	rep(i,n-2) if(s[i]=='c' && s[i+1]=='c' && s[i+2]=='w') ans=max(ans,min(i+1,n-i-2));
	printf("%d\n",ans);

	return 0;
}
