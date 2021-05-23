#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<lint> solve(vector<lint> a){
	int n=a.size()+1;

	vector<lint> cum(n),cum_max(n);
	rep(i,n-1){
		cum[i+1]=cum_max[i+1]=cum[i]+a[i];
	}
	for(int i=n-2;i>=0;i--){
		cum_max[i]=max(cum_max[i],cum_max[i+1]);
	}

	vector<lint> res(n);
	rep(i,n){
		res[i]=cum_max[i]-cum[i];
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n-1);
	rep(i,n-1) scanf("%lld",&a[i]);

	auto res1=solve(a);
	reverse(a.begin(),a.end());
	auto res2=solve(a);

	rep(i,n) printf("%lld\n",max(res1[i],res2[n-i-1]));

	return 0;
}
