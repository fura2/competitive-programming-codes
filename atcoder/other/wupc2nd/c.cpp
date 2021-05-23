#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	char B[30][31];
	rep(i,h) scanf("%s",B[i]);

	int ans=0;
	rep(_,4){
		rep(i,h) rep(j,w) {
			int sum=0;
			for(int d=1;;d++){
				bool ok=true;
				rep(k,d){
					if(i+d-1>=h || j+k>=w || B[i+d-1][j+k]=='X') ok=false;
					sum+=B[i+d-1][j+k]-'0';
				}
				if(!ok) break;
				ans=max(ans,sum);
			}
		}

		char tmp[30][31];
		memcpy(tmp,B,sizeof B);
		rep(i,h) rep(j,w) B[j][h-1-i]=tmp[i][j];
		swap(h,w);
	}
	printf("%d\n",ans);

	return 0;
}
