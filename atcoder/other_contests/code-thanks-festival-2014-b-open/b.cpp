#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	int d=max(a+b,a*b);
	cout<<max(d+c,d*c)<<'\n';
	return 0;
}
