#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int f[128];
	f['J']=0;
	f['O']=1;
	f['I']=2;
	sort(s.begin(),s.end(),[&](char a,char b){
		return f[a]<f[b];
	});

	cout<<s<<'\n';

	return 0;
}
