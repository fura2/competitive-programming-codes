#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);

	bool ok=false;
	rep(i,h){
		string s; cin>>s;
		rep(j,w-3) if(s.substr(j,4)=="LOVE") ok=true;
	}
	puts(ok?"YES":"NO");

	return 0;
}
