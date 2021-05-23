#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k); k--;
	vector<lint> x(n),ra(n);
	rep(i,n) scanf("%lld",&x[i]);
	rep(i,n) scanf("%lld",&ra[i]);

	lint xl=x[k]-ra[k],xr=x[k]+ra[k];
	int l=k,r=k;
	while(1){
		bool end=true;
		if(l>0 && xl<=x[l-1]){
			xl=min(xl,x[l-1]-ra[l-1]);
			xr=max(xr,x[l-1]+ra[l-1]);
			l--;
			end=false;
		}
		if(r<n-1 && x[r+1]<=xr){
			xl=min(xl,x[r+1]-ra[r+1]);
			xr=max(xr,x[r+1]+ra[r+1]);
			r++;
			end=false;
		}
		if(end) break;
	}
	printf("%d\n",r-l+1);

	return 0;
}
