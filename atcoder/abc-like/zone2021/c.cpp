#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector a(n,vector(5,0));
	rep(i,n) rep(j,5) scanf("%d",&a[i][j]);

	int lo=0,hi=1e9+1;
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		bool b[1<<5]={};
		rep(i,n){
			int S=0;
			rep(j,5) if(a[i][j]>=mi) S|=1<<j;
			b[S]=true;
		}

		bool ok=false;
		rep(S1,1<<5) if(b[S1]) rep(S2,1<<5) if(b[S2]) rep(S3,1<<5) if(b[S3]) {
			if((S1|S2|S3)==(1<<5)-1){
				ok=true;
			}
		}
		if(ok) lo=mi;
		else   hi=mi;
	}
	printf("%d\n",lo);

	return 0;
}
