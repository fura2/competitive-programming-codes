#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	vector<lint> cum(n+1),cum_e(n+1),cum_o(n+1);
	rep(i,n){
		cum[i+1]=cum[i]+a[i];
		cum_e[i+1]=cum_e[i]+(i%2==0?a[i]:0);
		cum_o[i+1]=cum_o[i]+(i%2==1?a[i]:0);
	}

	vector<lint> b(q);
	rep(i,q) scanf("%lld",&b[i]);
	vector<int> p(q);
	iota(p.begin(),p.end(),0);
	sort(p.begin(),p.end(),[&](int i,int j){
		return b[i]>b[j];
	});

	vector<lint> ans(q);
	int bdry=n-1;
	rep(i,q){
		lint tar=min(b[p[i]],a[n-1]);
		while(1){
			int p0; // 後手が a[bdry] を取るまでにかかる手数
			int p1; // 後手が a[bdry-1] を取るまでにかかる手数

			int idx=lower_bound(a.begin(),a.end(),tar-(a[bdry]-tar))-a.begin();
			p0=bdry-idx+1;
			idx=lower_bound(a.begin(),a.end(),tar-(a[bdry-1]-tar))-a.begin();
			p1=(bdry-1)-idx+1;

			if(p1<n-bdry+1 && n-bdry+1<=p0+1){
				break;
			}
			bdry--;
		}

		int k=n-2*(n-bdry);
		if(k%2==1) ans[p[i]]=(cum[n]-cum[bdry])+(k>=0?cum_e[k]:0);
		else       ans[p[i]]=(cum[n]-cum[bdry])+(k>=0?cum_o[k]:0);
	}

	rep(i,q) printf("%lld\n",ans[i]);

	return 0;
}
