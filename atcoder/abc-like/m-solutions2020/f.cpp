#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int solve(vector<int> x,vector<int> y,vector<int> dir){
	int n=x.size(),ans=INF;

	// -> <-
	map<int,set<int>> X;
	rep(i,n) if(dir[i]==2) {
		X[y[i]].emplace(x[i]);
	}
	rep(i,n) if(dir[i]==0) {
		auto it=X[y[i]].lower_bound(x[i]);
		if(it!=X[y[i]].end()){
			ans=min(ans,5*(*it-x[i]));
		}
	}

	// →
	//   ↑
	map<int,set<int>> D;
	rep(i,n) if(dir[i]==1) {
		D[x[i]+y[i]].emplace(x[i]);
	}
	rep(i,n) if(dir[i]==0) {
		auto it=D[x[i]+y[i]].lower_bound(x[i]);
		if(it!=D[x[i]+y[i]].end()) ans=min(ans,10*(*it-x[i]));
	}

	return ans;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n),y(n),dir(n);
	rep(i,n){
		char c; scanf("%d%d %c",&x[i],&y[i],&c);
		if(c=='R') dir[i]=0;
		if(c=='U') dir[i]=1;
		if(c=='L') dir[i]=2;
		if(c=='D') dir[i]=3;
	}

	int ans=INF;
	rep(_,4){
		ans=min(ans,solve(x,y,dir));
		rep(i,n){
			tie(x[i],y[i])=make_pair(-y[i],x[i]);
			dir[i]=(dir[i]+1)%4;
		}
	}

	if(ans<INF) printf("%d\n",ans);
	else        puts("SAFE");

	return 0;
}
