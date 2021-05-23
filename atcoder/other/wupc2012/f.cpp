#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d%d",&p[i].first,&p[i].second);

	sort(p.begin(),p.end());

	bool B[1000][1000]={};
	int cum[1001][1001]={};
	for(auto [x,y]:p){
		B[y][x]=true;
		cum[y+1][x+1]=1;
	}
	rep(y,1000) rep(x,1000) cum[y+1][x+1]+=cum[y+1][x]+cum[y][x+1]-cum[y][x];

	int ans=0;
	rep(i,n) for(int j=i+1;j<n;j++) {
		int x1=p[i].first,y1=p[i].second;
		int x2=p[j].first,y2=p[j].second;
		if(B[y2][x1] && B[y1][x2]){
			if(y2<y1) swap(y1,y2);
			if(cum[y2][x2]-cum[y2][x1+1]-cum[y1+1][x2]+cum[y1+1][x1+1]==0){
				ans=max(ans,(x2-x1)*(y2-y1));
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
