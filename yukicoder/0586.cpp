#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int p1,p2,n; cin>>p1>>p2>>n;

	int ans=0;
	vector<int> cnt(1000);
	rep(i,n){
		int r; cin>>r;
		cnt[r]++;
		if(cnt[r]>1) ans+=p1+p2;
	}
	cout<<ans<<'\n';

	return 0;
}
