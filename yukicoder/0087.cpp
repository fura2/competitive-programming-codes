#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	lint ans=(n-2014)/400*57;
	for(int i=2015;i<=2014+(n-2014)%400;i++){
		if((i+i/4-i/100+i/400)%7==(2014+2014/4-2014/100+2014/400)%7) ans++;
	}
	cout<<ans<<'\n';

	return 0;
}
