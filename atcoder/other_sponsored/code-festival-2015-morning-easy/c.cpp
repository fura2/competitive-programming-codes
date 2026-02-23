#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	lint m,r; cin>>n>>k>>m>>r;
	vector<lint> a(n-1);
	rep(i,n-1) cin>>a[i];

	sort(a.rbegin(),a.rend());

	lint ans;
	if(k<n){
		lint sum=0;
		rep(i,k) sum+=a[i];
		if(sum>=r*k){
			ans=0;
		}
		else{
			sum-=a[k-1];
			ans=r*k-sum;
		}
	}
	else{
		lint sum=0;
		rep(i,n-1) sum+=a[i];
		if(sum>=r*k){
			ans=0;
		}
		else{
			ans=r*k-sum;
		}
	}
	cout<<(ans<=m?ans:-1)<<'\n';

	return 0;
}
