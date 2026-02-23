#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,tar; cin>>n>>tar;

	string ans="kogakubu10gokan";
	rep(i,n){
		int y;
		string s; cin>>y>>s;
		if(tar<y) break;
		ans=s;
	}
	cout<<ans<<'\n';

	return 0;
}
