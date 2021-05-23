#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int freq[128]={};
	for(char c:s) freq[c]++;

	int mx=0,mn=1e9;
	rep(c,128) if(freq[c]>0) {
		mx=max(mx,freq[c]);
		mn=min(mn,freq[c]);
	}
	puts(mx==mn?"Yes":"No");

	return 0;
}
