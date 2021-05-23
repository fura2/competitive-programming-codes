#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	stringstream ss(s);
	int a; ss>>a;
	char op; ss>>op;
	int b; ss>>b;
	cout<<(op=='+'?a-b:a+b)<<'\n';
	return 0;
}
