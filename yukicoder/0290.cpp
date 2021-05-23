#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	puts(s=="0"||s=="1"||s=="01"||s=="10"||s=="101"||s=="010"?"NO":"YES");
	return 0;
}
