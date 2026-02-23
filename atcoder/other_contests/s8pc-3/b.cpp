#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w,k;

int calc(vector<string> B){
	int res=0;
	for(int t=0;;t++){
		bool end;
		do{
			end=true;
			for(int i=h-1;i>0;i--) rep(j,w) if(B[i][j]=='0' && B[i-1][j]!='0') {
				B[i][j]=B[i-1][j];
				B[i-1][j]='0';
				end=false;
			}
		}while(!end);

		bool found=false;
		rep(i,h) rep(j,w-k+1) if(B[i][j]!='0') {
			int len;
			for(len=1;j+len<w;len++) if(B[i][j+len]!=B[i][j]) break;
			if(len>=k){
				res+=(1<<t)*(B[i][j]-'0')*len;
				rep(d,len) B[i][j+d]='0';
				j+=len-1;
				found=true;
			}
		}
		if(!found) break;
	}
	return res;
}

int main(){
	cin>>h>>w>>k;
	vector<string> B(h);
	rep(i,h) cin>>B[i];

	int ans=0;
	rep(i,h) rep(j,w) {
		char c=B[i][j];
		B[i][j]='0';
		ans=max(ans,calc(B));
		B[i][j]=c;
	}
	cout<<ans<<'\n';

	return 0;
}
