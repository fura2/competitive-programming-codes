#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b; scanf("%d%d",&a,&b);
	a%=12;

	double t=(a*30.0+b/2.0)-b*6.0;
	if(t<0) t+=360;

	int ans=t/((360-30)/3600.0);
	printf("%d\n",ans);

	return 0;
}
