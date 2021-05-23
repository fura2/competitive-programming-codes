#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d%*d",&n,&m);
	int l=max(n,m);
	vector<int> a(l),b(l);
	rep(i,n) scanf("%d",&a[i+l-n]);
	rep(j,m) scanf("%d",&b[j+l-m]);

	puts(a==b?"Same":a<b?"X":"Y");

	return 0;
}
