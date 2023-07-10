#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) scanf("%lld",&b[i]);

	if(accumulate(a.begin(),a.end(),0LL)<accumulate(b.begin(),b.end(),0LL)){
		puts("-1");
		return 0;
	}

	int ans=0;
	lint sum=0;
	vector<lint> c;
	rep(i,n){
		if(a[i]<b[i]){
			sum+=b[i]-a[i];
			ans++;
		}
		else{
			c.emplace_back(a[i]-b[i]);
		}
	}

	sort(c.rbegin(),c.rend());

	rep(i,c.size()) if(sum>0) sum-=c[i], ans++;

	printf("%d\n",ans);

	return 0;
}
