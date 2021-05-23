#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<lint> d(n);
	rep(i,n-1) scanf("%lld",&d[i+1]);

	rep(i,n-1) if(abs(d[i]-d[i+1])>=L) {
		puts("-1");
		return 0;
	}

	L*=2;
	rep(i,n) d[i]*=2;

	vector<int> x(n);
	rep(i,n) x[i]=d[i]+L/2;

	int ans=0;
	lint sum=x[n-1];
	for(int i=n-2;i>=0;i--){
		if(sum<=(n-i-1)*d[i+1] || (n-i-1)*(d[i+1]+L)<=sum
		|| sum<=(n-i-1)*d[ i ] || (n-i-1)*(d[ i ]+L)<=sum){
			ans++;
		}
		sum+=x[i];
	}
	printf("%d\n",ans);

	return 0;
}
