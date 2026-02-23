#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int solve(int x0,int y0){
	auto f=[&](int k){
		if((x0+y0)%2==0){
			if(k%2==0) return 4*(k/2);
			else       return 4*(k/2)+3;
		}
		else{
			if(k%2==0) return 4*(k/2)+1;
			else       return 4*(k/2)+2;
		}
	};

	int lo=-1,hi=1e5;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int x=x0,y=y0;
		for(int i=f(mi);i>0;i--){
			if(x>=y) x=abs(x-i);
			else     y=abs(y-i);
		}
		if(x==0 && y==0) hi=mi;
		else             lo=mi;
	}
	return f(hi);
}

int main(){
// experiment
/*
	vector<int> d[100][100];
	d[50][50].emplace_back(0);
	rep(a,9){
		rep(i,100) rep(j,100) if(count(d[i][j].begin(),d[i][j].end(),a)>0) {
			rep(k,4){
				int y=i+(a+1)*dy[k],x=j+(a+1)*dx[k];
				if(0<=y && y<100 && 0<=x && x<100) d[y][x].emplace_back(a+1);
			}
		}
	}
	rep(i,100) rep(j,100) {
		sort(d[i][j].begin(),d[i][j].end());
		d[i][j].erase(unique(d[i][j].begin(),d[i][j].end()),d[i][j].end());
	}

	for(int i=45;i<=55;i++){
		for(int j=45;j<=55;j++){
			rep(k,6-d[i][j].size()) printf(" ");
			rep(k,d[i][j].size()) printf("%d",d[i][j][k]);
			printf(" ");
		}
		puts("");
	}
*/
	int n; scanf("%d",&n);
	vector<int> x(n),y(n);
	rep(i,n){
		scanf("%d%d",&x[i],&y[i]);
		x[i]=abs(x[i]);
		y[i]=abs(y[i]);
	}

	rep(i,n) if((x[i]+y[i])%2!=(x[0]+y[0])%2) return puts("-1"),0;

	int ans=0;
	rep(i,n) ans=max(ans,solve(x[i],y[i]));
	printf("%d\n",ans);

	return 0;
}
