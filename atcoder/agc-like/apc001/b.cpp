#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	lint asum=0,bsum=0;
	rep(i,n){
		asum+=a[i];
		bsum+=b[i];
	}

	if(asum>bsum) return puts("No"),0;

	lint k1=0,k2=0;
	rep(i,n){
		if(a[i]>b[i]){
			k2+=a[i]-b[i];
		}
		else if(a[i]<b[i]){
			if((b[i]-a[i])%2==0){
				k1+=(b[i]-a[i])/2;
			}
			else{
				k1+=(b[i]-a[i]+1)/2;
				k2++;
			}
		}
	}

	lint m=bsum-asum;
	if(k1<=m && k2<=m && 2*(m-k1)==m-k2){
		puts("Yes");
	}
	else puts("No");

	return 0;
}
