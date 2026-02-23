#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int q; cin>>q;
	rep(_,q){
		string s,t; cin>>s>>t;
		bool f[128]={};
		for(char c:t) f[c]=true;
		string r;
		for(char c:s) if(f[c]) r+=c;
		cout<<(r.find(t)!=string::npos?"YES":"NO")<<'\n';
	}
	return 0;
}
