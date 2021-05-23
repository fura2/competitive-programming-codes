#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint h,w; cin>>h>>w;
	cout<<(min(h,w)==1?1:(h*w+1)/2)<<'\n';
	return 0;
}
