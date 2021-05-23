#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	double b; scanf("%lf",&b);
	vector<double> a(n);
	rep(i,n) scanf("%lf",&a[i]);

	double ans1=0,ans2=0;
	rep(i,n){
		if(a[i]!=0) ans1+=a[i]*pow(b,a[i]-1);
		if(a[i]!=-1) ans2+=pow(b,a[i]+1)/(a[i]+1);
		else         ans2+=log(b);
	}
	printf("%.9f\n%.9f\n",ans1,ans2);

	return 0;
}
