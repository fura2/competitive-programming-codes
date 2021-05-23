#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint l,r,m,k; cin>>l>>r>>m>>k;
	puts(k==0||l==0||k*r/m>(k*l-1)/m?"Yes":"No");
	return 0;
}
