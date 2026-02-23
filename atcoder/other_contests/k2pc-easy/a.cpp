#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c,n; cin>>a>>b>>c>>n;
	cout<<max(n-a,0)<<' '<<max(2*n-b,0)<<' '<<max(3*n-c,0)<<'\n';
	return 0;
}
