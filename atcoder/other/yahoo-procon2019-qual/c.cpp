#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint k,a,b; cin>>k>>a>>b;
	lint ans=k+1;
	if(k>=a-1){
		k-=a-1;
		ans=max(ans,a+k/2*(b-a)+k%2);
	}
	cout<<ans<<'\n';
	return 0;
}
