#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	bool ok=true;
	rep(i,n-1) if(a[i]>a[i+1]) ok=false;
	if(ok){
		puts("0");
		return 0;
	}

	int l,r;
	rep(i,n-1){
		if(a[i]>a[i+1]){
			l=i+1;
			break;
		}
	}
	for(int i=n-1;i>0;i--){
		if(a[i-1]>a[i]){
			r=i;
			break;
		}
	}

	int ans=a[0]+a[r];
	for(int i=r;i<n;i++){
		if(i==n-1 || a[l-1]<a[i+1]) ans=min(ans,a[l]+a[i]);
	}
	printf("%d\n",ans);

	return 0;
}
