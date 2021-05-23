#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	printf("%f\n",n%2==1?1.0*a[n/2]:(a[n/2-1]+a[n/2])/2.0);

	return 0;
}
