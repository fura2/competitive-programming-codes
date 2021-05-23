#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int p=1;
	for(char c:s) p=(c=='L'?2*p:2*p+1);
	cout<<p<<'\n';
	return 0;
}
