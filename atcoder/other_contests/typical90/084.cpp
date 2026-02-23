#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n;
	string s; cin>>n>>s;

	lint ans=0;
	int o=0,x=0;
	for(int l=0,r=0;l<n;l++){
		while(r<n && (o==0 || x==0)){
			if(s[r]=='o') o++;
			else          x++;
			r++;
		}
		if(o>0 && x>0) ans+=n-r+1;
		if(s[l]=='o') o--;
		else          x--;
	}
	printf("%lld\n",ans);

	return 0;
}
