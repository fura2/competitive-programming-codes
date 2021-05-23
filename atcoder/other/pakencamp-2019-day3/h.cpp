#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,-1,-1,-1,0,1,1,1};

int n;
char B[100][101];

vector<pair<int,int>> Me;

bool check(){
	for(auto p:Me){
		int y0,x0; tie(y0,x0)=p;
		rep(k,8){
			int y=y0+dy[k],x=x0+dx[k];
			while(0<=y && y<n && 0<=x && x<n){
				if(B[y][x]=='#' || B[y][x]=='X') break;
				if(B[y][x]=='Q') return false;
				y+=dy[k]; x+=dx[k];
			}
		}
	}
	return true;
}

void solve(int T){
	rep(i,n) rep(j,n) if(B[i][j]=='.') {
		bool ok=false;
		rep(k,8){
			int y1=i+dy[k],x1=j+dx[k];
			int y2=i-dy[k],x2=j-dx[k];
			if(0<=y1 && y1<n && 0<=x1 && x1<n
			&& 0<=y2 && y2<n && 0<=x2 && x2<n
			&& B[y1][x1]=='X' && B[y2][x2]=='Q'){ ok=true; break; }
		}
		if(ok) B[i][j]='#';
	}

	char stop[100][100][8]={};
	rep(i,n) rep(j,n) if(B[i][j]=='.') {
		rep(k,8) if(stop[i][j][k]!='#') {
			int y=i+dy[k],x=j+dx[k];
			while(0<=y && y<n && 0<=x && x<n){
				if(B[y][x]!='.'){ stop[i][j][k]=B[y][x]; break; }
				y+=dy[k]; x+=dx[k];
			}
		}
	}

	vector<pair<int,int>> No;
	rep(i,n) rep(j,n) if(B[i][j]=='.') No.emplace_back(i,j);

	if(T==1){
		sort(No.begin(),No.end(),greater<pair<int,int>>());
	}
	else if(T>1){
		random_device seed_gen;
		shuffle(No.begin(),No.end(),mt19937(seed_gen()));
	}

	while(!check()){
		int cost=-1,y,x;
		for(const auto& p:No){
			int i=p.first,j=p.second;
			if(B[i][j]!='.') continue;
			int cnt=0;
			rep(k,4) if((stop[i][j][k]=='X' && stop[i][j][k+4]=='Q') || (stop[i][j][k]=='Q' && stop[i][j][k+4]=='X')) cnt++;
			if(cnt>cost) tie(cost,y,x)=tie(cnt,i,j);
		}

		B[y][x]='#';

		auto update=[&](int i,int j){
			if(!(0<=i && i<n && 0<=j && j<n)) return;
			rep(k,8) if(stop[i][j][k]!='#') {
				int y=i+dy[k],x=j+dx[k];
				while(0<=y && y<n && 0<=x && x<n){
					if(B[y][x]!='.'){ stop[i][j][k]=B[y][x]; break; }
					y+=dy[k]; x+=dx[k];
				}
			}
		};
		rep(i,n) update(i,x);
		rep(j,n) update(y,j);
		rep(d,n){
			update(y-d,x-d);
			update(y-d,x+d);
			update(y+d,x-d);
			update(y+d,x+d);
		}
	}
}

int main(){
	int m; scanf("%d%d",&n,&m);
	rep(i,n) scanf("%s",B[i]);

	rep(i,n) rep(j,n) if(B[i][j]=='X') Me.emplace_back(i,j);

	int ans=n*n;
	char B_ans[100][101]={};
	rep(t,6){
		rep(i,n) rep(j,n) if(B[i][j]=='#') B[i][j]='.';

		solve(t);

		int cnt=0;
		rep(i,n) rep(j,n) if(B[i][j]=='#') cnt++;
		if(cnt<ans){
			ans=cnt;
			rep(i,n) rep(j,n) B_ans[i][j]=B[i][j];
		}
	}

	rep(i,n) puts(B_ans[i]);

	return 0;
}
