#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;
	if(b>=60*a) return puts("-1"),0;
	cout<<(60*60*c+60*a-b-1)/(60*a-b)<<'\n';
	return 0;
}
