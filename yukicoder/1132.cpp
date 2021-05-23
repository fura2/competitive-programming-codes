#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

lint a,b,c,d;
lint f(lint x){ return a*x*x*x+b*x*x+c*x+d; }

int main(){
	lint p,q; cin>>a>>b>>c>>d>>p>>q;
	lint x_mn=p,x_mx=p;
	for(lint x=p;x<=q;x++){
		if(f(x)<f(x_mn)) x_mn=x;
		if(f(x)>f(x_mx)) x_mx=x;
	}
	cout<<f(x_mx)<<' '<<x_mx<<' '<<f(x_mn)<<' '<<x_mn<<'\n';
	return 0;
}
