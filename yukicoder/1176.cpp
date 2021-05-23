#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a; cin>>a;

	int e2=0,e3=0,e5=0;
	for(lint x=1;x<a;x*=2) e2++;
	for(lint x=1;x<a;x*=3) e3++;
	for(lint x=1;x<a;x*=5) e5++;

	cout<<min({2*e2,3*e3,5*e5})<<'\n';

	return 0;
}
