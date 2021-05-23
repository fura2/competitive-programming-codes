#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int h,w;
	char c; cin>>w>>h>>c;
	rep(i,h) rep(j,w) cout<<(((i+j)%2==0)^(c=='W')?'B':'W')<<(j<w-1?"":"\n");
	return 0;
}
