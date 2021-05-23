#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	rep(i,h){
		rep(j,w){
			int cnt=0;
			for(int dx=-1;dx<=1;dx++){
				for(int dy=-1;dy<=1;dy++){
					int x=i+dx,y=j+dy;
					if(0<=x && x<h && 0<=y && y<w && B[x][y]=='#') cnt++;
				}
			}
			printf("%d",cnt);
		}
		puts("");
	}

	return 0;
}
