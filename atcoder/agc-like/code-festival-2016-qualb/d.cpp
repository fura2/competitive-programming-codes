#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=a[0]-1;
	int x=2;
	for(int i=1;i<n;i++){
		if(a[i]==x){
			x++;
		}
		else if(a[i]>x){
			ans+=(a[i]-1)/x;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
