#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; cin>>a>>b>>c;
	cout<<(a+b==c||b+c==a||c+a==b?"Yes":"No")<<endl;

	return 0;
}