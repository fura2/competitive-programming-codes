#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<double> l(n);
	rep(i,n) scanf("%lf",&l[i]);
	lint k; scanf("%lld",&k);

	double lo=0,hi=*max_element(l.begin(),l.end());
	rep(_,70){
		double mi=(lo+hi)/2;
		lint cnt=0;
		rep(i,n) cnt+=l[i]/mi;
		if(cnt>=k) lo=mi;
		else       hi=mi;
	}
	printf("%.15f\n",hi);

	return 0;
}
