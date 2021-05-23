#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w,B[2000][2000],mx,mn;

int solve(){
	int lo=-1,hi=mx-mn;
	vector tmp(h,vector(w,0));
	while(hi-lo>1){
		int mi=(lo+hi)/2;

		rep(i,h) rep(j,w) {
			tmp[i][j]=0;
			if(B[i][j]-mn<=mi) tmp[i][j]|=1;
			if(mx-B[i][j]<=mi) tmp[i][j]|=2;
		}

		vector<int> L(h);
		rep(i,h){
			int d;
			for(d=0;d<w;d++) if((tmp[i][d]&1)==0) break;
			L[i]=d;
		}
		for(int i=h-2;i>=0;i--) L[i]=min(L[i],L[i+1]);

		vector<int> R(h);
		rep(i,h){
			int d;
			for(d=0;d<w;d++) if((tmp[i][w-1-d]>>1&1)==0) break;
			R[i]=d;
		}
		for(int i=1;i<h;i++) R[i]=min(R[i],R[i-1]);

		bool ok=true;
		rep(i,h) if(L[i]+R[i]<w) ok=false;
		if(ok) hi=mi;
		else   lo=mi;
	}

	return hi;
}

int main(){
	scanf("%d%d",&h,&w);
	rep(i,h) rep(j,w) scanf("%d",&B[i][j]);

	mx=0; mn=1e9;
	rep(i,h) rep(j,w) {
		mx=max(mx,B[i][j]);
		mn=min(mn,B[i][j]);
	}

	int ans=mx-mn;
	rep(t,4){
		ans=min(ans,solve());

		rep(i,h/2) rep(j,w) swap(B[i][j],B[h-1-i][j]);
		if(t%2==0){
			rep(i,h) rep(j,w/2) swap(B[i][j],B[i][w-1-j]);
		}
	}
	printf("%d\n",ans);

	return 0;
}
