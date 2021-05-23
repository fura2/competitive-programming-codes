#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	stringstream ss(s);
	int ans=0;
	char op='*';
	while(!ss.eof()){
		int a; ss>>a;
		if(op=='*') ans+=a;
		else        ans*=a;
		ss>>op;
	}
	cout<<ans<<'\n';
	return 0;
}
