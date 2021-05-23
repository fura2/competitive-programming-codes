#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=INT_MAX;
	rep(i,n/2){
		ans=min(ans,abs(a[i]-a[n/2+1+i]));
	}
	printf("%d\n",ans);

	return 0;
}
