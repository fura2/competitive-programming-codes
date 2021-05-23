// Day 2: Cheating

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(const vector<int>& x,int w){
	int n=x.size();
	int res=1,pre=x[0];
	for(int i=1;i<n;i++) if(pre+w<x[i]) {
		pre=x[i];
		res++;
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> x(m),y(m);
	rep(i,m) scanf("%d%d",&x[i],&y[i]);

	sort(x.begin(),x.end());
	sort(y.begin(),y.end());

	int lo=-1,hi=1e9;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		if(solve(x,mi)+solve(y,mi)<=n) hi=mi;
		else lo=mi;
	}
	printf("%d\n",hi);

	return 0;
}
