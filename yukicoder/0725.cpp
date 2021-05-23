#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	rep(i,(int)s.length()-6) if(s.substr(i,7)=="treeone") s=s.substr(0,i)+"forest"+s.substr(i+7), i+=5;
	cout<<s<<'\n';
	return 0;
}
