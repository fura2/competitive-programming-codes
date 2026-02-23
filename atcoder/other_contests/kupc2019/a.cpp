#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x,a[1000]; cin>>n>>x;
	rep(i,n) cin>>a[i];

	int mx=*max_element(a,a+n);

	int ans=0;
	rep(i,n) if(a[i]+x>=mx) ans++;
	cout<<ans<<endl;

	return 0;
}
