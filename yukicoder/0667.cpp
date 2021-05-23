#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int n=s.length(),m=count(s.begin(),s.end(),'x');
	rep(i,n){
		printf("%.9f\n",100-100.0*m/(n-i));
		if(s[i]=='x') m--;
	}

	return 0;
}
