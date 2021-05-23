#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w; scanf("%d%d",&h,&w);
	rep(i,h) rep(j,w) {
		string s; cin>>s;
		if(s=="snuke") return printf("%c%d\n",'A'+j,i+1),0;
	}

	return 0;
}
