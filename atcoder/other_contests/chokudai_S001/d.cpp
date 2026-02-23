#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	sort(a.begin(),a.end());
	rep(i,n) printf("%d%c",a[i],i<n-1?' ':'\n');
	return 0;
}
