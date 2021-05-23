#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x,n,m; scanf("%d%d%d",&x,&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d",&b[i]);

	bool ok1=find(a.begin(),a.end(),x)!=a.end();
	bool ok2=find(b.begin(),b.end(),x)!=b.end();
	if(ok1 && ok2) puts("MrMaxValu");
	else if(ok1) puts("MrMax");
	else if(ok2) puts("MaxValu");
	else puts("-1");

	return 0;
}
