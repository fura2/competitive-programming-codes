#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n; cin>>n;
	rep(i,n){
		string s="a";
		rep(j,18) s+='a'+rng()%26;
		s+=(i<n-1?"a":"n");
		cout<<s<<'\n';
	}
	return 0;
}
