#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m,k;
	lint e; scanf("%d%d%d%lld",&n,&m,&k,&e);
	vector<lint> a(n),b(m);
	rep(i,n) scanf("%lld",&a[i]);
	rep(j,m) scanf("%lld",&b[j]);

	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());
	b.erase(b.begin()+k,b.end());

	lint asum=accumulate(a.begin(),a.end(),0LL);
	lint bsum=accumulate(b.begin(),b.end(),0LL);

	if(e+bsum<asum){
		int i;
		lint sum=0;
		for(i=0;i<n;i++){
			sum+=a[i];
			if(e+bsum<sum) break;
		}
		printf("No\n%d\n",i);
	}
	else{
		int j;
		lint sum=0;
		for(j=0;j<k;j++){
			sum+=b[j];
			if(e+sum>=asum) break;
		}
		printf("Yes\n%d\n",j+1);
	}

	return 0;
}
