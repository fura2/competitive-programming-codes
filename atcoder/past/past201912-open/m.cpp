#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<double> a(n),b(n),c(m),d(m);
	rep(i,n) scanf("%lf%lf",&a[i],&b[i]);
	rep(i,m) scanf("%lf%lf",&c[i],&d[i]);

	double lo=0,hi=1e6;
	rep(_,50){
		double mi=(lo+hi)/2;
		vector<double> x(n+1);
		rep(i,n) x[i]=b[i]-a[i]*mi;
		x[n]=-1e77;
		rep(i,m) x[n]=max(x[n],d[i]-c[i]*mi);
		sort(x.begin(),x.end(),greater<double>());
		if(accumulate(x.begin(),x.begin()+5,0.0)>0) lo=mi; else hi=mi;
	}
	printf("%.9f\n",lo);

	return 0;
}
