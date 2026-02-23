#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,m,n; scanf("%d%d%d%d",&h,&w,&m,&n);
	vector<int> t(n),b(n),l(n),r(n);
	rep(i,n) scanf("%d%d%d%d",&t[i],&b[i],&l[i],&r[i]), t[i]--, l[i]--;

	int a[50][50]={};
	rep(i,n) for(int y=t[i];y<b[i];y++) for(int x=l[i];x<r[i];x++) a[y][x]++;

	rep(i,n){
		int cnt=0;
		rep(y,h) rep(x,w) {
			if(t[i]<=y && y<b[i] && l[i]<=x && x<r[i]){
				if(a[y][x]%4==1) cnt++;
			}
			else{
				if(a[y][x]%4==0) cnt++;
			}
		}
		if(cnt==m) printf("%d\n",i+1);
	}

	return 0;
}
