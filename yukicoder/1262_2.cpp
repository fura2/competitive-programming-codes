#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

vector<int> phi;
void build_phi(int n){
	phi.resize(n+1);
	iota(phi.begin(),phi.end(),0);
	for(int i=2;i<=n;i++) if(phi[i]==i) {
		for(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);
	}
}

int main(){
	build_phi(1e6);

	vector<lint> res(1e6+1);
	for(int i=1;i<=1e6;i++){
		for(int j=i;j<=1e6;j+=i){
			res[j]+=i*phi[j/i];
		}
	}

	int n; scanf("%*d%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint ans=0;
	rep(i,n) ans+=res[a[i]]-a[i];
	printf("%lld\n",ans);

	return 0;
}
