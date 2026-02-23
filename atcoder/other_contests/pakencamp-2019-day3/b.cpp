#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	map<string,int> f;
	rep(i,n){
		string s; cin>>s;
		++f[s];
	}
	cout<<(f["black"]>f["white"]?"black":"white")<<'\n';

	return 0;
}
