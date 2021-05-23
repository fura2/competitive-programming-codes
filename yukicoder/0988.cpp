#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m;
	lint k;
	char op;
	cin>>n>>m>>k>>op;
	vector<lint> b(m),a(n);
	rep(j,m) scanf("%lld",&b[j]), b[j]%=k;
	rep(i,n) scanf("%lld",&a[i]), a[i]%=k;

	lint sum1=accumulate(a.begin(),a.end(),0LL)%k;
	lint sum2=accumulate(b.begin(),b.end(),0LL)%k;

	lint ans=0;
	if(op=='+') ans=(m*sum1+n*sum2)%k;
	else        ans=sum1*sum2%k;
	printf("%lld\n",ans);

	return 0;
}
