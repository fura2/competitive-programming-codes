#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int N=512;
int B[N][N];

void solve(int d){
	auto go=[&](int i0,int j0,int color){
		for(int i=i0;i<2*N;i+=d){
			for(int j=j0-((i-i0)/d%2==0?0:d);j<N;j+=2*d){
				int y0=i,x0=j+d/2-1;
				for(int dy=-d/2+1;dy<=d/2-1;dy++){
					for(int dx=-d/2+1;dx<=d/2-1;dx++){
						int y=y0+dy,x=x0+dx;
						if(0<=y && y<N && 0<=x && x<N && (i+j)%2==(y+x)%2 && abs(y-y0)+abs(x-x0)<d/2){
							B[y][x]=color;
						}
					}
				}
			}
		}
	};

	go( 0 ,  0 ,0);
	go( 0 ,  d ,1);
	go(d/2,-d/2,2);
	go(d/2, d/2,3);

	rep(i,N) for(int j=1;j<N;j++) if((i+j)%2==1) B[i][j]=B[i][j-1];
}

int main(){
	int h,w,d; scanf("%d%d%d",&h,&w,&d);

	if(d%2==1){
		rep(i,N) rep(j,N) B[i][j]=(i+j)%2;
	}
	else{
		solve(d);
	}

	rep(i,h){
		rep(j,w) putchar("RGBY"[B[i][j+1]]);
		puts("");
	}

	return 0;
}
