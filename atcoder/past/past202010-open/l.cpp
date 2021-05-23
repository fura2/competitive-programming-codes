#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,q; scanf("%d%d",&n,&q);
	vector<lint> a(n);
	rep(i,n) scanf("%lld",&a[i]);

	map<lint,int> E,O;
	rep(i,n-1){
		if(i%2==0) ++E[a[i+1]-a[i]];
		else       ++O[a[i+1]-a[i]];
	}

	lint D=0;
	rep(_,q){
		int type; scanf("%d",&type);
		if(type==1){
			lint v; scanf("%lld",&v);
			D+=v;
		}
		else if(type==2){
			lint v; scanf("%lld",&v);
			D-=v;
		}
		else{
			int i;
			lint v; scanf("%d%lld",&i,&v); i--;
			if(i>0){
				lint diff=a[i]-a[i-1];
				if(i%2==1){
					--E[diff];
					++E[diff+v];
				}
				else{
					--O[diff];
					++O[diff+v];
				}
			}
			if(i<n-1){
				lint diff=a[i+1]-a[i];
				if(i%2==0){
					--E[diff];
					++E[diff-v];
				}
				else{
					--O[diff];
					++O[diff-v];
				}
			}
			a[i]+=v;
		}
		printf("%d\n",E[D]+O[-D]);
	}

	return 0;
}
