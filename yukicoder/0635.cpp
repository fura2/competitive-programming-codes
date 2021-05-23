#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;

void solve(){
	int x[3],v[3];
	rep(i,3) scanf("%d",&x[i]);
	rep(i,3) scanf("%d",&v[i]);

	vector<double> T={0,1e9};
	rep(i,3) rep(j,3) if(i!=j) {
		if(x[i]<x[j] && v[i]>v[j]){
			// x_i+v_i*t = x_j+v_j*t <=> t = (x_j-x_i)/(v_i-v_j)
			T.emplace_back(double(x[j]-x[i])/(v[i]-v[j]));
		}
	}

	sort(T.begin(),T.end());

	rep(i,T.size()-1){
		double t=(T[i]+T[i+1])/2;
		double a[3];
		rep(j,3) a[j]=x[j]+v[j]*t;
		if(abs(a[0]-a[1])>EPS && abs(a[1]-a[2])>EPS && abs(a[0]-a[2])>EPS){
			if((a[0]>a[1] && a[1]<a[2]) || (a[0]<a[1] && a[1]>a[2])){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}

int main(){
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
