#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int cnt[128]={};
	for(char c:s) cnt[c]++;

	printf("%d\n",min({cnt['t'],cnt['r'],cnt['e']/2}));

	return 0;
}
