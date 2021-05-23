#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int f[128];
	f['0']=1;
	f['1']=0;
	f['2']=0;
	f['3']=0;
	f['4']=1;
	f['5']=0;
	f['6']=1;
	f['7']=0;
	f['8']=2;
	f['9']=1;

	string s; cin>>s;
	int m=s.length();

	int hole=1;
	rep(i,m) hole+=f[s[i]];
	cout<<min(2*m+hole,m+2*hole)<<'\n';

	return 0;
}
