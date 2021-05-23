#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int MOD=1e9+7;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	if(count(a.begin(),a.end(),0)>0){
		puts("-1");
		return 0;
	}

	lint ans=1;
	rep(i,n) if(a[i]>1) {
		lint fact=1;
		rep(j,a[i]){
			fact*=j+1;
			if(fact>100) break;
		}
		if(fact>100){
			ans=MOD+1;
			break;
		}

		rep(j,fact){
			if(ans>MOD) break;
			ans*=a[i];
		}
	}
	printf("%lld\n",MOD%ans);

	return 0;
}
