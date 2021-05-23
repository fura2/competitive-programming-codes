#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<s.length()-count(s.begin(),s.end(),'0')-1<<'\n';
	return 0;
}
