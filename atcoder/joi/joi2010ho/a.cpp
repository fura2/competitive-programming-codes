#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> d(n-1);
	rep(i,n-1) scanf("%d",&d[i]);

	vector<int> cum(n);
	rep(i,n-1) cum[i+1]=cum[i]+d[i];

	int ans=0,x=0;
	rep(_,m){
		int a; scanf("%d",&a);
		ans=(ans+abs(cum[x+a]-cum[x]))%100000;
		x+=a;
	}
	printf("%d\n",ans);

	return 0;
}
