#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,d,p; cin>>a>>b>>c>>d>>p;
	cout<<min(a*p,b+max(p-c,0)*d)<<'\n';
	return 0;
}
