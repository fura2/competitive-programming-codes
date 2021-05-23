#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int w,h; scanf("%d%d",&w,&h);
	vector<lint> p(w),q(h);
	rep(i,w) scanf("%lld",&p[i]);
	rep(i,h) scanf("%lld",&q[i]);

	sort(p.begin(),p.end());
	sort(q.begin(),q.end());

	lint ans=0;
	int ip=0,iq=0;
	while(ip<w || iq<h){
		if(ip==w || (iq<h && p[ip]>=q[iq])){
			ans+=(w-ip+1)*q[iq++];
		}
		else{
			ans+=(h-iq+1)*p[ip++];
		}
	}
	printf("%lld\n",ans);

	return 0;
}
