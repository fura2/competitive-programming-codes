#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[6];
	rep(i,6) cin>>a[i];
	sort(a,a+6);
	printf("%.2f\n",(a[1]+a[2]+a[3]+a[4])/4.0);
	return 0;
}
