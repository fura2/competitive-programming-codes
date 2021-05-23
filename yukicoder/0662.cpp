#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	map<string,int> id;
	int c[5];
	rep(i,5){
		string s; cin>>s>>c[i];
		id[s]=i;
	}

	vector<int> a[3];
	rep(i,3){
		int n; scanf("%d",&n);
		a[i].resize(n);
		rep(j,n){
			string s; cin>>s;
			a[i][j]=id[s];
		}
	}

	int cnt[3][5]={};
	rep(i,3) rep(j,a[i].size()) cnt[i][a[i][j]]++;

	double ans1=0;
	lint ans2[5];
	rep(i,5){
		ans2[i]=5;
		rep(j,3) ans2[i]*=cnt[j][i];
		ans1+=c[i]*ans2[i];
	}
	rep(i,3) ans1/=a[i].size();

	printf("%.9f\n",ans1);
	rep(i,5) printf("%lld\n",ans2[i]);

	return 0;
}
