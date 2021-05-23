#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int H,W; cin>>H>>W;
	int h=H,w=W;
	vector<string> B(h),b(h);
	rep(i,H) cin>>B[i];
	rep(i,h) cin>>b[i];

	{
		int x1=h,y1=w,x2=0,y2=0;
		rep(i,h) rep(j,w) if(b[i][j]=='#') {
			x1=min(x1,i);
			y1=min(y1,j);
			x2=max(x2,i+1);
			y2=max(y2,j+1);
		}
		auto tmp=b;
		b.assign(x2-x1,string(y2-y1,'?'));
		rep(x,x2-x1) rep(y,y2-y1) b[x][y]=tmp[x1+x][y1+y];
		h=x2-x1;
		w=y2-y1;
	}

	rep(_,4){
		rep(i,H-h+1) rep(j,W-w+1) {
			bool ok=true;
			rep(x,h) rep(y,w) if(B[i+x][j+y]=='#' && b[x][y]=='#') ok=false;
			if(ok) return puts("Yes"),0;
		}

		auto tmp=b;
		b.assign(w,string(h,'?'));
		rep(i,h) rep(j,w) b[j][h-i-1]=tmp[i][j];
		swap(h,w);
	}
	puts("No");

	return 0;
}
