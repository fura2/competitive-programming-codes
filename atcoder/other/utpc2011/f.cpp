// Internal Error...

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);

	if(k>n/2){
		puts("-1");
		return 0;
	}

	vector<pair<int,int>> E;
	rep(i,n/2){
		E.emplace_back(i,n-i-1);
	}
	rep(i,n/2-1){
		E.emplace_back(E[i].second,E[i+1].first);
	}
	if(n%2==1){
		E.emplace_back(n/2,n/2+1);
	}

	rep(i,k){
		if(i>0) puts("");
		for(auto [u,v]:E) printf("%d %d\n",(u+i)%n+1,(v+i)%n+1);
	}

	return 0;
}
