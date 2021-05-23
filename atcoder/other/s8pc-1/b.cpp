#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]);

	vector<pair<int,int>> ans;
	for(int j=1;j<w;j++){
		int cnt=0;
		bool ok=true;
		rep(k,n){
			if     (h*x[k]==j*y[k]) ok=false;
			else if(h*x[k]< j*y[k]) cnt++;
			else                    cnt--;
		}
		if(ok && cnt==0) ans.emplace_back(j,h);
	}
	for(int i=1;i<=h;i++){
		int cnt=0;
		bool ok=true;
		rep(k,n){
			if     (i*x[k]==w*y[k]) ok=false;
			else if(i*x[k]< w*y[k]) cnt++;
			else                    cnt--;
		}
		if(ok && cnt==0) ans.emplace_back(w,i);
	}

	if(ans.empty()){
		puts("-1");
	}
	else{
		for(auto [x,y]:ans) printf("(%d,%d)\n",x,y);
	}

	return 0;
}
