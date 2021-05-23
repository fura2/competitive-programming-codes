#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[50][51];
	rep(i,h) scanf("%s",B[i]);

	{
		bool emp=true;
		rep(i,h) rep(j,w) if(B[i][j]=='#') emp=false;
		if(emp) return puts("NO"),0;
	}

	rep(t,4){
		rep(dy,h+1) rep(dx,w+1) if(dy!=0 || dx!=0) {
			bool ok=true;
			rep(i,h) if(ok) rep(j,w) if(ok) {
				if(i-dy>=0 && j-dx>=0) continue;
				int y=i,x=j,cnt=0;
				while(y<h && x<w){
					if(B[y][x]=='#') cnt++;
					else{
						if(cnt%2!=0){
							ok=false;
							break;
						}
						cnt=0;
					}
					y+=dy;
					x+=dx;
				}
				if(cnt%2!=0) ok=false;
			}
			if(ok) return puts("YES"),0;
		}

		if(t%2==0){
			rep(i,h) rep(j,w/2) swap(B[i][j],B[i][w-1-j]);
		}
		else{
			rep(i,h/h) rep(j,w) swap(B[i][j],B[h-1-i][j]);
		}
	}
	puts("NO");

	return 0;
}
