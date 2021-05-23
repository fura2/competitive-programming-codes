#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=0,pre=0;
	rep(i,n) if(i==n-1 || a[i]>a[i+1]) {
		ans=max(ans,i-pre+1);
		pre=i+1;
	}
	printf("%d\n",ans);

	return 0;
}
