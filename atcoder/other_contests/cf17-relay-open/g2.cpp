#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L;
	string s,t; cin>>L>>s>>t;

	if(s+t>t+s) swap(s,t);

	int n1=s.length(),n2=t.length();

	int a,b;
	for(int i=L/n1;i>=0;i--) if((L-i*n1)%n2==0) {
		a=i;
		b=(L-i*n1)/n2;
		break;
	}
	rep(i,a) cout<<s;
	rep(i,b) cout<<t;
	cout<<'\n';

	return 0;
}
