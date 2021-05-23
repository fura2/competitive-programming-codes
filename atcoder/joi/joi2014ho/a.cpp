#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; cin>>h>>w;
	vector<string> B(h);
	rep(i,h) cin>>B[i];
	string C[2];
	rep(i,2) cin>>C[i];

	auto check=[&](int i,int j){
		return 0<=i && i+1<h && 0<=j && j+1<w
			&& B[i][j]==C[0][0] && B[i][j+1]==C[0][1] && B[i+1][j]==C[1][0] && B[i+1][j+1]==C[1][1];
	};

	int total=0;
	vector ok(h,vector(w,false));
	rep(i,h-1) rep(j,w-1) if(check(i,j)) {
		ok[i][j]=true;
		total++;
	}

	int ans=total;
	rep(i,h) rep(j,w) for(char c:"JOI") {
		char tmp=B[i][j];

		int cnt=0;
		if(check(i-1,j-1)) cnt--;
		if(check(i-1,j  )) cnt--;
		if(check(i  ,j-1)) cnt--;
		if(check(i  ,j  )) cnt--;
		B[i][j]=c;
		if(check(i-1,j-1)) cnt++;
		if(check(i-1,j  )) cnt++;
		if(check(i  ,j-1)) cnt++;
		if(check(i  ,j  )) cnt++;
		ans=max(ans,total+cnt);

		B[i][j]=tmp;
	}
	printf("%d\n",ans);

	return 0;
}
