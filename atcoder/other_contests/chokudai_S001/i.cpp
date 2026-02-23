#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0,cum=0;
	map<lint,int> f;
	rep(i,n+1){
		++f[cum];
		ans+=f[cum-n];
		if(i<n) cum+=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}
