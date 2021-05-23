#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	lint d=0;
	rep(i,n) d+=a[i]-b[i];

	if(n==2){
		if(d==0){
			printf("%d\n",abs(a[0]-b[0]));
		}
		else{
			puts("-1");
		}
		return 0;
	}
	if(d<0 || d%(n-2)!=0) return puts("-1"),0;

	lint k=d/(n-2);
	rep(i,n) if(b[i]-a[i]+k<0 || (b[i]-a[i]+k)%2!=0) return puts("-1"),0;
	printf("%lld\n",k);

	return 0;
}
