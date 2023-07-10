// written during the contest

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,k; scanf("%d%d%d",&h,&w,&k);
	char B[300][301];
	rep(i,h) scanf("%s",B[i]);

	int ans[300][300],pre=0;
	rep(i,h){
		vector<int> X;
		rep(j,w) if(B[i][j]=='#') X.emplace_back(j);
		X.emplace_back(w);
		if(X.size()==1) continue;

		for(int j=0;j<X.size()-1;j++){
			for(int y=pre;y<=i;y++) for(int x=(j==0?0:X[j]);x<min(X[j+1],w);x++) {
				ans[y][x]=k;
			}
			k--;
		}
		pre=i+1;
	}
	while(pre<h){
		rep(x,w) ans[pre][x]=ans[pre-1][x];
		pre++;
	}

	rep(i,h) rep(j,w) printf("%d%c",ans[i][j],j<w-1?' ':'\n');

	return 0;
}
