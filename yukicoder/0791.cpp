#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();
	printf("%d\n",n>1&&s[0]=='1'&&count(s.begin(),s.end(),'3')==n-1?n-1:-1);
	return 0;
}
