#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);

// experiment
/*
	vector<lint> p(n);
	iota(p.begin(),p.end(),1);
	lint ans=1e7;
	vector<lint> pans;
	do{
		lint cost=0;
		rep(i,n) cost+=p[i]*p[(i+1)%n];
		if(ans>cost){
			ans=cost;
			pans=p;
		}
	}while(next_permutation(p.begin(),p.end()));

	cout<<ans<<endl;
	rep(i,n) cout<<pans[i]<<" "; cout<<endl;
*/

	if(n==1) return puts("0"),0;

	vector<lint> p(n);
	int a=1,b=n,l=0,r=n-1;
	for(bool f=true;l<=r;f=!f){
		if(f) p[l]=a, p[r]=b;
		else  p[l]=b, p[r]=a;
		a++;
		b--;
		l++;
		r--;
	}

	lint ans=0;
	rep(i,n) ans+=p[i]*p[(i+1)%n];
	printf("%lld\n",ans);

	return 0;
}
