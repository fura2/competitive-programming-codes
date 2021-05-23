#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n,p,m; cin>>n>>p>>m;
	vector<string> B(n),S(n);
	rep(i,n) cin>>B[i];
	rep(i,n) cin>>S[i];

	int bx,by;
	vector<pair<int,int>> P;
	rep(i,n) rep(j,n) {
		if(B[i][j]=='o') bx=i, by=j;
		if(B[i][j]=='x') P.emplace_back(i,j);
	}

	rep(i,m) printf("%c\n","UDLR"[rng()%4]);

	return 0;
}
