#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	map<string,int> f;
	rep(i,n){
		string s; cin>>s;
		++f[s];
	}

	for(auto p:f) if(p.second>(n+1)/2) return puts("NO"),0;
	puts("YES");

	return 0;
}
