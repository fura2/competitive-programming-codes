#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> f(int k){ // prime factors of k
	vector<int> res;
	for(int d=2;d*d<=k;d++) if(k%d==0) {
		res.emplace_back(d);
		do k/=d; while(k%d==0);
	}
	if(k>1) res.emplace_back(k);
	return res;
}

int cnt[100001]; // cnt[x] := number of multiples of x

int solve(int k){
	vector<int> P=f(k);
	int n=P.size();

	int res=0;
	rep(S,1<<n){
		int x=1,pc=0;
		rep(i,n) if(S&(1<<i)) x*=P[i], pc++;
		if(pc%2==0) res+=cnt[x];
		else        res-=cnt[x];
	}
	return res;
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,n){
		int a; scanf("%d",&a);
		for(int d=1;d*d<=a;d++) if(a%d==0) {
			cnt[d]++;
			if(d*d<a) cnt[a/d]++;
		}
	}

	for(int k=1;k<=m;k++) printf("%d\n",solve(k));

	return 0;
}
