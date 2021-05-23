#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	cout<<(s==t?"YES":"NO")<<'\n';
	return 0;
}
