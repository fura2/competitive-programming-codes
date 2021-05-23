#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	vector<int> hist_b(1e5+1);
	rep(i,n) hist_b[b[i]]++;

	int ans=n;
	vector<int> hist_a(1e5+1);
	rep(i,n){
		hist_a[a[i]]++;
		ans=min(ans,hist_b[a[i]]/hist_a[a[i]]);
		printf("%d\n",ans);
	}

	return 0;
}
