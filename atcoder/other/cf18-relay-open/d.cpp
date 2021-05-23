#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> x(n),w(n);
	rep(i,n) scanf("%lf%lf",&x[i],&w[i]);

	auto f=[&](double p){
		double res=0;
		rep(i,n) res=max(res,w[i]*abs(p-x[i]));
		return res;
	};

	double lo=-1e7,hi=1e7;
	rep(_,100){
		double mi1=(2*lo+hi)/3,mi2=(lo+2*hi)/3;
		if(f(mi1)<f(mi2)) hi=mi2;
		else              lo=mi1;
	}
	printf("%.15f\n",lo);

	return 0;
}
