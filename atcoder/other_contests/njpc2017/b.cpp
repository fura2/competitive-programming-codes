#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	lint h,w;
	int n; scanf("%lld%lld%d",&h,&w,&n);
	set<pair<int,int>> P;
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y); x--; y--;
		P.emplace(x,y);
	}

	lint ans=h*(w-1)+(h-1)*w;
	for(auto [x,y]:P){
		rep(k,4){
			lint x2=x+dx[k],y2=y+dy[k];
			if(0<=x2 && x2<h && 0<=y2 && y2<w){
				if(P.count({x2,y2})>0){
					if(k==0 || k==1) ans--;
				}
				else ans--;
			}
		}
	}
	printf("%lld\n",ans);

	return 0;
}
