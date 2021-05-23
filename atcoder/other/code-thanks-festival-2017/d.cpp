#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int a,int b){ return b?gcd(b,a%b):a; }

int main(){
	int n,m; cin>>n>>m;
	cout<<m-gcd(n,m)<<endl;

	return 0;
}
