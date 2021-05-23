#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool check(lint a){
	if(abs(a)<100 || a%100!=0) return false;
	a/=100;
	while(abs(a)>9){
		if(a%10!=0) return false;
		a/=10;
	}
	return true;
}

int main(){
	lint a,b; cin>>a>>b;
	if(check(a) && check(b)){
		cout<<a*b/10<<'\n';
	}
	else{
		if(abs(a*b)<=99999999) cout<<a*b<<'\n';
		else cout<<"E\n";
	}
	return 0;
}
