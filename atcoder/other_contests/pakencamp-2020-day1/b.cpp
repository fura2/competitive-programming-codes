#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	cout<<*max_element(s.begin(),s.end())<<'\n';
	return 0;
}
