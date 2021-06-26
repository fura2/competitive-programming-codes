#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> x(n),y(n);
	rep(i,n){
		int u,v; scanf("%d%d",&u,&v);
		x[i]=u+v;
		y[i]=u-v;
	}

	lint x_min=*min_element(x.begin(),x.end());
	lint x_max=*max_element(x.begin(),x.end());
	lint y_min=*min_element(y.begin(),y.end());
	lint y_max=*max_element(y.begin(),y.end());

	rep(_,q){
		int q; scanf("%d",&q); q--;
		printf("%lld\n",max({x[q]-x_min,x_max-x[q],y[q]-y_min,y_max-y[q]}));
	}

	return 0;
}
