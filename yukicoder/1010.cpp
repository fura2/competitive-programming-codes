#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint x,y,h; cin>>x>>y>>h;
	x*=1000;
	y*=1000;

	if(x>y) swap(x,y);

	int ans=0;
	while(x>h) y*=2, h*=4, ans++;
	while(y>h) x*=2, h*=4, ans++;
	printf("%d\n",ans);

	return 0;
}
