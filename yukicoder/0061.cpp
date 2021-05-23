#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; cin>>q;
	rep(_,q){
		int w,h,d,sx,sy,gx,gy,vx,vy;
		cin>>w>>h>>d>>gx>>gy>>sx>>sy>>vx>>vy;

		int g=gcd(vx,vy);
		d*=g;
		int dx=vx/g;
		int dy=vy/g;

		bool vis[30][30]={};
		int x=sx,y=sy;
		rep(t,min(d+1,1200)){
			vis[y][x]=true;
			y=(y+dy)%(2*h); if(y<0) y+=2*h;
			x=(x+dx)%(2*w); if(x<0) x+=2*w;
		}
		puts(vis[gy][gx]
		   ||vis[gy][(2*w-gx)%(2*w)]
		   ||vis[(2*h-gy)%(2*h)][gx]
		   ||vis[(2*h-gy)%(2*h)][(2*w-gx)%(2*w)]?"Hit":"Miss");
	}

	return 0;
}
