#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int m,k; cin>>m>>k;

	lint sum=0,pw=1;
	for(int i=1;;i++){
		sum+=k*pw;
		pw*=2*k+1;
		if(sum>=m){ cout<<i<<endl; break; }
	}

	return 0;
}
