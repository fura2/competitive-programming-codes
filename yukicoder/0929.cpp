#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	queue<int> Z;
	rep(i,n) if(a[i]==0) Z.push(i);

	lint ans=0;
	rep(i,n) if(a[i]>0) {
		while(a[i]>=2){
			ans+=abs(i-Z.front());
			Z.pop();
			a[i]--;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
