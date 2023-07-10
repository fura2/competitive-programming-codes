#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string a,b,c; cin>>n>>a>>b>>c;

	int ans=0;
	rep(i,n) ans+=set<char>{a[i],b[i],c[i]}.size()-1;
	cout<<ans<<'\n';

	return 0;
}
