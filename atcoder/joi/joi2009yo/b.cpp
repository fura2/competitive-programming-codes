#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[10],b[10];
	rep(i,10) cin>>a[i];
	rep(i,10) cin>>b[i];

	sort(a,a+10);
	sort(b,b+10);

	cout<<a[7]+a[8]+a[9]<<' '<<b[7]+b[8]+b[9]<<'\n';

	return 0;
}
