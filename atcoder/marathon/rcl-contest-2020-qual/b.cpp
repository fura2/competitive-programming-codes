#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int n,m; scanf("%d%d",&n,&m);
	int tar[50][50];
	rep(i,n) rep(j,n) scanf("%d",&tar[i][j]);

	int B[50][50];
	rep(i,n) rep(j,n) B[i][j]=-1;
	B[ 0 ][ 0 ]=0;
	B[ 0 ][n-1]=1;
	B[n-1][ 0 ]=2;
	B[n-1][n-1]=3;

	vector<tuple<int,int,int>> ini[4];
	rep(t,9){
		ini[0].emplace_back(      0,    5*t,0);
		ini[1].emplace_back(    5*t,    n-1,3);
		ini[2].emplace_back(n-1-5*t,      0,1);
		ini[3].emplace_back(    n-1,n-1-5*t,2);
	}
	for(int t=1;t<=8;t+=2){
		int last[4]={-1,n,-1,n};
		rep(y,n)                if(tar[y][5*t+1]    ==0) last[0]=y;
		for(int x=n-1;x>=0;x--) if(tar[5*t+2][x]    ==1) last[1]=x;
		rep(x,n)                if(tar[n-1-5*t+4][x]==2) last[2]=x;
		for(int y=n-1;y>=0;y--) if(tar[y][n-1-5*t]  ==3) last[3]=y;
		rep(s,8){
			if(    5*s<=last[0]) ini[0].emplace_back(    5*s,    5*t+1,3);
			if(n-1-5*s>=last[1]) ini[1].emplace_back(    5*t+2,n-1-5*s,2);
			if(    5*s<=last[2]) ini[2].emplace_back(n-1-5*t+4,    5*s,0);
			if(n-1-5*s>=last[3]) ini[3].emplace_back(n-1-5*s,n-1-5*t+3,1);
		}
	}
	int ini_max=0;
	rep(c,4) ini_max=max(ini_max,(int)ini[c].size());
	rep(t,ini_max) rep(c,4) {
		if(t>=ini[c].size()){
			puts("-1");
		}
		else{
			int i,j,k; tie(i,j,k)=ini[c][t];
			printf("%d %d %c\n",i,j,"RULD"[k]);
			rep(l,5){
				int y=i+(l+1)*dy[k],x=j+(l+1)*dx[k];
				if(0<=y && y<n && 0<=x && x<n){
					B[y][x]=c;
				}
			}
		}
	}
	m-=4*ini_max;
//fprintf(stderr,"m = %d\n",m);

	rep(t,m){
		int c=t%4;

		int cnt_max=-1,cnt2_max=-1,i_max,j_max,k_max;
		rep(i,n) rep(j,n) if(B[i][j]==c) rep(k,4) {
			int cnt=0,cnt2=0;
			rep(l,5){
				int y=i+(l+1)*dy[k],x=j+(l+1)*dx[k];
				if(0<=y && y<n && 0<=x && x<n){
					if(B[y][x]!=c && tar[y][x]==c) cnt++;
					if(B[y][x]==-1) cnt2++;
				}
			}
			if(make_pair(cnt,cnt2)>make_pair(cnt_max,cnt2_max)){
				cnt_max=cnt;
				cnt2_max=cnt2;
				i_max=i;
				j_max=j;
				k_max=k;
			}
		}

		if(cnt_max==-1){
			puts("-1");
		}
		else{
			int i=i_max,j=j_max,k=k_max;
			printf("%d %d %c\n",i,j,"RULD"[k]);
			rep(l,5){
				int y=i+(l+1)*dy[k],x=j+(l+1)*dx[k];
				if(0<=y && y<n && 0<=x && x<n){
					B[y][x]=c;
				}
			}
		}
	}

	return 0;
}
