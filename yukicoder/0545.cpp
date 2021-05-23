#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n) scanf("%lld%lld",&a[i],&b[i]);

	lint asum=accumulate(a.begin(),a.end(),0LL);

	vector<lint> D1,D2;
	rep(S,1<<n/2){
		lint tmp=0;
		rep(i,n/2) if(S>>i&1) tmp+=a[i]+b[i];
		D1.emplace_back(tmp);
	}
	rep(S,1<<(n+1)/2){
		lint tmp=0;
		rep(i,(n+1)/2) if(S>>i&1) tmp+=a[n/2+i]+b[n/2+i];
		D2.emplace_back(tmp);
	}

	sort(D1.begin(),D1.end());
	sort(D2.begin(),D2.end());
	D1.erase(unique(D1.begin(),D1.end()),D1.end());
	D2.erase(unique(D2.begin(),D2.end()),D2.end());

	lint ans=INF;
	rep(i,D1.size()){
		int pos=lower_bound(D2.begin(),D2.end(),asum-D1[i])-D2.begin();
		for(int j=max(pos-2,0);j<min(pos+2,int(D2.size()));j++){
			ans=min(ans,abs(D1[i]+D2[j]-asum));
		}
	}
	printf("%lld\n",ans);

	return 0;
}
