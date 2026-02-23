#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int f[128]={};
	f['A']=1;
	f['D']=1;
	f['O']=1;
	f['P']=1;
	f['Q']=1;
	f['R']=1;
	f['B']=2;

	string s; cin>>s;
	puts(f[s[0]]==0&&f[s[1]]==0&&f[s[2]]==1&&f[s[3]]==0?"yes":"no");

	return 0;
}
