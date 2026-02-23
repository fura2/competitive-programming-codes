#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	bool Young[4][4]={};
	int sum=0;
	rep(i,3){
		int w; scanf("%d",&w);
		rep(j,w) Young[i][j]=true;
		sum+=w;
	}

	// hook length formula
	int ans=1;
	rep(i,sum) ans*=i+1;
	rep(i,3) rep(j,3) if(Young[i][j]) {
		int h=1;
		for(int y=i+1;Young[y][j];y++) h++;
		for(int x=j+1;Young[i][x];x++) h++;
		ans/=h;
	}
	printf("%d\n",ans);

	return 0;
}
