#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),b(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);

	rep(i,n) b[i]=(b[i]+a[i])%2;
	for(int i=n-1;i>0;i--) b[i]=(b[i-1]+b[i])%2;

	printf("%ld\n",(count(b.begin(),b.end(),1)+1)/2);

	return 0;
}
