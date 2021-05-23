#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);
	vector<int> x(m);
	vector<lint> w(m);
	rep(j,m) scanf("%d%lld",&x[j],&w[j]), x[j]--;

	vector<lint> wsum(n);
	rep(j,m) wsum[x[j]]+=w[j];
	rep(i,n) if(wsum[i]>=a[i]) return puts("-1"),0;

	if(accumulate(w.begin(),w.end(),0LL)<*min_element(a.begin(),a.end())) return puts("0"),0;

	const int OFFSET=1e5+7;
	vector<lint> sum(n+2*OFFSET);

	int lo=0,hi=1e5;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		int c=mi;
		fill(sum.begin(),sum.end(),0LL);
		rep(j,m){
			// left
			sum[x[j]-w[j]/c+OFFSET+1]+=c;
			sum[x[j]+OFFSET+1]-=c;
			sum[x[j]-w[j]/c+OFFSET]+=w[j]%c;
			sum[x[j]-w[j]/c+OFFSET+1]-=w[j]%c;
			// right
			sum[x[j]+OFFSET+1]-=c;
			sum[x[j]+w[j]/c+OFFSET+1]+=c;
			sum[x[j]+w[j]/c+OFFSET+1]-=w[j]%c;
			sum[x[j]+w[j]/c+OFFSET+2]+=w[j]%c;
		}
		rep(_,2) rep(i,(int)sum.size()-1) sum[i+1]+=sum[i];

		bool ok=true;
		rep(i,n) if(sum[i+OFFSET]>=a[i]) { ok=false; break; }
		if(ok) hi=mi;
		else   lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
