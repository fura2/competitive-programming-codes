#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<double> a(n);
	rep(i,n) scanf("%lf",&a[i]);

	int sgn=1;
	rep(i,n) if(a[i]<0) sgn*=-1, a[i]*=-1;

	vector<int> b(n);
	b[0]=0;
	b[1]=1;
	for(int i=2;i<n;i++){
		if(sgn==1) b[i]=(a[i]>=1?0:1);
		else       b[i]=(a[i]>=1?1:0);
	}

	vector<pair<int,int>> p;
	int pre=0;
	for(int i=1;i<=n;i++){
		if(i==n || b[i]==1){
			p.emplace_back(pre,i);
			pre=i;
		}
	}

	vector<int> ans(n-1,-1);
	int len=n-1;
	for(int i=int(p.size())-2;i>=0;i--){
		ans[p[i].second-1]=len--;
	}
	rep(i,p.size()){
		for(int x=p[i].second-2;x>=p[i].first;x--) ans[x]=len--;
	}
	rep(i,n-1) printf("%d\n",ans[i]);

	return 0;
}
