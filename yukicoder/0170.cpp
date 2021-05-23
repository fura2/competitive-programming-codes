#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;

	int fact[9]={1};
	rep(i,8) fact[i+1]=(i+1)*fact[i];

	int ans=fact[s.length()];
	rep(c,128) ans/=fact[hist[c]];
	printf("%d\n",ans-1);

	return 0;
}
