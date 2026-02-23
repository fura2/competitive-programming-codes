#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> x(m);
	rep(i,m) scanf("%lld",&x[i]), x[i]--;

	lint lo=-1,hi=1e10;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;

		lint pos=0;
		rep(i,m){
			if(pos==n || x[i]-pos>mi){
				break;
			}
			if(pos-x[i]>mi){
				continue;
			}

			lint lo2=pos,hi2=n;
			while(hi2-lo2>1){
				lint mi2=(lo2+hi2)/2;
				lint d1=abs(x[i]-pos)+abs(pos-mi2);
				lint d2=abs(x[i]-mi2)+abs(mi2-pos);
				if(min(d1,d2)<=mi) lo2=mi2;
				else               hi2=mi2;
			}
			pos=hi2;
		}
		if(pos==n) hi=mi;
		else       lo=mi;
	}
	printf("%lld\n",hi);

	return 0;
}
