#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	lint a_total=0,b_total=0;
	rep(i,n) a_total+=a[i];
	rep(j,m) b_total+=b[j];

	vector<lint> sum;
	rep(S,1<<m) if(S!=0 && S!=(1<<m)-1) {
		lint tmp=0;
		rep(j,m) if(S>>j&1) tmp+=b[j];
		if(2*tmp<b_total) sum.emplace_back(tmp);
	}
	sort(sum.begin(),sum.end());

	long ans=0;
	rep(S,1<<n) if(S!=0 && ~S!=(1<<n)-1) {
		lint tmp=0;
		rep(i,n) if(S>>i&1) tmp+=a[i];
		if(2*tmp<a_total){
			ans=max(ans, lower_bound(sum.begin(),sum.end(),tmp)
						-upper_bound(sum.begin(),sum.end(),tmp-a_total+b_total));
		}
	}
	printf("%.9f\n",1.0*ans/sum.size());

	return 0;
}
