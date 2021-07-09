#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	sort(s.begin(),s.end());
	string t="kyoprotenkei90";
	sort(t.begin(),t.end());
	cout<<(s==t?"Yes":"No")<<'\n';
	return 0;
}
