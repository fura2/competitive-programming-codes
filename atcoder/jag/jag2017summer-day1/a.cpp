#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;

	lint ans=0;
	if(n<=52){
		ans+=n/2*3+n%2;
	}
	else{
		ans+=26+2*26;
		n-=52;
		if(n<=26*26-26){
			ans+=2*n;
		}
		else{
			ans+=2*(26*26-26);
			n-=26*26-26;
			lint x=26*26*26;
			for(int i=3;n>0;i++){
				ans+=i*min(n,x);
				n-=x;
				x*=26;
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}
