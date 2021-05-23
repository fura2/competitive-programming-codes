#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n);
	rep(i,n) scanf("%d",&x[i]);

	int mx=x[n-1]-x[0];
	int mn=mx;
	rep(i,n-1) mn=min(mn,x[i+1]-x[i]);
	printf("%d\n%d\n",mn,mx);

	return 0;
}
