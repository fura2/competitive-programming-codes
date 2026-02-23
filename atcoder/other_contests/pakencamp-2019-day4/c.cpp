#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int l[3],r[3];
	rep(i,3) scanf("%d%d",&l[i],&r[i]);

	double c=(r[0]-l[0]+1.0)*(r[1]-l[1]+1.0)*(r[2]-l[2]+1.0);

	double ans=0;
	for(int a=l[0];a<=r[0];a++){
		int x[2],y[2];
		rep(i,2) x[i]=max(l[i+1],a+1), y[i]=max(r[i+1],a);
		ans+=(y[0]-x[0]+1.0)*(y[1]-x[1]+1.0)/c;
	}
	printf("%.9f\n",ans);

	return 0;
}
