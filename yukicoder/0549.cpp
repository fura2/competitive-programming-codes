#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());
	rep(i,n-1) a[n-1]+=a[i]/2;

	printf("%d\n",a[n-1]);

	return 0;
}
