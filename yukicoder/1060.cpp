#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> a(n,vector<int>(m));
	rep(i,n) rep(j,m) scanf("%d",&a[i][j]);

	vector<lint> num(m),score(n);
	rep(i,n) rep(j,m) num[j]+=a[i][j];
	rep(i,n) rep(j,m) score[i]+=num[j]*a[i][j];

	vector<int> ord(n);
	iota(ord.begin(),ord.end(),0);
	sort(ord.begin(),ord.end(),[&](int i1,int i2){
		return score[i1]>score[i2];
	});

	lint ans=0;
	rep(i,n){
		if(i%2==0) ans+=score[ord[i]];
		else       ans-=score[ord[i]];
	}
	printf("%lld\n",ans);

	return 0;
}
