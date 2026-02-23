#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint solve(int w,int k,vector<int> x){
	int n=x.size();
	vector<lint> B(w,k),cum(w+1);
	rep(i,n) B[x[i]]--;
	rep(i,w) cum[i+1]=cum[i]+B[i];

	int p;
	for(p=0;p<w;p++) if(2*cum[p+1]>=cum[w]) break;
	assert(p<w);

	lint res=0;
	rep(i,w) res+=B[i]*abs(i-p);
	return res;
}

int main(){
	int h,w,n; scanf("%d%d%d",&h,&w,&n);
	vector<int> x(n),y(n);
	rep(i,n) scanf("%d%d",&x[i],&y[i]), x[i]--, y[i]--;

	printf("%lld\n",solve(h,w,x)+solve(w,h,y));

	return 0;
}
