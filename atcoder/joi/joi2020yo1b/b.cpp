#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,a,b;
	string s; cin>>n>>a>>b>>s; a--;
	reverse(s.begin()+a,s.begin()+b);
	cout<<s<<'\n';
	return 0;
}
