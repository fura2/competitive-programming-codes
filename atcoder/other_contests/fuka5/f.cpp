#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const double PI=acos(-1);

int main(){
	while(1){
		int n,w; scanf("%d%d",&n,&w);
		if(n==0 && w==0) break;

		int res1=0;
		vector<pair<double,int>> Ev;
		rep(i,n){
			lint x,y; scanf("%lld%lld",&x,&y);
			if(x*x+y*y<=w*w){
				res1++;
				continue;
			}

			double h=hypot(x,y);
			Ev.emplace_back(asin(y/h)-asin(w/h),+1);
			Ev.emplace_back(asin(y/h)+asin(w/h),-1);
		}

		sort(Ev.begin(),Ev.end());

		int res2=0,cnt=0;
		for(auto [theta,io]:Ev){
			cnt+=io;
			res2=max(res2,cnt);
		}

		printf("%d\n",res1+res2);
	}

	return 0;
}
