#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	char c1,c2;
	int a1,a2; cin>>c1>>a1>>c2>>a2;
	if(c1==c2){
		cout<<abs(a1-a2)/15<<'\n';
	}
	else{
		cout<<(a1+a2)/15<<'\n';
	}
	return 0;
}
