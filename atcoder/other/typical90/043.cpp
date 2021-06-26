#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;
const int dx[]={0,-1,0,1},dy[]={1,0,-1,0};

int main(){
	int h,w; cin>>h>>w;
	int sx,sy,gx,gy; cin>>sx>>sy>>gx>>gy; sx--; sy--; gx--; gy--;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	vector d(h,vector(w,vector(4,INF)));
	deque<tuple<int,int,int>> D;
	rep(k,4){
		d[sx][sy][k]=0;
		D.emplace_back(sx,sy,k);
	}
	while(!D.empty()){
		int x,y,k; tie(x,y,k)=D.front();
		D.pop_front();

		if(x==gx && y==gy){
			printf("%d\n",d[x][y][k]);
			break;
		}

		rep(k2,4){
			int x2=x+dx[k2],y2=y+dy[k2];
			if(0<=x2 && x2<h && 0<=y2 && y2<w && B[x2][y2]=='.'){
				int d2=d[x][y][k]+(k==k2?0:1);
				if(d[x2][y2][k2]>d2){
					d[x2][y2][k2]=d2;
					if(k==k2) D.emplace_front(x2,y2,k2);
					else      D.emplace_back(x2,y2,k2);
				}
			}
		}
	}

	return 0;
}
