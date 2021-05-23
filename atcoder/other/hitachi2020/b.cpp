#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int na,nb,m; scanf("%d%d%d",&na,&nb,&m);
	vector<int> a(na),b(nb);
	rep(i,na) scanf("%d",&a[i]);
	rep(i,nb) scanf("%d",&b[i]);

	int ans=*min_element(a.begin(),a.end())+*min_element(b.begin(),b.end());
	rep(i,m){
		int x,y,c; scanf("%d%d%d",&x,&y,&c); x--; y--;
		ans=min(ans,a[x]+b[y]-c);
	}
	printf("%d\n",ans);

	return 0;
}
