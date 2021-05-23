#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	int ans=0;
	rep(i,n) if(s[i]=='U') for(int j=i+1;j<n;j++) if(s[j]=='M') {
		int k=2*j-i;
		if(k<n && s[k]=='G') ans++;
	}
	printf("%d\n",ans);
	return 0;
}
