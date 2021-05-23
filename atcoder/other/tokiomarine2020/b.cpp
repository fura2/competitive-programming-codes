#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,v,b,w,t; cin>>a>>v>>b>>w>>t;
	puts(abs(a-b)<=(v-w)*t?"YES":"NO");
	return 0;
}
