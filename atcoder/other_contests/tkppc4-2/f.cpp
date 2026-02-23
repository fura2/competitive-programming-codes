#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<lint> a(n+3);
	rep(i,n) scanf("%lld",&a[i]);

	for(int i=n+2;i>0;i--) a[i]-=a[i-1];
	for(int i=n+2;i>0;i--) a[i]-=a[i-1];
	for(int i=n+2;i>0;i--) a[i]-=a[i-1];

	rep(i,n+3){
		if(a[i]<0) return puts("No"),0;

		lint d=a[i];
		if(i+2*k+1<n+3){
			a[i  ]-=d;
			a[i+1]-=d;
			a[i+k  ]+=4*k*d;
			a[i+k+1]-=4*k*d;
			a[i+2*k  ]+=d;
			a[i+2*k+1]+=d;
		}
		else{
			if(d!=0) return puts("No"),0;
		}
	}
	puts("Yes");

	return 0;
}
