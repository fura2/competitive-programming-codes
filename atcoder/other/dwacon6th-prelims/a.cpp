#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,t[50];
	string s[50],x;

	cin>>n;
	rep(i,n) cin>>s[i]>>t[i];
	cin>>x;

	rep(i,n) if(s[i]==x) cout<<accumulate(t+i+1,t+n,0)<<'\n';

	return 0;
}
