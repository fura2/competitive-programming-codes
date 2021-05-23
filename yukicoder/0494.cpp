#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<"yukicoder"[find(s.begin(),s.end(),'?')-s.begin()]<<'\n';
	return 0;
}
