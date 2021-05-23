#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

void solve(){
	lint O,A,X;
	scanf("%lld%lld%lld",&O,&A,&X);

	bool ng=false,even=false,odd=false;
	rep(i,60){
		bool bo=O>>i&1;
		bool ba=A>>i&1;
		bool bx=X>>i&1;
		if(!bo && !ba &&  bx) ng=true;
		if(!bo &&  ba && !bx) ng=true;
		if(!bo &&  ba &&  bx) ng=true;
		if( bo &&  ba && !bx) even=true;
		if( bo &&  ba &&  bx) odd=true;
	}
	puts(ng||(even&&odd)?"No":"Yes");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
