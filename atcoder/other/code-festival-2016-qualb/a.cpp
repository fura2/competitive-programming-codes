#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int ans=0;
	rep(i,16) if(s[i]!="CODEFESTIVAL2016"[i]) ans++;
	printf("%d\n",ans);
	return 0;
}
