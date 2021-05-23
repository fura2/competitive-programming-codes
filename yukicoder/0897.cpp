#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int q; cin>>q;
	rep(_,q){
		lint n,k; cin>>n>>k;
		lint ans=0;
		if(k==1) ans=n-1;
		else{
			lint sum=1;
			while(sum<n){
				sum=k*sum+1;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
