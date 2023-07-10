#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a[100]; cin>>n;
	rep(i,n) cin>>a[i];

	int sum=accumulate(a,a+n,0);
	int ans=0;
	rep(i,n) if(abs(n*a[i]-sum)<abs(n*a[ans]-sum)) ans=i;
	cout<<ans<<endl;

	return 0;
}
