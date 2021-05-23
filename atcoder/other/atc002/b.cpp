#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint modpow(lint a,lint k,int m){
	lint r=1;
	for(lint x=a%m;k>0;k>>=1,x=x*x%m) if(k&1) r=r*x%m;
	return r;
}

int main(){
	lint n,m,p; cin>>n>>m>>p;
	cout<<modpow(n,p,m)<<'\n';
	return 0;
}
