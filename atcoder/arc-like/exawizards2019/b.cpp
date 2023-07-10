#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	cout<<(count(s.begin(),s.end(),'R')>count(s.begin(),s.end(),'B')?"Yes":"No")<<'\n';
	return 0;
}
