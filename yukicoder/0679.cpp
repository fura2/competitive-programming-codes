#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<vector<int>> L(n);
	rep(i,m){
		int a,k; scanf("%d%d",&a,&k); a--;
		L[a].resize(k);
		rep(j,k) scanf("%d",&L[a][j]), L[a][j]--;
	}

	vector<bool> ok(n);
	rep(_,n){
		rep(i,n) if(!ok[i]) {
			bool f=true;
			for(int a:L[i]) if(!ok[a]) { f=false; break; }
			if(f) ok[i]=true;
		}
	}
	printf("%ld\n",count(ok.begin(),ok.end(),true));

	return 0;
}
