#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int a[3];
	rep(i,3) scanf("%d",&a[i]);

	sort(a,a+3);

	double ans;
	if(a[0]+a[1]>=a[2]){
		ans=PI*pow(a[0]+a[1]+a[2],2);
	}
	else{
		ans= PI*pow(a[0]+a[1]+a[2],2)
			-PI*pow(a[2]-a[1]-a[0],2);
	}
	printf("%.9f\n",ans);

	return 0;
}
