#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,d; cin>>n>>d;
	if(d<=n){
		cout<<string(d,'A')+string(n-d,'C')<<'\n';
	}
	else{
		cout<<string(2*n-d,'A')+string(d-n,'B')<<'\n';
	}
	return 0;
}
