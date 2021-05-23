#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<lint> x(n),y(n);
	rep(i,n) scanf("%lld%lld",&x[i],&y[i]);

	vector<tuple<lint,int,int>> D;
	rep(i,n) for(int j=i+1;j<n;j++) {
		D.emplace_back((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),i,j);
	}
	sort(D.begin(),D.end());

	int ans=0;
	vector<bool> del(n);
	for(auto [d,i,j]:D){
		if(i==0){
			if(!del[j]){
				del[j]=true;
				ans++;
			}
		}
		else{
			if(!del[i] && !del[j]){
				del[i]=del[j]=true;
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
