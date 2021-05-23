#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint v,t,p; cin>>v>>t>>p;

	lint lo=0,hi=LLONG_MAX;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(mi<=(mi-2+t)/t+(p+1)*v) lo=mi;
		else                       hi=mi;
	}
	cout<<lo<<'\n';

	return 0;
}
