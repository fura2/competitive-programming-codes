#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,h,m,t; cin>>n>>h>>m>>t;

	int ans=(60*h+m+(n-1)*t)%1440;
	printf("%d\n%d\n",ans/60,ans%60);

	return 0;
}
