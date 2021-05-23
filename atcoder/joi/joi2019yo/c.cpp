#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	int ans=0;
	rep(i,n-1) if(s[i]!=s[i+1]) ans++, i++;
	printf("%d\n",ans);
	return 0;
}
