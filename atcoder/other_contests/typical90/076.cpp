#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(2*n);
	rep(i,n) scanf("%lld",&a[i]), a[n+i]=a[i];

	lint total=accumulate(a.begin(),a.begin()+n,0LL);

	lint sum=0;
	for(int l=0,r=0;l<n;l++){
		while(r<2*n && 10*(sum+a[r])<=total) sum+=a[r], r++;
		if(10*sum==total){
			puts("Yes");
			return 0;
		}
		sum-=a[l];
	}
	puts("No");

	return 0;
}
