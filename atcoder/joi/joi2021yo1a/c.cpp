#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	for(int x=1;x<=100;x++) if(count(a.begin(),a.end(),x)>0 && count(b.begin(),b.end(),x)>0) printf("%d\n",x);

	return 0;
}
