#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t; cin>>s>>t;
	puts(s=="Sat"||s=="Sun"?t=="Sat"||t=="Sun"?"8/33":"8/32":"8/31");
	return 0;
}
