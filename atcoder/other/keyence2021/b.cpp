#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> freq(n);
	rep(i,n) freq[a[i]]++;

	lint ans=0;
	int num=k;
	rep(i,n){
		num=min(num,freq[i]);
		ans+=num;
	}
	printf("%lld\n",ans);

	return 0;
}
