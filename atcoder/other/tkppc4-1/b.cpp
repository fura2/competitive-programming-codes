#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=-1;
	rep(i,n) if(a[i]<k) {
		if(ans==-1 || a[ans]<a[i]) ans=i;
	}
	printf("%d\n",ans==-1?-1:ans+1);

	return 0;
}
