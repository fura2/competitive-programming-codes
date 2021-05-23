#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3][3];
	scanf("%d%d%d",&a[0][0],&a[0][1],&a[1][1]);

	rep(sum,1000){
		a[0][2]=sum-a[0][0]-a[0][1];
		a[2][1]=sum-a[0][1]-a[1][1];
		a[2][0]=sum-a[0][2]-a[1][1];
		a[2][2]=sum-a[0][0]-a[1][1];
		a[1][0]=sum-a[0][0]-a[2][0];
		a[1][2]=sum-a[0][2]-a[2][2];

		bool ok=true;
		rep(i,3){
			int tmp=0;
			rep(j,3) tmp+=a[i][j];
			if(tmp!=sum) ok=false;
		}
		rep(j,3){
			int tmp=0;
			rep(i,3) tmp+=a[i][j];
			if(tmp!=sum) ok=false;
		}
		if(ok){
			rep(i,3) rep(j,3) printf("%d%c",a[i][j],j<2?' ':'\n');
			return 0;
		}
	}

	return 0;
}
