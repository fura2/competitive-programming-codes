#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> r(n),c(n);
	rep(i,n) scanf("%d",&r[i]);
	rep(i,n) scanf("%d",&c[i]);

	int rcnt[3]={},ccnt[3]={};
	rep(i,n){
		rcnt[r[i]]++;
		ccnt[c[i]]++;
	}

	int ans=rcnt[2]*n+ccnt[2]*n-rcnt[2]*ccnt[2];
	if(rcnt[2]==0 && ccnt[2]==0){
		ans+=max(rcnt[1],ccnt[1]);
	}
	else if(rcnt[2]==0){
		ans+=ccnt[1];
	}
	else if(ccnt[2]==0){
		ans+=rcnt[1];
	}
	printf("%d\n",ans);

	return 0;
}
