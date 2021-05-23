#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

void solve(){
	int h,w; scanf("%d%d",&h,&w);
	if(h>w) swap(h,w);

	bool ok;
	if(h==2 && w==4){
		ok=false;
	}
	else if(h%2==0 && w%2==0){
		if     (h%4==0) ok=true;
		else if(w%4==0) ok=true;
		else            ok=false;
	}
	else{
		if     (h%8==0 && w>=3) ok=true;
		else if(w%8==0 && h>=3) ok=true;
		else                    ok=false;
	}
	puts(ok?"Possible":"Impossible");
}

int main(){
	int t; scanf("%d",&t); rep(_,t) solve();
	return 0;
}
