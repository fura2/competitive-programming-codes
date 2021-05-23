#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	const int OFFSET=1100;
	static int a1[2200][2200];
	static int a2[2200][2200];
	static int a3[2200][2200];
	rep(_,n){
		int type,x,y,sz; scanf("%d%d%d%d",&type,&x,&y,&sz);
		x+=OFFSET;
		y+=OFFSET;
		if(type==1){
			a1[y+sz-1][x-sz+1]++;
			a1[y-sz][x+sz]--;
			for(int i=1;i<sz;i++){
				a1[y+sz-1-i][x-sz+1]++;
				a1[y+sz-1][x-sz+1+i]++;
				a1[y-sz+i][x+sz]--;
				a1[y-sz][x+sz-i]--;
			}
		}
		else if(type==2){
			rep(i,sz){
				a2[y+i][x-sz+1]++;
				a2[y+i][x+1]--;
				a2[y-i-1][x+1]--;
				a2[y-i-1][x+sz+1]++;
			}
		}
		else{
			rep(i,sz){
				a2[y+i][x-sz+1]++;
				a2[y+i][x+1]-=2*(sz-i)-1;
				a2[y-i-1][x+1]-=2*(sz-i)-1;
				a2[y-i-1][x+sz+1]++;
			}
			rep(i,sz-1){
				a3[y+i][x-sz+2]+=2;
				a3[y+i][x+1-i]-=2;
				a3[y-i-1][x+2+i]+=2;
				a3[y-i-1][x+sz+1]-=2;
			}
		}
	}

	rep(y,2200) rep(x,2200-1) {
		a3[y][x+1]+=a3[y][x];
	}
	rep(y,2200) rep(x,2200) a2[y][x]+=a3[y][x];

	rep(y,2200) rep(x,2200-1) {
		a2[y][x+1]+=a2[y][x];
	}
	rep(y,2200) rep(x,2200) a1[y][x]+=a2[y][x];

	rep(y,2200) rep(d,2200) if(y-d-1>=0) {
		a1[y-d-1][d+1]+=a1[y-d][d];
	}
	rep(x,2200) rep(d,2200) if(x>0 && x+d+1<2200) {
		a1[2200-2-d][x+d+1]+=a1[2200-1-d][x+d];
	}

	int ans=0;
	rep(y,2200) rep(x,2200) ans=max(ans,a1[y][x]);
	printf("%d\n",ans);

	return 0;
}
