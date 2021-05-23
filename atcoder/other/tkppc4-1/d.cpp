#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	a.erase(unique(a.begin(),a.end()),a.end());
	n=a.size();
	if(n==1) return puts("0"),0;

	int ans=n;
	for(int i=1;i<n-1;i++){
		if((a[i-1]<=a[i] && a[i]<=a[i+1])
		|| (a[i-1]>=a[i] && a[i]>=a[i+1])) ans--;
	}
	printf("%d\n",ans);

	return 0;
}
