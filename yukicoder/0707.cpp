#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double INF=1e77;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	auto calc=[&](int i,int j){
		double res=0;
		rep(y,h) rep(x,w) if(B[y][x]=='1') res+=hypot(x+1-j,y+1-i);
		return res;
	};

	double ans=INF;
	rep(i,h+2){
		if(i!= 0 ) ans=min(ans,calc(i, 0 ));
		if(i!=h+1) ans=min(ans,calc(i,w+1));
	}
	rep(j,w+2){
		if(j!= 0 ) ans=min(ans,calc( 0 ,j));
		if(j!=w+1) ans=min(ans,calc(h+1,j));
	}
	printf("%.9f\n",ans);

	return 0;
}
