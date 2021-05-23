#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	lint ans=0,cnt=0;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='w') cnt++;
		if(s[i]=='c') ans+=cnt*(cnt-1)/2;
	}
	cout<<ans<<'\n';

	return 0;
}
