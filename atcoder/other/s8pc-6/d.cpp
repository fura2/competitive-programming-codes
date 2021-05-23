#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double f(double r1,double r2){
	return pow(r1*r1*r1+r2*r2*r2,1.0/3);
}

int main(){
	int n; scanf("%d",&n);
	vector<pair<double,double>> p(n);
	rep(i,n) scanf("%lf%lf",&p[i].first,&p[i].second);

	sort(p.begin(),p.end());

	vector<double> dpl(n),dpr(n);
	dpl[0]=p[0].second;
	for(int i=1;i<n;i++){
		auto [x1,r1]=p[i-1];
		auto [x2,r2]=p[i];
		dpl[i]=f(r2,max(dpl[i-1]-(x2-x1),0.0));
	}
	dpr[n-1]=p[n-1].second;
	for(int i=n-2;i>=0;i--){
		auto [x1,r1]=p[i+1];
		auto [x2,r2]=p[i];
		dpr[i]=f(r2,max(dpr[i+1]-(x1-x2),0.0));
	}

	double ans=0;
	rep(i,n){
		if(i<n-1){
			double d=abs(p[i].first-p[i+1].first);
			ans=max(ans,f(dpl[i],max(dpr[i+1]-d,0.0)));
		}
		if(i>0){
			double d=abs(p[i].first-p[i-1].first);
			ans=max(ans,f(dpr[i],max(dpl[i-1]-d,0.0)));
		}
	}
	printf("%.15f\n",ans);

	return 0;
}
