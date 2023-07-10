#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint n; cin>>n;
	for(lint a=1;a<=3500;a++) for(lint b=1;b<=3500;b++) {
		lint d=4*a*b-n*a-n*b;
		if(d>0 && n*a*b%d==0){
			cout<<a<<' '<<b<<' '<<n*a*b/d<<'\n';
			return 0;
		}
	}
	return 0;
}
