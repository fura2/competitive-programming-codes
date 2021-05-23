#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int main(){
	int w,h,n; scanf("%d%d%d",&w,&h,&n);
	vector<int> t(n),l(n),b(n),r(n);
	rep(i,n) scanf("%d%d%d%d",&l[i],&t[i],&r[i],&b[i]);

	vector<int> X={-1,w},Y={-1,h};
	rep(i,n){
		rep(j,2){
			X.emplace_back(l[i]-j);
			X.emplace_back(r[i]-j);
			Y.emplace_back(t[i]-j);
			Y.emplace_back(b[i]-j);
		}
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	int H=Y.size(),W=X.size();

	vector cum(H,vector<short>(W));
	rep(i,n){
		t[i]=lower_bound(Y.begin(),Y.end(),t[i])-Y.begin();
		l[i]=lower_bound(X.begin(),X.end(),l[i])-X.begin();
		b[i]=lower_bound(Y.begin(),Y.end(),b[i])-Y.begin();
		r[i]=lower_bound(X.begin(),X.end(),r[i])-X.begin();
		cum[t[i]][l[i]]++;
		cum[b[i]][l[i]]--;
		cum[t[i]][r[i]]--;
		cum[b[i]][r[i]]++;
	}
	rep(i,H-1) rep(j,W) cum[i+1][j]+=cum[i][j];
	rep(j,W-1) rep(i,H) cum[i][j+1]+=cum[i][j];

	vector vis(H,vector<bool>(W));
	rep(i,Y.size()) rep(j,X.size()) if(Y[i]<0 || h<=Y[i] || X[j]<0 || w<=X[j] || cum[i][j]>0) {
		vis[i][j]=true;
	}

	int ans=0;
	queue<pair<int,int>> Q;
	rep(i,H) rep(j,W) if(!vis[i][j]) {
		vis[i][j]=true;
		ans++;

		Q.emplace(i,j);
		while(!Q.empty()){
			auto [y,x]=Q.front(); Q.pop();
			rep(k,4){
				int y2=y+dy[k],x2=x+dx[k];
				if(!vis[y2][x2]){
					vis[y2][x2]=true;
					Q.emplace(y2,x2);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
