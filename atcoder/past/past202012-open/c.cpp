#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; cin>>n;

	string ans;
	do{
		int d=n%36;
		if(d<10) ans+='0'+d;
		else     ans+='A'+d-10;
		n/=36;
	}while(n>0);
	reverse(ans.begin(),ans.end());
	cout<<ans<<'\n';

	return 0;
}
